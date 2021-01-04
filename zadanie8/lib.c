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

void addUnsorted(tree **T, int y)
{
    tree *current = *T;

    int dec = rand() % 2;
    if (current == NULL)
    {
        tree *newEl = (tree *)malloc(sizeof(tree));
        newEl->value = y;
        *T = newEl;
        newEl->parrent = NULL;
        newEl->leftChild = NULL;
        newEl->rightChild = NULL;
    }
    else if (dec)
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
            addUnsorted(&current->rightChild, y);
        }
    }
    else if (!dec)
    {
        if (current->leftChild == NULL)
        {
            tree *newEl = (tree *)malloc(sizeof(tree));
            newEl->value = y;
            newEl->parrent = current;
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
            addSorted(&current->rightChild, y);
        }
    }
    else if (current->value >= y)
    {
        if (current->leftChild == NULL)
        {
            tree *newEl = (tree *)malloc(sizeof(tree));
            newEl->value = y;
            newEl->parrent = current;
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

tree *nast(tree *T)
{
    if (T != NULL)
    {
        if (T->rightChild)
        {
            return searchMin(T->rightChild);
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

tree *usunSorted(tree *T, int y)
{
    if (T != NULL)
    {
        tree *current = T;

        while (current != NULL && current->value != y)
        {
            if (current->value >= y)
            {
                current = current->leftChild;
            }
            else
            {
                current = current->rightChild;
            }
        }
        if(current == NULL)
        {
            return T;
        }

        tree *parrent = current->parrent;
        int isR = 1;
        if (parrent != NULL && parrent->leftChild == current)
        {
            isR = 0;
        }
        if (current->leftChild && current->rightChild)
        {

            tree *n = nast(current);
            current->value = n->value;
            n->parrent->leftChild = n->rightChild;
            if(n->rightChild)
                n->rightChild->parrent = n->parrent;
            free(n);
        }
        else if (current->leftChild)
        {
            if (current == T)
            {
                T = T->leftChild;
                free(current);
                return T;
            }
            if (isR)
            {
                parrent->rightChild = current->leftChild;
            }
            else
            {
                parrent->leftChild = current->leftChild;
            }
            current->leftChild->parrent = parrent;
            free(current);
        }
        else
        {
            if (T == current)
            {
                T = T->rightChild;
                free(current);
                return T;
            }
            if (isR)
            {
                parrent->rightChild = current->rightChild;
            }
            else
            {
                parrent->leftChild = current->rightChild;
            }
            current->rightChild->parrent = parrent;
            free(current);
        }
        return T;
    }
    return NULL;
}

tree *find(tree *T, int y)
{
    if (T == NULL)
    {
        return NULL;
    }
    if (T->value == y)
    {
        return T;
    }
    tree *lResult = find(T->leftChild, y);
    tree *rResult = find(T->rightChild, y);
    if (lResult != NULL)
    {
        return lResult;
    }
    return rResult;
}

tree *usunUnsorted(tree *T, int y)
{
    if (T != NULL)
    {
        tree *toDel = find(T, y);
        tree *parrent = toDel->parrent;
        int isR = 1;
        if (parrent != NULL && parrent->leftChild == toDel)
        {
            isR = 0;
        }
        if (toDel->leftChild && toDel->rightChild)
        {

            tree *tmp = toDel;
            while (tmp->leftChild)
            {
                tmp = tmp->leftChild;
            }
            toDel->value = tmp->value;
            tmp->parrent->leftChild = tmp->rightChild;
            if(tmp->rightChild)
                tmp->rightChild->parrent = tmp->parrent;
            free(tmp);
        }
        else if (toDel->leftChild)
        {
            if (T == toDel)
            {
                T=T->leftChild;
                free(toDel);
                return T;
            }
            if (isR)
            {
                parrent->rightChild = toDel->leftChild;
            }
            else
            {
                parrent->leftChild = toDel->leftChild;
            }
            toDel->leftChild->parrent = parrent;
            free(toDel);
        }
        else
        {
            if (T == toDel)
            {
                tree *tmp = T->rightChild;
                free(T);
                return tmp->rightChild;
            }
            if (isR)
            {
                parrent->rightChild = toDel->rightChild;
            }
            else
            {
                parrent->leftChild = toDel->rightChild;
            }
            toDel->rightChild->parrent = parrent;
            free(toDel);
        }
        return T;
    }
    return NULL;
}