/***
 * g++ cpp_example_01.cpp -o cpp_example_01.out
 * ./cpp_example_01.out
 ***/

#include <iostream>

int main()
{
	// endl is like "endline", NOT "end one"
	// l and 1 look very similar in this font.
	std::cout << "This writes to stdout!" << std::endl;
	std::cerr << "This writes to stderr!" << std::endl;

}
