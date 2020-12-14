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

tree *dodaj(tree *T, int Y)
{
    if(T==NULL)
    {
        tree *newEl = (tree *)malloc(sizeof(tree));
        newEl->value = Y;
        newEl->leftChild = NULL;
        newEl->rightChild = NULL;
        return newEl;

    }
    else if(T->value > Y)
    {
        T->rightChild = dodaj(T->rightChild, Y);
    }
    else if(T->value < Y)
    {
        T->leftChild = dodaj(T->leftChild, Y);
    }
    return T;
}

void dodaj2(tree **T, int y)
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
            dodaj2(&current->rightChild, y);
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
            dodaj2(&current->leftChild, y);
        }
    }
}