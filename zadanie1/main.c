
#include "lib.h"
#include "stdlib.h"


int main(int argc, char const *argv[])
{
    tree *T = NULL;
    dodaj2(&T, 2);
    print(T, 0);
    dodaj2(&T, 4);
    dodaj2(&T, 5);
    dodaj2(&T, 3);
    dodaj2(&T, 1);
    dodaj2(&T, 0);
    dodaj2(&T, -10);
    dodaj2(&T, -26);
    dodaj2(&T, -8);
    print(T, 0);

    return 0;
}
