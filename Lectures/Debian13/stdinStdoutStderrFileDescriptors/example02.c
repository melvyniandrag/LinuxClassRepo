#include <unistd.h>

int main(int argc, char** argv)
{
	write(1, "Hello stdout\n", 13);
	write(2, "Hello stderr\n", 13);
	return 0;
}
