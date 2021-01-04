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
    dodaj(&T, 5);
    dodaj(&T, 3);
    dodaj(&T, 1);
    dodaj(&T, 0);
    dodaj(&T, -10);
    dodaj(&T, -26);
    dodaj(&T, -8);
    dodaj(&T, 9);

    tree *T2 = NULL;
    dodaj(&T2, 2);
    dodaj(&T2, 4);
    dodaj(&T2, 5);
    dodaj(&T2, 3);
 
    dodaj(&T2, -8);
    dodaj(&T2, 9);

   dodaj(&T2, 1);
    dodaj(&T2, 0);
    dodaj(&T2, -26);
//    dodaj(&T2, 123);

    dodaj(&T2, 6);
    dodaj(&T2, -10);

    print(T,0);
    printf("_____________________\n");
    print(T2,0);
    printf("_____________________\n");

    int result = isThisSame(T, T2);
    printf("\n%d\n", result);

}