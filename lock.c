#include "lock.h"
#define SIM 0
int Lock = 1;

int getLock(void)
{
    return Lock;
}

void setLock(int State)
{
    Lock = State;
}
