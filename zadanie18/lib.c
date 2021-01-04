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
            return searchMin(T->rightChild);
        }
        else
        {
            tree *parrent = T->parrent;
            tree *current = T;
            tree *returnValue = NULL;
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

tree *min(tree *T)
{
    if (T != NULL)
    {
        tree *min = T;
        tree *current = T;
        while (current != NULL)
        {
            if (current->value < min->value)
            {
                min = current;
            }
            current = current->leftChild;
        }
        return min;
    }
    return NULL;
}

tree *max(tree *T)
{
    if (T != NULL)
    {
        tree *max = T;
        tree *current = T;
        while (current != NULL)
        {
            if (current->value > max->value)
            {
                max = current;
            }
            current = current->rightChild;
        }
        return max;
    }
    return NULL;
}

// szukanie minimalnej wartosci i po przez nastepniki sprawdzenie czy nastepna wartosc sie zgadza
int isThisSame(tree *T1, tree *T2)
{
    if (T1 != NULL && T2 != NULL)
    {
        tree *t1current = searchMin(T1);
        tree *t2current = searchMin(T2);
        // printf("%d-%d\n", T1->value, T2->value);

        // tree *t1max = max(T1);
        // tree *t2max = max(T2);
        // printf("%d-%d\n%d-%d", t1current->value, t1max->value, t2current->value, t2max->value);

        while (t1current != NULL && NULL != t2current)
        {
            if (t1current->value != t2current->value)
            {
                return 0;
            }
            t1current = nast(t1current);
            t2current = nast(t2current);
        }
        if(t1current == NULL && t2current == NULL)
        {
            return 1;
        }
    }
    return 0;
}
