/***
 * Compile this program and run it. 
 * Note that you don't see any output for fd 3. 
 * Try doing 3>&1 and you will now see the output!
 * You can also 3>somefile.txt and you will see the data go to a file.
 ***/
#include <unistd.h>

int main(int argc, char** argv)
{
	write(1, "Hello stdout\n", 13);
	write(2, "Hello stderr\n", 13);
	write(3, "Hello custom fd\n", 16);
	return 0;
}
