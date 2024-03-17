#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "administration.h"
#include "animal.h"
#include "file_element.h"
#include "terminal_io.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

const char* filename = "testFile";

static void addAnimalToAdministration(
            Animal* animals, size_t arrayLength,
            size_t* nrAnimalsPresent)
{
    // this function does not test the validity of input parameters as it is
    // a static function (equivalent to private in a C# class). Please do not
    // confuse this use of static with a static method in C#!
    Animal animal = { 1, 0, 0, 0, { 0, 0, 0 } };

    animal.Id = getInt("enter animal Id: ");
    animal.Species = getSpecies();
    animal.Sex = getSex();
    animal.Age = getInt("enter age: ");
    animal.DateFound = getDate("enter found date:\n");

    int result = addAnimal(&animal, animals, arrayLength, *nrAnimalsPresent,
                           nrAnimalsPresent);
    printf("\nAdd animal result: %s\n", result == 0 ? "success" : "fail");
}

static void
removeAnimalFromAdministration(Animal* animals, size_t* nrAnimals)
{
    int animalId = getInt("enter animal id: ");

    int result = removeAnimal(animalId, animals, *nrAnimals, nrAnimals);
    printf("%d animals removed (-1 is error)\n", result);
}

static void findAndPrintAnimal(const Animal* animals, size_t nrAnimals)
{
    Animal animal = { 1, 0, 0, 0, { 0, 0, 0 } };

    int animalId = getInt("enter animal id: ");

    int result = findAnimalById(animalId, animals, nrAnimals, &animal);
    if (result == 1)
    {
        printAnimals(&animal, 1);
    }
    else if (result == 0)
    {
        printf("Find animal result: animalId %d not found\n", animalId);
    }
    else
    {
        printf("Find animal result: fail\n");
    }
}

static void addTestData(Animal* animals, size_t* nrAnimals)
{
    Animal a1 = { 1, Dog, Male, 12, { 1, 2, 3 } };
    Animal a2 = { 2, Cat, Female, 4, { 4, 3, 2 } };
    Animal a3 = { 3, Parrot, Male, 40, { 8, 9, 10 } };
    Animal a4 = { 4, Dog, Female, 1, { 1, 1, 100 } };
    Animal a5 = { 5, GuineaPig, Male, 3, { 3, 4, 1 } };

    animals[(*nrAnimals)++] = a1;
    animals[(*nrAnimals)++] = a2;
    animals[(*nrAnimals)++] = a3;
    animals[(*nrAnimals)++] = a4;
    animals[(*nrAnimals)++] = a5;
}

int main(int argc, char* argv[])
{
    const size_t MaxNrAnimals = 20;
    // char filename[MAX_STRLEN] = "";
    Animal animals[MaxNrAnimals];
    size_t nrAnimals = 0;
    MenuOptions choice = MO_SHOW_ANIMALS;

    addTestData(animals, &nrAnimals);

    printf("PRC assignment 'Animal Shelter'\n"
           "-------------------------------------------");

    if (argc != 1)
    {
        fprintf(stderr, "%s: argc=%d\n", argv[0], argc);
    }

    while (choice != MO_QUIT)
    {
        printf("\n\nMENU\n====\n\n");
        choice = getMenuChoice();

        switch (choice)
        {
        // case MO_SelectFile:
        //     getStr("enter administration filename: ", filename, MAX_STRLEN);
        //     break;
        case MO_SHOW_ANIMALS:
            printAnimals(animals, nrAnimals);
            break;
        case MO_ADD_ANIMAL:
            addAnimalToAdministration(animals, MaxNrAnimals, &nrAnimals);
            break;
        case MO_REMOVE_ANIMAL:
            removeAnimalFromAdministration(animals, &nrAnimals);
            break;
        case MO_SORT_ANIMALS_BY_AGE:
        {
            int result = sortAnimalsByAge(animals, nrAnimals);
            printf("Sort animal by age result: %s\n",
                   result == 0 ? "success" : "fail");
        }
        break;
        case MO_SORT_ANIMALS_BY_YEAR_FOUND:
        {
            int result = sortAnimalsByYearFound(animals, nrAnimals);
            printf("Sort animal by year found result: %s\n",
                   result == 0 ? "success" : "fail");
        }
        break;
        case MO_SORT_ANIMALS_BY_SEX:
        {
            int result = sortAnimalsBySex(animals, nrAnimals);
            printf("Sort animal by sex result: %s\n",
                   result == 0 ? "success" : "fail");
        }
        break;
        case MO_FIND_ANIMAL:
            findAndPrintAnimal(animals, nrAnimals);
            break;
        case MO_SAVE:
        {
            int result = writeAnimals(filename, animals, nrAnimals);
            printf("Save animals to file result %s\n",
                   result == 0 ? "success" : "fail");
        }
        break;
        case MO_LOAD:
        {
            int result = getNrAnimalsInFile(filename, &nrAnimals);
            if (result != -1)
            {
                nrAnimals = readAnimals(filename, animals, nrAnimals);
            }
            printf("Load animals from file result %s\n",
                   result != -1 ? "succes" : "fail");
        }
        break;
        case MO_QUIT:
            // nothing to do here
            break;
        default:
            printf("ERROR: invalid choice: %d\n", choice);
            break;
        }
    }
    return 0;
}
