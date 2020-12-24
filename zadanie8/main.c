#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
int main(int argc, char const *argv[])
{
    srand(time(NULL));

    tree *T = NULL;
    addSorted(&T, 2);
    addSorted(&T, 5);
    addSorted(&T, 3);
    addSorted(&T, 1);
    addSorted(&T, 4);
    addSorted(&T, 0);
    addSorted(&T, -10);
    addSorted(&T, -26);
    addSorted(&T, -8);
    print(T, 0);
    printf("______________\n");

    tree *test = usunSorted(T, 0);
    print(test, 0);
    printf("______________\n");
    // print(*test, 0);
    return 0;
}