typedef struct  tree
{
    struct tree *leftChild;
    struct tree *rightChild;
    int value;
} tree;

tree *utworz(int n);


void utworz2(tree **T, int n);
void print(tree *T, int deep);
