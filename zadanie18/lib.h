typedef struct  tree
{
    struct tree *parrent;
    struct tree *leftChild;
    struct tree *rightChild;
    int value;
} tree;
void dodaj(tree **T, int y);
void print(tree *T, int deep);
 
tree *nast(tree *T);

tree *searchMin(tree *T);

tree *searchMax(tree *T);

tree *poprz(tree *T);


int isThisSame(tree *T1, tree *T2);
