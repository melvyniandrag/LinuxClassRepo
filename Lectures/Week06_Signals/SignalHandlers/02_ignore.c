#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

static volatile int keep_running = 1;

static void sig_handler(int i)
{
    (void) i;
    keep_running = 0;
}

int main(void)
{
    signal( SIGINT, sig_handler );
    signal( SIGTERM, SIG_IGN );

    while ( keep_running ) {
        puts("Still running...");
    }

    if ( !keep_running ){
        puts("Received SIGINT!");
        return 1;
    }

    return 0;
}
