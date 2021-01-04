typedef struct  tree
{
    struct tree *leftChild;
    struct tree *rightChild;
    int value;
} tree;

void dodaj(tree **T, int y);
void print(tree *T, int deep);

int maxDifferenceHeight(tree *T);

int maxDifferenceCount(tree *T);