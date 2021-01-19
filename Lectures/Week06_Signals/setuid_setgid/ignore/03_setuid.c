#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
	printf("uid: %d\neuid:%d\n", getuid(), geteuid());
    	system("id");
    	system("id -u");
        printf("************************************\n");	
	setuid(0);
	printf("uid: %d\neuid:%d\n", getuid(), geteuid());
    	system("id");
    	system("id -u");
}
