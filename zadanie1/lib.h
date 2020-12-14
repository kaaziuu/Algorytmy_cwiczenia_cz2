typedef struct  tree
{
    struct tree *leftChild;
    struct tree *rightChild;
    int value;
} tree;

tree *dodaj(tree *T, int y);
void  dodaj2(tree **T, int y);

void print(tree *T, int deep);