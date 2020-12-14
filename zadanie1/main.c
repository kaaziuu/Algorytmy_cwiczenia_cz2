
#include "lib.h"
#include "stdlib.h"


int main(int argc, char const *argv[])
{
    tree *T = NULL;
    T = dodaj(T, 2);
    print(T, 0);
    T = dodaj(T, 4);
    T = dodaj(T, 5);
    T = dodaj(T, 3);
    T = dodaj(T, 1);
    T = dodaj(T, 0);
    T = dodaj(T, -10);
    T = dodaj(T, -26);
    T = dodaj(T, -8);
    print(T, 0);

    return 0;
}
