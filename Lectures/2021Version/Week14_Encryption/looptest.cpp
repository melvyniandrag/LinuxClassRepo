#include <iostream>
#include <cassert>

int main()
{
	assert( sizeof(unsigned long long) == 8);
	const unsigned long long PRINT_FREQ = 1000000000;
	char c = 0;
	for ( unsigned long long i = 0; i < UINT64_MAX; ++i )
	{
		for ( unsigned long long j = 0; j < UINT64_MAX; ++j )
		{
			if( j % PRINT_FREQ == 0 )
			       	std::cout << i << "/" << UINT64_MAX << " , "<< j << "/" << UINT64_MAX << std::endl;
			c++;
		}  
	}
	std::cout << c << std::endl;
}
