typedef struct tree
{
    struct tree *leftChild;
    struct tree *rightChild;
    int value;
} tree;

void addUnsorted(tree **T, int y);
void addSorted(tree **T, int y);
void print(tree *T, int deep);

tree *szukajSorted(tree *T, int y);
tree **szykajUnsorted(tree **T, int y);