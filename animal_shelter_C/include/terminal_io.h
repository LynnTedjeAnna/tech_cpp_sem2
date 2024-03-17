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
} menu_options;


int get_int(const char* message);
int get_limited_int(const char* message, const char* items[], int nrItems);
Species get_species(void);
Sex get_sex(void);
menu_options get_menu_choice(void);
Date get_date(const char* message);
void getStr(const char* message, char* str, int max_length);
void print_animals(const Animal* animals, int nr_animals);


#endif //TERMINAL_IO_H
