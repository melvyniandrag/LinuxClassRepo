#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char* const cat_argv[4] = { "/bin/sh", "-c", "cat /root/hello.txt"};

int main(void)
{
    int current_uid = getuid();

    printf("My UID is: %d. My GID is: %d\n", current_uid, getgid());
    
    if ( setuid(0) ) // Note the return value 0 means good!
    {
        perror("setuid");
        return 1;
    }
    
    printf("My UID is: %d. My GID is: %d\n", getuid(), getgid());

    pid_t pid = fork();

    if (pid){
    
        execve( cat_argv[0], cat_argv, NULL );
    
    }
    //Time to drop back to regular user privileges
    setuid(current_uid);
    
    printf("My UID is: %d. My GID is: %d\n", getuid(), getgid());
    
    return 0;
}
