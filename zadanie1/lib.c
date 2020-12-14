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

    tree *newEl = (tree *)malloc(sizeof(tree));
    newEl->leftChild = NULL;
    newEl->rightChild = NULL;
    newEl->value = Y;
    if (T != NULL)
    {
        tree *current = T;
        while (current != NULL)
        {
            if (current->value > Y)
            {
                if (current->rightChild == NULL)
                {
                    current->rightChild = newEl;
                    break;
                }
                else
                {
                    current = current->rightChild;
                }
            }
            else if (current->value < Y)
            {
                if (current->leftChild == NULL)
                {
                    current->leftChild = newEl;
                    break;
                }
                else
                {
                    current = current->leftChild;
                }
            }
            else
            {
                break;
            }
        }
        return T;
    }
    else
    {
        return newEl;
    }
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