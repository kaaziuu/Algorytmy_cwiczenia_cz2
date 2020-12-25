#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
int main(int argc, char const *argv[])
{
    srand(time(NULL));

    tree *T = NULL;
    addSorted(&T, 1);
    addSorted(&T, 4);
    addSorted(&T, 2);
    addSorted(&T, 4);
    addSorted(&T, 2);
    addSorted(&T, 3);
    addSorted(&T, 2);
    addSorted(&T, 4);
    addSorted(&T, 6);

    addSorted(&T, 4);
    



    print(T, 0);
    printf("______________\n");

    T = usunUnsorted(T, 4);
    print(T, 0);
    printf("______________\n");
    // print(*test, 0);
    return 0;
}