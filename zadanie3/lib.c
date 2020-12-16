#include <stdio.h>
#include <time.h>

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


void addUnsorted(tree **T, int y)
{
    tree *current = *T;

    int dec = rand() % 2;
    if (current == NULL)
    {
        tree *newEl = (tree *)malloc(sizeof(tree));
        newEl->value = y;
        *T = newEl;
        newEl->leftChild = NULL;
        newEl->rightChild = NULL;
    }
    else if (dec)
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
            addUnsorted(&current->rightChild, y);
        }
    }
    else if (!dec)
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
            addUnsorted(&current->leftChild, y);
        }
    }
}

void addSorted(tree **T, int y)
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
            addSorted(&current->rightChild, y);
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
            addSorted(&current->leftChild, y);
        }
    }
}

tree *szukajSorted(tree *T, int y)
{
    if (T != NULL)
    {
        tree *current = T;
        while (current != NULL && current->value != y)
        {
            if (current->value > y)
            {
                current = current->rightChild;
            }
            else
            {
                current = current->leftChild;
            }
        }
        return current;
    }
    return NULL;
}

tree **szykajUnsorted(tree **T, int y)
{
    if (T == NULL || *T == NULL)
    {
        return NULL;
    }
    else if ((*T)->value == y)
    {
        // printf("%d \n", T->value);
        return T;
    }
    tree **leftResult = szykajUnsorted(&(*T)->leftChild, y);
    tree **rightResult = szykajUnsorted(&(*T)->rightChild, y);
    // printf("%p \n", *leftResult);
    if (leftResult != NULL)
    {
        return leftResult;
    }
    else if (rightResult != NULL)
    {
        return rightResult;
    }
    return NULL;
}