/**
 * In this cute little program we're writing C code to do the equivalent of
 * this line of bash code:
 * 
 * ls | wc -l
 * 
 * Writing bash his much nicer than writing all this isn't it?
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
	    dup2(fd[1], STDOUT_FILENO);  // we're taking the stdout of the ls command and replacing it with the write end of the pipe we mad above.
        close(fd[0]);
        close(fd[1]);

        execlp("ls", "ls", NULL);
        perror("execlp ls");
        exit(1);
    }

    if (fork() == 0) {
        // Child 2: "wc -l"
        dup2(fd[0], STDIN_FILENO);   // were replacing the stdin of the wc process and replacing it with the read end of the pipe.
        close(fd[1]);
        close(fd[0]);

        execlp("wc", "wc", "-l", NULL);
        perror("execlp wc");
        exit(1);
    }

    // Close the parent's file pipe.
    close(fd[0]);
    close(fd[1]);
    // Wait for the cihld processes to finish
    wait(NULL);
    wait(NULL);

    return 0;
}

