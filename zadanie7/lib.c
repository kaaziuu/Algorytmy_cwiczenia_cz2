#include "stdlib.h"
#include "lib.h"
#include <stdio.h>

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
        newEl->parrent = NULL;
        newEl->leftChild = NULL;
        newEl->rightChild = NULL;
    }
    else if (current->value < y)
    {
        if (current->rightChild == NULL)
        {
            tree *newEl = (tree *)malloc(sizeof(tree));
            newEl->value = y;
            newEl->parrent = current;
            newEl->leftChild = NULL;
            newEl->rightChild = NULL;
            current->rightChild = newEl;
        }
        else
        {
            dodaj(&current->rightChild, y);
        }
    }
    else if (current->value > y)
    {
        if (current->leftChild == NULL)
        {
            tree *newEl = (tree *)malloc(sizeof(tree));
            newEl->parrent = current;
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

tree *searchMin(tree *T)
{
    if (T != NULL)
    {
        tree *current = T;
        while (current->leftChild != NULL)
        {
            current = current->leftChild;
        }
        return current;
    }
    return NULL;
}

tree *searchMax(tree *T)
{
    if (T != NULL)
    {
        tree *current = T;
        while (current->rightChild != NULL)
        {
            current = current->rightChild;
        }
        return current;
    }
    return NULL;
}

tree *nast(tree *T)
{
    if (T != NULL)
    {
        if (T->rightChild)
        {
            return searchMin(T);
        }
        else
        {
            tree *parrent = T->parrent;
            while (parrent != NULL && (T == parrent->rightChild))
            {
                T = parrent;
                parrent = parrent->parrent;
            }
            return parrent;
        }
    }
}

tree *poprz(tree *T)
{
    if (T->leftChild)
    {
        return searchMax(T->leftChild);
    }
    tree *parrent = (tree *)malloc(sizeof(tree));
    parrent = T->parrent;
    while (parrent != NULL && T == parrent->leftChild)
    {
        T = parrent;
        parrent = parrent->parrent;
    }
    return parrent;
}