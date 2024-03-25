//
// Created by Lynn Tedje Anna Meindertsma on 22 Mar 2024.
//
#include <string.h>

#include "administration.h"
#include "unity.h"
#include "unity_test_module.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void administration_setUp(void) {
    // This is run before EACH test
}

void test_addAnimal_emptyArray() {
    Animal animal1 = {
        .Id = 1,
        .Age = 5,
        .Sex = 'M',
        .DateFound.Year = 2020,
        .DateFound.Month = 12,
        .DateFound.Day = 25
    };
    Animal animal_array[5];  // Array to hold animals
    size_t number_of_animals_present = 0;  // Initially, no animals present

    // Add animal1 to the empty array
    int result = add_animal(&animal1, animal_array, 5, number_of_animals_present, &number_of_animals_present);

    // Verify that the result is successful (0)
    if (result == 0 && number_of_animals_present == 1) {
        printf("Test Case 1 Passed: Animal added to an empty array successfully.\n");
    } else {
        printf("Test Case 1 Failed: Unable to add animal to an empty array.\n");
    }
}

void test_addAnimal_fullArray() {
    Animal animal1 = {
        .Id = 1,
        .Age = 5,
        .Sex = 'M',
        .DateFound.Year = 2020,
        .DateFound.Month = 12,
        .DateFound.Day = 25
    };
    Animal animal2 = {
        .Id = 2,
        .Age = 3,
        .Sex = 'F',
        .DateFound.Year = 2022,
        .DateFound.Month = 22,
        .DateFound.Day = 10
    };
    Animal animal_array[2];  // Array to hold animals
    size_t number_of_animals_present = 2;  // Array already full

    // Add animal1 to the full array
    int result = add_animal(&animal1, animal_array, 2, number_of_animals_present, &number_of_animals_present);

    // Verify that the result indicates failure (-1)
    if (result == -1 && number_of_animals_present == 2) {
        printf("Test Case 2 Passed: Unable to add animal to a full array.\n");
    } else {
        printf("Test Case 2 Failed: Animal added to a full array.\n");
    }
}

void administration_tearDown(void)
{
    // This is run after EACH test
}

void test_EmptyTest(void)
{
    TEST_ASSERT_EQUAL(1, 0);
}

void run_administration_tests()
{
    UnityRegisterSetupTearDown( administration_setUp, administration_tearDown);

    MY_RUN_TEST(test_EmptyTest);

    UnityUnregisterSetupTearDown();
}
