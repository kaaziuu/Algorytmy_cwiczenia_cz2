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

void removeTree(tree **value)
{
    int isR = 1;
    tree *T = *value;
    tree *parrent = T->parrent;

    if (parrent && parrent->leftChild == T)
    {
        isR = 0;
    }
    if (T->leftChild && T->rightChild)
    {
        tree *help = T;
        while (help->leftChild)
        {
            help = help->leftChild;
        }

        T->value = help->value;
        help->parrent->leftChild = help->rightChild;
        if (help->rightChild)
            help->rightChild->parrent = help->parrent;

        free(help);
        return;
    }
    if (T->leftChild)
    {
        if (parrent == NULL)
        {
            *value = T->leftChild;
            free(T);
            return;
        }
        if (isR)
        {
            parrent->rightChild = T->leftChild;
        }
        else
        {
            parrent->leftChild = T->leftChild;
        }
        T->leftChild->parrent = parrent;
    }
    else if (T->rightChild)
    {

        if (parrent == NULL)
        {
            *value = T->rightChild;
            free(T);
            return;
        }
        if (isR)
        {
            parrent->rightChild = T->rightChild;
        }
        else
        {
            parrent->leftChild = T->rightChild;
        }
        T->rightChild->parrent = parrent;
    }
    else if (parrent)
    {
        if (isR)
        {
            parrent->rightChild = NULL;
        }
        else
        {
            parrent->leftChild = NULL;
        }
    }
    free(T);
}

tree *usunUnsorted(tree *T, int y)
{
    if (T != NULL)
    {
        tree *toDel = find(T, y);
        int i = 0;
        while (toDel != NULL)
        {
            removeTree(&toDel);
            toDel = find(T, y);
        }
        return T;
    }
    return NULL;
}

tree *usunSorted(tree *value, int y)
{
    tree *T = value;
    if (T != NULL)
    {
        tree *current = T;
        tree *start = NULL;
        tree *end = NULL;
        tree *parrent = NULL;
        tree *n = NULL;
        tree *help = NULL;
        int isR;
        while (current != NULL)
        {
            if (current->value > y)
            {
                current = current->leftChild;
                continue;
            }
            else if (current->value < y)
            {
                current = current->rightChild;
                continue;
            }
            parrent = current->parrent;
            start = current;
            while (current->leftChild && current->leftChild->value == y)
            {
                current = current->leftChild;
            }
            isR = 1;
            if (parrent && parrent->leftChild == current)
            {
                isR = 0;
            }
            if (current->leftChild && current->rightChild)
            {
                n = nast(current);
                if (isR)
                {
                    parrent->rightChild = n;
                }
                else
                {
                    parrent->leftChild = n;
                }
                n->parrent = parrent;
                while (start != current)
                {
                    help = start;
                    start = start->leftChild;
                    free(help);
                }
                free(current);
                continue;
            }
            if (current->leftChild)
            {
                if (parrent == NULL)
                {
                    help = T->leftChild;
                    free(T);
                    T = help;
                    continue;
                }
                if (isR)
                {
                    parrent->rightChild = T->rightChild;
                }
                else
                {
                    parrent->leftChild = T->rightChild;
                }
                T->rightChild->parrent = parrent;
            }
            else if (current->rightChild)
            {
                if (parrent == NULL)
                {
                    help = T->leftChild;
                    free(T);
                    T = help;
                    continue;
                }
                if (isR)
                {
                    parrent->rightChild = T->rightChild;
                }
                else
                {
                    parrent->leftChild = T->rightChild;
                }
                T->rightChild->parrent = parrent;
            }
            while (start != current)
            {
                help = start;
                start = start->leftChild;
                free(help);
            }
            free(current);
        }
        return T;
    }
    return NULL;
}