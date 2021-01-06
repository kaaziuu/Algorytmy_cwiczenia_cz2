#include "string.h"
#include <stdio.h>
#include "lib.h"

int main(int argc, char const *argv[])
{
    char *test;
    scanf("%s", test);
    HUNode *head = NULL;
    head = compressWord(head, test);
    print(head, 0);
    return 0;
}
