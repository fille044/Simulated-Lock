#include <stdio.h>
#include "input.h"
#include "lock.h"

int Lock = 1;

int getLock(void)
{
    return Lock;
}

void setLock(int State)
{
    Lock = State;
}

#include "input.h"
#include "stdio.h"

int getInput(int Input)
{
    if (Input < 0) {
        Input = 0;
    }
    return Input;
}

int checkInput(int Input, int Answer)
{
    int Min, Max;

    if (Input < 0) {
        Input = 0;
    }

    if (Answer < 50) {
        Min = 0;
        Max = Answer + 50;
    }
    else {
        Min = Answer - 50;
        Max = Answer + 50;
    }

    if (Input >= Min && Input <= Max)
        return 1;
    else {
        return 0;
    }
}


int main(void)
{
    setLock(1);
    int b = getLock();
    int a = getInput(19);

    printf("HelloWorld! %d \n", checkInput(-60, 10));
    return 0;
}
