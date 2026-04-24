# Final Exam
A little ncurses program that lends itself to a class github activity
The exam ( exam2.c ) is a C program that uses ncurses.
To compile
```
apt install libncurses-dev
gcc exam2.c -lncurses -o exam
```

Then the students must provide some questions in the questions directory.
Each question should be a file called `student_name.txt`
And the file format is like
```
QUESTION
CHOICE1
CHOICE2
CHOICE3
CHOICE4
ANSWER_INDEX
```

Hastily uploaded this idea. Need to make sure the indices are correct, and add a summary statistic
to the end.
