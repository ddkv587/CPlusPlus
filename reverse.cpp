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

void reverse( struct node*& pHead, struct node*& pTail )
{
	if ( !pHead || !pTail || pHead == pTail ) return;

	node head;
	head.next = pHead;

	node* pHolder = NULL;
	if ( pTail ) {
		pHolder = pTail->next;
		pTail->next = NULL;
	}

	reverse( &head );

	pHead = head.next;
	pTail = head.next;
	while ( pTail->next )
	{
		pTail = pTail->next;
	}
	pTail->next = pHolder;
}

void reverseK( struct node*& head, int k )
{
	if ( !head || k == 0 ) return;

	int count;
	node* pTail = head;
	for ( count = 1; count < k; ++count ) {
		if ( !pTail->next ) break;

		pTail = pTail->next;
	}
		
	reverse( head, pTail );

	if ( count == k ) {
		reverseK( pTail->next, k );
	}
}

int main(int argc, const char *argv[])
{
	node head;
	node head2;
	create( &head, 10 );
	create( &head2, 20 );

	reverse( &head );
	reverseK( head2.next, 3 );

	print( &head );
	print( &head2 );

	return 0;
}
