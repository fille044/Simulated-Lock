#include <stdio.h>
#include "input.h"
#include "lock.h"


int main(void)
{
    setLock(1);
    int b = getLock();
    int a = getInput(19);

    printf("HelloWorld! %d \n", checkInput(-60, 10));
    return 0;
}
