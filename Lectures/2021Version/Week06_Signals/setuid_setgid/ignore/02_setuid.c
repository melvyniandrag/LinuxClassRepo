#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
	printf("uid: %d\n euid:%d\n", getuid(), geteuid());
    	system("apt-get update");
}
