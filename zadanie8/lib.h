typedef struct  tree
{
    struct tree *parrent;
    struct tree *leftChild;
    struct tree *rightChild;
    int value;
} tree;
void addSorted(tree **T, int y);
void addUnsorted(tree **T, int y);
void print(tree *T, int deep);


tree *usunSorted(tree *T, int y);
tree *usunUnsorted(tree *T, int y);