#include <stdio.h>

extern "C"
{
void foo()
{
	printf( "call foo in preload\n" );
}

void foo2()
{
	printf( "call foo2 in preload\n" );
}
}
