
/* -------------------------------------------*/
/*
    Test och verifiering - Mölk Utbildning

    Description: Test cases for calculations made in Calculator.c
*/
/* -------------------------------------------*/

#include "../unity/src/unity.h"
#include "input.h"

// Compile commands     gcc TestDumbExample.c DumbExample.c unity/src/unity.c -o TestDumbExample

void test_getInput(void)
{
    TEST_ASSERT_EQUAL(17, getInput(17));
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_getInput);

    return UNITY_END();
}
