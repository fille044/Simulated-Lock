#include <stdio.h>
#include "input.h"
#include "lock.h"

int main(void)
{
    int b = dumbfunction(4);
    int a = getInput(19);
    printf("HelloWorld! %d %d\n", a, b);
    return 0;
}
