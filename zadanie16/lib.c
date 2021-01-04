#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "math.h"

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

int isThisSame(tree *T1, tree *T2)
{
    if(T1==NULL && T2 == NULL)
    {
        return 1;
    }
    if(T1==NULL)
    {
        return 0;
    }
    if(T2 == NULL)
    {
        return 0;
    }

    int lCheckt = isThisSame(T1->leftChild, T2->leftChild);
    int rCheckt = isThisSame(T1->rightChild, T2->rightChild);

    if(T1->value != T2->value || lCheckt == 0 || rCheckt == 0)
    {
        return 0;
    }
    return 1;


}