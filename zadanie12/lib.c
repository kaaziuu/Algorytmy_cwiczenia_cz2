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

void dodaj(tree **T, int y)
{
    tree *current = *T;
    if (current == NULL)
    {
        tree *newEl = (tree *)malloc(sizeof(tree));
        newEl->value = y;
        *T = newEl;
        newEl->leftChild = NULL;
        newEl->rightChild = NULL;
    }
    else if (current->value > y)
    {
        if (current->rightChild == NULL)
        {
            tree *newEl = (tree *)malloc(sizeof(tree));
            newEl->value = y;
            newEl->leftChild = NULL;
            newEl->rightChild = NULL;
            current->rightChild = newEl;
        }
        else
        {
            dodaj(&current->rightChild, y);
        }
    }
    else if (current->value < y)
    {
        if (current->leftChild == NULL)
        {
            tree *newEl = (tree *)malloc(sizeof(tree));
            newEl->value = y;
            newEl->leftChild = NULL;
            newEl->rightChild = NULL;
            current->leftChild = newEl;
        }
        else
        {
            dodaj(&current->leftChild, y);
        }
    }
}

int wys(tree *T)
{
    if(T==NULL)
    {
        return 0;
    }
    int leftHeight = 1 + wys(T->leftChild);
    int rightHeight = 1 + wys(T->rightChild);
    if(leftHeight > rightHeight)
    {
        return leftHeight;
    }
    return rightHeight;
    
}