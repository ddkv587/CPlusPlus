#include <iostream>
#include <stdlib.h>

static int exchange = 0;
static int i 		= 0;
static int j 		= 0;
static int posi 	= 0;

void quickSort( int* array, int start, int end )
{
	exchange = 0;
	if ( end <= start  ) return;
	// if ( ( end - start ) == 1 ) {
	// 	if ( array[end] < array[start] ) {
	// 		exchange 		= array[end];
	// 		array[end] 		= array[start];
	// 		array[start]	= exchange;
	// 	}
	// 	return;
	// }
	i 		= start + 1;
	j 		= end;
	while( i < j ) {
		while ( array[i] <= array[start] && i < j ) { ++i; }		// find next value more than T 
		while ( array[j] > array[start] && j > i ) { --j; }			// find next value less than T

		if ( i < j ) {
			// exchange
			exchange = array[i];
			array[i++] = array[j];
			array[j--] = exchange;
		}
	}
	
	if ( array[start] <= array[i] ) {
		exchange = array[i-1];
		array[i-1] = array[start];
		array[start] = exchange;
		posi = i - 1;
	} else {
		exchange = array[i];
		array[i] = array[start];
		array[start] = exchange;
		posi = i;
	}

	quickSort( array, start, posi - 1 );
	quickSort( array, posi + 1, end );
}

#define DEF_SIZE 10000000

int main(int argc, const char *argv[])
{
	int* array = new int[DEF_SIZE];

	for ( int i = 0; i < DEF_SIZE; ++i ) {
		array[i] = random() % DEF_SIZE;
	}

	// for ( int i = 0; i < DEF_SIZE; ++i ) {
	// 	std::cout << array[i] << " ";
	// }
	// std::cout << std::endl;
	
	quickSort( array, 0, DEF_SIZE - 1 );

	// for ( int i = 0; i < DEF_SIZE; ++i ) {
	// 	std::cout << array[i] << " ";
	// }
	// std::cout << std::endl;
	
	delete [] array;
	return 0;
}
