//
// Created by Lynn Tedje Anna Meindertsma on 22 Mar 2024.
//

#ifndef UNITY_TEST_MODULE_H
#define UNITY_TEST_MODULE_H

#include <stddef.h>

typedef struct {
    char name[24];
    void(*run_tests)(void);
} UnityTestModule;

void UnityRegisterSetupTearDown( void(*setUp)(void), void(*tearDown)(void) );
void UnityUnregisterSetupTearDown(void);

UnityTestModule* UnityTestModuleFind(
  UnityTestModule* modules,
  size_t number_of_modules,
  char* wantedModule);

void UnityTestModuleRunRequestedModules(
  int number_of_requested_modules,
  char* requested_modules_names[],
  UnityTestModule* allModules,
  size_t number_of_modules );

int  UnityTestModuleRun(
  int argc,
  char * argv[],
  UnityTestModule* allModules,
  size_t number_of_modules);

#endif //UNITY_TEST_MODULE_H
