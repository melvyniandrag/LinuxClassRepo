#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

#define MAX_QUESTIONS 200
#define NUM_CHOICES 4
#define QUIZ_SIZE 5

typedef struct {
    char question[256];
    char choices[NUM_CHOICES][128];
    char correct;
} Question;

Question questions[MAX_QUESTIONS];
int question_count = 0;
char answers[QUIZ_SIZE];


/***
 * remove newline character.
 */
void trim_newline(char *s) {
    s[strcspn(s, "\n")] = 0;
}

/***
 * Load a file that contains data for a question
 *
 * parameters:
 * path - path to the question file
 */
void load_file(const char *path) {
    FILE *fp = fopen(path, "r");
    if (!fp) return;

    char line[256];

    while (1) {
        Question q;

        // QUESTION
        if (!fgets(line, sizeof(line), fp)) break;
        trim_newline(line);
        strcpy(q.question, line);

        // 4 choices
        for (int i = 0; i < 4; i++) {
            if (!fgets(line, sizeof(line), fp)) return;
            trim_newline(line);
            strcpy(q.choices[i], line);
        }

        // Read the correct answer as a char
	if (!fgets(line, sizeof(line), fp)) return;
        q.correct = line[0];

        questions[question_count++] = q;
    }

    fclose(fp);
}

/***
 * Load all .txt files in questions/ directory
 */
void load_all_questions(const char *dir) {
    DIR *d = opendir(dir);
    if (!d) {
        perror("opendir failed");
        exit(1);
    }

    struct dirent *entry;

    while ((entry = readdir(d))) {
        if (strstr(entry->d_name, ".txt")) {
            char path[512];
            snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);
            load_file(path);
        }
    }

    closedir(d);
}

/***
 */
void shuffle_questions() {
    srand(time(NULL));

    for (int i = question_count - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

/***
 * Run the quiz
 */
void run_quiz() {
    int score = 0;

    for (int i = 0; i < QUIZ_SIZE; i++) {
        clear();
        Question *q = &questions[i];

        mvprintw(2, 2, "Question %d/%d", i + 1, QUIZ_SIZE);
        mvprintw(4, 2, "%s", q->question);

        for (int j = 0; j < NUM_CHOICES; j++) {
            mvprintw(6 + j, 4, "%d. %s", j + 1, q->choices[j]);
        }

        mvprintw(12, 2, "Press 1-4 to answer");

        char ch;
        while (1) {
            ch = getch();
            if (ch >= '1' && ch <= '4') {
                answers[i] = ch;
                if (answers[i] == q->correct)
                    score++;
                break; // only break if the student thas selected a valid index.
            }
        }
    }

    // print resutlts 
    clear();
    mvprintw(2, 2, "Quiz Complete!");
    mvprintw(4, 2, "Score: %d / %d [%0.2f]%%", score, QUIZ_SIZE, (float)score * 100.0f/ (float)QUIZ_SIZE);

    for (int i = 0; i < QUIZ_SIZE; i++) {
        mvprintw(6 + i, 2,
            "Q%d: your=%c correct=%c",
            i + 1,
            answers[i],
            questions[i].correct
        );
    }
    // TODO put in a percentage of results, do: 100 * right / total
    mvprintw(14, 2, "Press any key to exit...");
    refresh();
    getch();
}


int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    /* MENU */
    clear();
    mvprintw(2, 2, "Simple NCurses Quiz");
    mvprintw(4, 2, "Loading questions...");
    refresh();

    load_all_questions("questions");

    if (question_count < QUIZ_SIZE) {
        mvprintw(6, 2, "Not enough questions loaded!");
        getch();
        endwin();
        return 1;
    }

    shuffle_questions();

    mvprintw(6, 2, "Loaded %d questions. Press any key to start.", question_count);
    refresh();
    getch();

    run_quiz();

    endwin();
    return 0;
}
