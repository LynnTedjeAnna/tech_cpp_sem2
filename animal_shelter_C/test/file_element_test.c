//
// Created by Lynn Tedje Anna Meindertsma on 22 Mar 2024.
//
#include <string.h>

#include "file_element.h"
#include "unity.h"
#include "unity_test_module.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void file_element_setUp(void)
{
    // This is run before EACH test
}

void file_element_tearDown(void)
{
    // This is run after EACH test
}

void test_EmptyTest_file(void)
{
    TEST_ASSERT_EQUAL(1, 0);
}

void run_file_element_tests()
{
    UnityRegisterSetupTearDown( file_element_setUp, file_element_tearDown);

    MY_RUN_TEST(test_EmptyTest_file);

    UnityUnregisterSetupTearDown();
}
