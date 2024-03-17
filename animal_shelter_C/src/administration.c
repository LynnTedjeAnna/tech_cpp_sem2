//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//
#include "administration.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// leave resource_detector.h as last include!
#include "resource_detector.h"

int addAnimal(
            const Animal* animalPtr, Animal* animalArray,
            size_t animalArrayLength, size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent)
{
    return -1;
}

int removeAnimal(
            int animalId, Animal* animalArray,
            size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent)
{
    return -1;
}

int findAnimalById(
            int animalId, const Animal* animalArray,
            size_t numberOfAnimalsPresent, Animal* animalPtr)
{
    return -1;
}

/*-------------------------------------------------------------------------------*/
int sortAnimalsByAge(Animal* animalArray, size_t numberOfAnimalsPresent)
{
    return 0;
}

int sortAnimalsByYearFound(
            Animal* animalArray, size_t numberOfAnimalsPresent)
{
    return 0;
}

int sortAnimalsBySex(Animal* animalArray, size_t numberOfAnimalsPresent)
{
    return 0;
}
