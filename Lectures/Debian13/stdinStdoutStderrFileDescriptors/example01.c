#include <stdio.h>

int main(void)
{
	fprintf(stdout, "Hello stdout via fprintf\n");
	fprintf(stderr, "Hello stderr via fprintf\n");
	return 0;
}
