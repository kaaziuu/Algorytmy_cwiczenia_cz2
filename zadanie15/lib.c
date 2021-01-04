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

void levelPrinter(int currentLevel, int k, tree *T)
{
    if (T == NULL)
        return;
    if (k == currentLevel)
    {
        printf("%d\n", T->value);
        return;
    }

    levelPrinter(currentLevel + 1, k, T->leftChild);
    levelPrinter(currentLevel + 1, k, T->rightChild);
}

int wys(tree *T)
{
    if (T == NULL)
    {
        return 0;
    }
    int leftHeight = 1 + wys(T->leftChild);
    int rightHeight = 1 + wys(T->rightChild);
    if (leftHeight > rightHeight)
    {
        return leftHeight;
    }
    return rightHeight;
}

int getWidth(tree *T, int level)
{
    if (T == NULL)
    {
        return 0;
    }
    if (level == 1)
    {
        return 1;
    }
    if (level > 1)
    {
        return getWidth(T->leftChild, level - 1) + getWidth(T->rightChild, level - 1);
    }
}

int maxDifferenceHeight(tree *T)
{
    if(T==NULL)
    {
        return 0;
    }
    int lMax = maxDifferenceHeight(T->leftChild);
    int rMax = maxDifferenceHeight(T->rightChild);
    int lHeight = wys(T->leftChild);
    int rHeight = wys(T->rightChild);
    int difference = abs(lHeight - rHeight);
    if(difference > rMax && difference > lMax)
    {
        return difference;
    }
    else if(lMax > rMax)
    {
        return lMax;
    }
    return rMax;

}

int count(tree *T)
{
    if(T == NULL)
    {
        return 0;
    }
    return count(T->rightChild) + count(T->leftChild) +1;

}



int maxDifferenceCount(tree *T)
{
    if(T==NULL)
    {
        return 0;
    }
    int lMax = maxDifferenceCount(T->leftChild);
    int rMax = maxDifferenceCount(T->rightChild);
    int lCount = count(T->leftChild);
    int rCount = count(T->rightChild);
    int difference = abs(lCount - rCount);

    if(difference > rMax && difference > lMax)
    {
        return difference;
    }
    else if(lMax > rMax)
    {
        return lMax;
    }
    return rMax;

}