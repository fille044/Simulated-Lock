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
