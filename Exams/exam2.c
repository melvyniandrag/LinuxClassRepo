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
    int correct;
} Question;

Question questions[MAX_QUESTIONS];
int question_count = 0;
int answers[QUIZ_SIZE];

void trim_newline(char *s) {
    s[strcspn(s, "\n")] = 0;
}

/* ---------------- FILE LOADING ---------------- */

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

        // ANSWER (0-3)
        if (!fgets(line, sizeof(line), fp)) return;
        trim_newline(line);
        q.correct = atoi(line);

        questions[question_count++] = q;
    }

    fclose(fp);
}

/* Load all .txt files in questions/ directory */
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

/* ---------------- SHUFFLE ---------------- */

void shuffle_questions() {
    srand(time(NULL));

    for (int i = question_count - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

/* ---------------- QUIZ UI ---------------- */

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

        int ch;
        while (1) {
            ch = getch();
            if (ch >= '1' && ch <= '4') {
                answers[i] = ch - '1';
                if (answers[i] == q->correct)
                    score++;
                break;
            }
        }
    }

    /* ---------------- RESULTS ---------------- */

    clear();
    mvprintw(2, 2, "Quiz Complete!");
    mvprintw(4, 2, "Score: %d / %d", score, QUIZ_SIZE);

    for (int i = 0; i < QUIZ_SIZE; i++) {
        mvprintw(6 + i, 2,
            "Q%d: your=%d correct=%d",
            i + 1,
            answers[i],
            questions[i].correct
        );
    }

    mvprintw(14, 2, "Press any key to exit...");
    refresh();
    getch();
}

/* ---------------- MAIN ---------------- */

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
