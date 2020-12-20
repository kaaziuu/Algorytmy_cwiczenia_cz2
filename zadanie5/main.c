#include <time.h>
#include<stdlib.h>
#include "lib.h"
int main(int argc, char const *argv[])
{

    tree *T = NULL;
    utworz2(&T ,15);
    // int height = getHeight(T);
    print(T, 0);
    return 0;
}
