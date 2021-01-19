#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STRANGE_ERROR 1
#define SHOULDNT_SEE_THIS 2
#define SLEEP_TIME 5

int main( int argc, char** argv ){
    int i;
    sigset_t intmask;
    int repeatfactor;
    double y = 0.0;

    if(( sigemptyset(&intmask) == -1 ) ||( sigaddset(&intmask, SIGINT) == -1 )){
        perror("Failed to set up the signal mask");
        return STRANGE_ERROR;
    }
    while(1){
        printf("Entering BLOCK state\n");
        if( sigprocmask(SIG_BLOCK, &intmask, NULL) == -1 ){
            break;
        }
        fprintf(stderr, "SIGINT signal blocked\n");
        sleep(SLEEP_TIME);

        printf("Entering UNBLOCK state\n");
        if( sigprocmask(SIG_UNBLOCK, &intmask, NULL) == -1 ){
            break;
        }
        fprintf(stderr, "SIGINT signal unblocked\n");
        sleep(SLEEP_TIME);
    }
    perror("Failed to change signal mask!");
    return SHOULDNT_SEE_THIS;
}
