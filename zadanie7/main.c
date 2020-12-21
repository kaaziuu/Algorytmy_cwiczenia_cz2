#include "lib.h"
#include "stdlib.h"
#include "stdio.h"
int main(int argc, char const *argv[])
{
    tree *T = NULL;
    dodaj(&T, 9);
    dodaj(&T, 5);
    dodaj(&T, 15);
    dodaj(&T, 10);
    dodaj(&T, 18);
    dodaj(&T, 12);
    dodaj(&T, 19);
    dodaj(&T, 4);
    dodaj(&T, 7);
    dodaj(&T, 1);
    dodaj(&T, 6);
    dodaj(&T, 8);
    print(T, 0);
    printf("_______________________\n");
    tree *test = T->leftChild->leftChild;
    tree *help = (tree *)malloc(sizeof(tree));
    tree *result = nast(test);
    printf("%d\n", result->value);
    /* code */
    return 0;
}
