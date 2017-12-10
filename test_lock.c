
/* -------------------------------------------*/
/*
    Test och verifiering - Mölk Utbildning

    Description: Test cases for calculations made in Calculator.c
*/
/* -------------------------------------------*/


#include "../unity/src/unity.h"
#include "input.h"
#include "lock.h"

// Compile commands     gcc TestDumbExample.c DumbExample.c unity/src/unity.c -o TestDumbExample


void test_getInput(void)
{
    TEST_ASSERT_EQUAL(17, getInput(17));
    TEST_ASSERT_EQUAL(0, getInput(-17));
    TEST_ASSERT_EQUAL(256, getInput(256));
}


void test_checkInput(void)
{
    TEST_ASSERT_EQUAL(1, checkInput(200, 200));
    TEST_ASSERT_EQUAL(1, checkInput(1000, 960));
    TEST_ASSERT_EQUAL(0, checkInput(200, 140));
    TEST_ASSERT_EQUAL(0, checkInput(200, 260));
    TEST_ASSERT_EQUAL(1, checkInput(-50, 10));
    TEST_ASSERT_EQUAL(1, checkInput(0, 0));
}


void test_getLock(void)
{
    setLock(0);
    TEST_ASSERT_EQUAL(0, getLock());
    setLock(1);
    TEST_ASSERT_EQUAL(1, getLock());
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_getInput);
    RUN_TEST(test_checkInput);
    RUN_TEST(test_getLock);
    return UNITY_END();
}
