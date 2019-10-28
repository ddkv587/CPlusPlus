struct Node {
    int     data;
    Node*   lChind;
    Node*   rChild;
};

void insertTree( Node* tree, Node* node )
{
    if ( NULL == tree || NULL == node ) return;

    if ( tree->data > node->data ) {
        if ( tree->lChild ) {
            insert( tree->lChild, node )
        } else {
            tree->lChild = node;
        }
    } else {
        if ( tree->rChild ) {
            insert( tree->rChild, node );
        } else {
            tree->rChild = node;
        }
    }
}

void printTree( Node* tree )
{
    if ( NULL == tree ) return;

    if ( tree->lChild ) printTree( tree->lChild );

    print( "data: %d\n", tree-> data );

    if ( tree->rChild ) printTree( tree->rChild );
}

int main( int argc, char **argv )
{
    Node tree;
    for ( int i=0; i< 10; ++i ) {
        Node* node = new Node();
        node->data      = i;
        node->lChild    = NULL;
        node->rChild    = NULL;
        insert( &tree, node );
    }

    return 0;
}