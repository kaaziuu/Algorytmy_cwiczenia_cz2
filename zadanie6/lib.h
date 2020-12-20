typedef struct  tree
{
    struct tree *leftChild;
    struct tree *rightChild;
    int value;
} tree;

void print(tree *T, int deep);


void  dodaj(tree **T, int y);


void addRandom(tree **T, int y);

int countSort(tree *T, int y);

int countUnsorted(tree *T, int y);
