//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//

#ifndef TERMINAL_IO_H
#define TERMINAL_IO_H

#include "animal.h"

typedef enum
{
    MO_SHOW_ANIMALS,
    MO_ADD_ANIMAL,
    MO_REMOVE_ANIMAL,
    MO_SORT_ANIMALS_BY_AGE,
    MO_SORT_ANIMALS_BY_YEAR_FOUND,
    MO_SORT_ANIMALS_BY_SEX,
    MO_FIND_ANIMAL,
    MO_LOAD,
    MO_SAVE,
    MO_QUIT
} MenuOptions;


int getInt(const char* message);
int getLimitedInt(const char* message, const char* items[], int nrItems);
Species getSpecies(void);
Sex getSex(void);
MenuOptions getMenuChoice(void);
Date getDate(const char* message);
void getStr(const char* message, char* str, int maxLength);
void printAnimals(const Animal* animals, int nrAnimals);


#endif //TERMINAL_IO_H
