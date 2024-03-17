//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//
#include "file_element.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

int readAnimals(const char* filename, Animal* animalPtr, size_t nrAnimals)
{
    return -1;
}

int writeAnimals(const char* filename, const Animal* animalPtr, size_t nrAnimals)
{
    return -1;
}

int getNrAnimalsInFile(const char* filename, size_t* nrAnimals)
{
    return -1;
}

int readAnimalFromFile(
            const char* filename, size_t filePosition, Animal* animalPtr)
{
    return -1;
}

int writeAnimalToFile(
            const char* filename, size_t filePosition, const Animal* animalPtr)
{
    return -1;
}

int renameAnimalInFile(
            const char* filename, size_t filePosition, const char* animalSurname)
{
    return -1;
}
