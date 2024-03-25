//
// Created by Lynn Tedje Anna Meindertsma on 22 Mar 2024.
//
#include "unity_test_module.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

/* As an alternative for header files we can declare that
 * the following methos are available 'extern'ally.
 */
extern void run_administration_tests();
extern void run_file_element_tests();

int main (int argc, char * argv[])
{
    UnityTestModule allModules[] = { { "administration", run_administration_tests},
                                     { "file_element", run_file_element_tests}
    };

    size_t number_of_modules = sizeof(allModules)/sizeof(allModules[0]);
    return UnityTestModuleRun(argc, argv, allModules, number_of_modules);
}
