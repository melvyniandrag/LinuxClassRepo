/**
 * Think about this like this:
 * ls  --stdout-->  pipe  --stdin-->  wc -l
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];   
    // The pipe has a reading end ( where you can read data from )
    // and the pipe also has a writing end (where you can write data to )
    // fd[0] = read end
    // fd[1] = write end

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    if (fork() == 0) {
        // Child 1: "ls"
        // see man dup2 on the command line to see what dup2 does.
	dup2(fd[1], STDOUT_FILENO);  // stdout -> pipe write end
        close(fd[0]);
        close(fd[1]);

        execlp("head", "head", "-n12", "pipe_demo.c", NULL);
        perror("execlp ls");
        exit(1);
    }

    if (fork() == 0) {
        // Child 2: "wc -l"
        dup2(fd[0], STDIN_FILENO);   // stdin <- pipe read end
        close(fd[1]);
        close(fd[0]);

        execlp("wc", "wc", "-l", NULL);
        perror("execlp wc");
        exit(1);
    }

    // Parent
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}

