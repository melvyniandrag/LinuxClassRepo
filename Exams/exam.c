#include <ncurses.h>
#include <string.h>

#define NUM_QUESTIONS 5
#define NUM_CHOICES 4

typedef struct {
    char question[256];
    char choices[NUM_CHOICES][128];
    int correct; // 0–3
} Question;

Question quiz[NUM_QUESTIONS] = {
    {
        "What is 2 + 2?",
        {"1", "2", "3", "4"},
        3
    },
    {
        "Capital of France?",
        {"Berlin", "Madrid", "Paris", "Rome"},
        2
    },
    {
        "C keyword for loop?",
        {"repeat", "loop", "for", "iterate"},
        2
    },
    {
        "Unix command to list files?",
        {"ls", "cd", "rm", "pwd"},
        0
    },
    {
        "Value of TRUE in C?",
        {"0", "1", "-1", "Depends"},
        1
    }
};

int main() {
    int score = 0;
    int answers[NUM_QUESTIONS];

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // ---- Menu Screen ----
    mvprintw(2, 2, "Select Test:");
    mvprintw(4, 4, "1. Sample Quiz");
    mvprintw(6, 2, "Press 1 to start...");
    refresh();

    while (getch() != '1');

    // ---- Quiz Loop ----
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        clear();
        mvprintw(2, 2, "Question %d:", i + 1);
        mvprintw(4, 4, "%s", quiz[i].question);

        for (int j = 0; j < NUM_CHOICES; j++) {
            mvprintw(6 + j, 6, "%d. %s", j + 1, quiz[i].choices[j]);
        }

        mvprintw(12, 2, "Press 1-4 to answer");

        int ch;
        while (1) {
            ch = getch();
            if (ch >= '1' && ch <= '4') {
                answers[i] = ch - '1';
                if (answers[i] == quiz[i].correct) {
                    score++;
                }
                break;
            }
        }
    }

    // ---- Results Screen ----
    clear();
    mvprintw(2, 2, "Quiz Complete!");
    mvprintw(4, 2, "Score: %d / %d", score, NUM_QUESTIONS);

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        mvprintw(6 + i, 2,
            "Q%d: Your answer: %d | Correct: %d",
            i + 1,
            answers[i] + 1,
            quiz[i].correct + 1
        );
    }

    mvprintw(15, 2, "Press any key to exit...");
    refresh();
    getch();

    endwin();
    return 0;
}
