//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//
#include "administration.h"

int add_animal(
            const Animal* animal_ptr, Animal* animal_array,
            size_t animal_array_length, size_t number_of_animals_present,
            size_t* new_number_of_animals_present){
    return -1;
}

int rmv_animal(
            int animal_id, Animal* animal_array,
            size_t number_of_animals_present,
            size_t* new_number_of_animals_present){
    return -1;
}

int find_animal_by_id(
            int animal_id, const Animal* animal_array,
            size_t number_of_animals_present, Animal* animal_ptr){
    return -1;
}

/*-------------------------------------------------------------------------------*/
int sort_animals_by_age(Animal* animal_array, size_t number_of_animals_present){
    return 0;
}

int sort_animals_by_year_found(
            Animal* animal_array, size_t number_of_animals_present){
    return 0;
}

int sort_animals_by_sex(Animal* animal_array, size_t number_of_animals_present){
    return 0;
}
