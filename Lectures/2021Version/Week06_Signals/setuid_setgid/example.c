/**
 * What a great example this is. 
 * You see calls to 4 cool Unix functions!
 *    1. set_uid() - sets the user id
 *    2. set_gid() - sets the group id
 *    3. fork() - makes a copy of a process
 *    4. execve() - creates a new process
 * 
 * I don't expect you to understand the details. 
 * Alot of things have to go unsaid about this program.
 * I just want you to see that we can run this root command from 
 * a non root user!!
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char* const root_command[4] = { "/bin/sh", "-c", "cat /root/hello.txt"};

int main(void)
{
    int uid_of_person_running_code = getuid();

    printf("My UID is: %d. My GID is: %d\n", getuid(), getgid());
    
    if ( setuid(0) ) // Note the return value 0 means good!
    {
        perror("setuid");
        return 1;
    }
   
    printf("My UID is: %d. My GID is: %d\n", getuid(), getgid());

    // Good Linux stuff ahead!
    // fork() call followed by execve()!
    pid_t pid = fork();
    if (pid){
        execve( root_command[0], root_command, NULL );
    }
    
    //Time to drop back to regular user privileges
    setuid(uid_of_person_running_code);
    
    printf("My UID is: %d. My GID is: %d\n", getuid(), getgid());
    
    return 0;
}
