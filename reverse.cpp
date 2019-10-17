#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};

void create( struct node* head, int size )
{
	if ( head == NULL || size <= 0 ) return;

	node* pt = head;
	for ( int i=0; i < size; ++i ) {
		node* n = new node;
		n->data = i;
		n->next = NULL;

		pt->next = n;
		pt = n;
	}
}

void print( struct node* head )
{
	node* pt = head->next;

	while( pt ) {
		fprintf( stderr, "data: %d\n", pt->data );
		pt = pt->next;
	}
}

void reverse( struct node* head )
{
	node* ne = head->next;
	head->next = NULL;

	while ( ne ) {
		node* pt = ne;
		ne = ne->next;

		pt->next = head->next;
		head->next = pt;
	}
}

int main(int argc, const char *argv[])
{
	node head;
	create( &head, 10 );
	print( &head );

	reverse( &head );
	print( &head );

	return 0;
}
