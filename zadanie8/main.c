#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
int main(int argc, char const *argv[])
{
    srand(time(NULL));

    tree *T = NULL;
    addUnsorted(&T, 2);
    addUnsorted(&T, 5);
    addUnsorted(&T, 4);
    addUnsorted(&T, 1);
    addUnsorted(&T, 4);
    addUnsorted(&T, 0);
    addUnsorted(&T, 4);
    addUnsorted(&T, -26);
    addUnsorted(&T, 4);
    print(T, 0);
    printf("______________\n");

    T = usunUnsorted(T, 4);
    print(T, 0);
    printf("______________\n");
    // print(*test, 0);
    return 0;
}