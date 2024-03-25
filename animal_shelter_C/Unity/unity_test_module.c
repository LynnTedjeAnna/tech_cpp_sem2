//
// Created by Lynn Tedje Anna Meindertsma on 22 Mar 2024.
//
#include "unity_test_module.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "unity.h"

void (*unity_setUp_ptr)(void) = NULL;
void (*unit_tearDown_ptr)(void) = NULL;

#ifdef UNITY_USE_MODULE_SETUP_TEARDOWN

void setUp()
{
    if(unity_setUp_ptr != NULL) unity_setUp_ptr();
}

void tearDown()
{
    if(unit_tearDown_ptr != NULL) unit_tearDown_ptr();
}

#endif

void UnityRegisterSetupTearDown( void(*setUp)(void), void(*tearDown)(void) )
{
    unity_setUp_ptr = setUp;
    unit_tearDown_ptr = tearDown;
}

void UnityUnregisterSetupTearDown(void)
{
    unity_setUp_ptr = NULL;
    unit_tearDown_ptr = NULL;
}

UnityTestModule* UnityTestModuleFind(
                        UnityTestModule* modules,
                        size_t number_of_modules,
                        char* wantedModule)
{
    for(size_t i = 0; i < number_of_modules; i++) {
        if(strcmp(wantedModule, modules[i].name) == 0) {
            return &modules[i];
        }
    }

    return NULL;
}

void UnityTestModuleRunRequestedModules(
  int number_of_requested_modules,
  char* requested_modules_names[],
  UnityTestModule* allModules,
  size_t number_of_modules )
{
    for(int i = 0; i < number_of_requested_modules; i++)
    {
        UnityTestModule* module = UnityTestModuleFind(allModules,
          number_of_modules, requested_modules_names[i]);

        if(module != NULL)
        {
            module->run_tests();
        }
        else
        {
            printf("Ignoring: could not find requested module: %s\n",
            requested_modules_names[i]);
        }
    }
}

int UnityTestModuleRun(
                   int argc,
                   char * argv[],
                   UnityTestModule* allModules,
                   size_t number_of_modules)
{
    UnityBegin();

    bool moduleRequests = (argc > 1);

    if(moduleRequests)
    {
        UnityTestModuleRunRequestedModules(argc-1, &argv[1],
          allModules, number_of_modules);
    }
    else
    {
        for(int i = 0; i < number_of_modules; i++)
        {
            allModules[i].run_tests();
        }
    }

    return UnityEnd();
}
