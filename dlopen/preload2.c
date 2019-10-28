#include <stdio.h>

extern "C"
{
void foo()
{
	printf( "call foo in preload2\n" );
}

void foo2()
{
	printf( "call foo2 in preload2\n" );
}
}
