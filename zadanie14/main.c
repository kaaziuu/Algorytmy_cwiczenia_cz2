#include <time.h>
#include<stdlib.h>
#include <stdio.h>
#include "lib.h"
int main(int argc, char const *argv[])
{

    tree *T = NULL;
    dodaj(&T, 2);
    // print(T, 0);
    dodaj(&T, 4);
    dodaj(&T, 6);
    dodaj(&T, 9);
    dodaj(&T, 5);
    dodaj(&T, 3);
    dodaj(&T, 1);
    dodaj(&T, 0);
    dodaj(&T, -10);
    dodaj(&T, -26);
    dodaj(&T, -8);
    print(T, 0);
    int width = szer(T);
    printf("\n%d\n", width);

}