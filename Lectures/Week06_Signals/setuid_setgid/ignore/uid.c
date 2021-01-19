#include <stdio.h> 
#include <unistd.h> 

int main () {

  printf("CHILD  %d -------------------\n", getpid()); 
  printf("     UID           GID  \n"
        "Real      %d  Real      %d  \n"
        "Effective %d  Effective %d  \n",
             getuid (),     getgid (),
             geteuid(),     getegid()
    );
  puts("---------------------------------");
 return 0; 
}
