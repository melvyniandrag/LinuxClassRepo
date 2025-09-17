/*
 *How to ignore sigtstp
 */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    signal( SIGTSTP, SIG_IGN );

    while ( 1 ) {
        puts("Still running...");
    }

   return EXIT_SUCCESS;
}
