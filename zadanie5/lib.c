#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void print(tree *T, int deep)
{
    if (T == NULL)
        return;
    print(T->leftChild, deep + 1);
    int i;
    for (i = 0; i < deep; i++)
    {
        printf("_");
    }
    printf("%d \n", T->value);

    print(T->rightChild, deep + 1);
}

tree *utworz(int n)
{
    if (n == 0)
    {
        return NULL;
    }
    else if (n == 1)
    {
        tree *newEl = (tree *)malloc(sizeof(tree));
        newEl->value = 0;
        newEl->leftChild = NULL;
        newEl->rightChild = NULL;
        return newEl;
    }
    tree *leftChild = utworz((n - 1) / 2);
    tree *rightChild = NULL;
    if ((n - 1) % 2 == 0)
    {
        rightChild = utworz((n - 1) / 2);
    }
    else
    {
        rightChild = utworz(n / 2);
    }
    tree *newEl = (tree *)malloc(sizeof(tree));
    newEl->value = 0;
    newEl->leftChild = leftChild;
    newEl->rightChild = rightChild;
}

void utworz2(tree **T, int n)
{
    if (n == 0)
    {
        return;
    }
    tree *newEl = (tree *)malloc(sizeof(tree));
    newEl->value = 0;
    newEl->leftChild = NULL;
    newEl->rightChild = NULL;
    *T = newEl;
    n--;
    if (n > 0)
    {
        utworz2(&(*T)->leftChild, n / 2);
        if (n % 2 == 0)
        {
            utworz2(&(*T)->rightChild, n / 2);
        }
        else
        {
            utworz2(&(*T)->rightChild, (n+1)/2);

        }
    }
}
