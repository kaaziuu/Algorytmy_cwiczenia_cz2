#include "lib.h"
#include <stdlib.h>
#include "string.h"
#include <stdio.h>

void print(HUNode *head, int deep)
{
    if (head == NULL)
        return;
    print(head->left, deep + 1);
    int i;
    for (i = 0; i < deep; i++)
    {
        printf("_");
    }
    printf("%d-%c\n", head->count, head->ch);

    print(head->right, deep + 1);
}

void printList(HUNode *head)
{
    if (head != NULL)
    {
        HUNode *current = head;
        while (current)
        {
            printf("-%d:%c-", current->count, current->ch);
            current = current->next;
        }
    }
}

HUNode *worldToList(HUNode *head, char *word)
{
    if (word != NULL)
    {
        char c;
        int i;
        HUNode *current, *before;

        for (i = 0; i < strlen(word); i++)
        {
            current = head;
            before = NULL;
            c = word[i];
            while (current && current->ch != c)
            {
                before = current;
                current = current->next;
            }
            if (current == NULL)
            {
                HUNode *newNode = (HUNode *)malloc(sizeof(HUNode));
                newNode->ch = c;
                newNode->count = 1;
                newNode->next = head;
                newNode->left = NULL;
                newNode->right = NULL;
                head = newNode;
            }
            else
            {
                current->count++;

                if (current->next && current->next->count < current->count)
                {
                    HUNode *nextNode = current->next;
                    HUNode *beforeCurrent = current;
                    while (nextNode && nextNode->count < current->count)
                    {
                        beforeCurrent = nextNode;
                        nextNode = nextNode->next;
                    }
                    if (nextNode && before)
                    {
                        before->next = current->next;

                        beforeCurrent->next = current;
                        current->next = nextNode;
                    }
                    else if (before)
                    {

                        before->next = current->next;
                        beforeCurrent->next = current;
                        current->next = NULL;
                    }
                    else
                    {
                        head = current->next;
                        beforeCurrent->next = current;
                        current->next = nextNode;
                    }
                }
            }
        }
    }

    return head;
}

int isTree(HUNode *node)
{
    if (node->left || node->right)
    {
        return 1;
    }
    return 0;
}

HUNode *insert(HUNode *head, HUNode *node)
{
    if (head != NULL)
    {
        HUNode *current = head;
        HUNode *before = NULL;
        while (current != NULL && current->count < node->count)
        {

            before = current;

            current = current->next;
        }

        if (before != NULL)
        {
            before->next = node;
            node->next = current;
        }
        else
        {
            node->next = head;
            return node;
        }
        return head;
    }
    return node;
}

HUNode *makeTree(HUNode *head)
{

    if (head != NULL)
    {
        HUNode *point, *nextPoint;
        while (head->next != NULL)
        {
            point = head;
            nextPoint = head->next;

            head = nextPoint->next;
            HUNode *newNode = (HUNode *)malloc(sizeof(HUNode));
            newNode->left = point;
            newNode->right = nextPoint;
            newNode->count = point->count + nextPoint->count;
            newNode->next = NULL;
            newNode->ch = '_';
            
            head = insert(head, newNode);

        }
    }
    return head;
}

HUNode *compressWord(HUNode *head, char *word)
{
    head = worldToList(head, word);

    head = makeTree(head);
    return head;
}
