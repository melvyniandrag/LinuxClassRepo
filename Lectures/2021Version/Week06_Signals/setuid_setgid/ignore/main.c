#include <stdio.h> 
#include <unistd.h> 


void print_info () {

  printf("     UID           GID  \n"
        "Real      %d  Real      %d  \n"
        "Effective %d  Effective %d  \n",
             getuid (),     getgid (),
             geteuid(),     getegid()
    );
 return; 
}


int main () {

 pid_t pid; 
 int status; 
 pid = fork(); 

 if (!pid) {
   puts("Childe process\n"); 
   execv("./uid.out", NULL); 
   return;
 } 

 wait(status); 

 printf("Father %d -------------------\n", getpid());
 print_info();
 puts("--------------------------------"); 

 return 0; 
} 
