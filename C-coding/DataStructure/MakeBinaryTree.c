#include <stdio.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

struct TreeNode
{
    int iNum;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty( SearchTree T )
{
    if ( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    return NULL;
}
