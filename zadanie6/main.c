#include "lib.h"
#include "stdlib.h"
#include <time.h>
#include "stdio.h"


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    tree *T = NULL;
    addRandom(&T, 2);
    addRandom(&T, 4);
    addRandom(&T, 5);
    addRandom(&T, 4);
    addRandom(&T, 5);
    addRandom(&T, 4);

    addRandom(&T, 0);
    addRandom(&T, -10);

    addRandom(&T, 4);
    addRandom(&T, 4);
    addRandom(&T, 4);
    addRandom(&T, -8);
    addRandom(&T, 5);
    addRandom(&T, 3);
    print(T, 0);

    int ct = countUnsorted(T, 4);
    
    printf("ct=%d\n", ct);
    return 0;
}
