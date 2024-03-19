//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//
#include "administration.h"

int add_animal(
            const Animal* animal_ptr, Animal* animal_array,
            size_t animal_array_length, size_t number_of_animals_present,
            size_t* new_number_of_animals_present){
    // Check if there is space in the animal_array
    if(animal_array_length <= number_of_animals_present) {
        fprintf(stderr, "Error: Animal array is full\n");
        return -1;
    }
    //Copy the new Animal structure to the next available position in the animal_array.
    animal_array[number_of_animals_present] = *animal_ptr;
    //Increment the number_of_animals_present.
    number_of_animals_present ++;
    //Update the pointer value for the number of animals present.
    *new_number_of_animals_present = number_of_animals_present;
    return 0;
}

/*
It should take parameters such as the animal ID to be removed, the array of animals,
the number of animals present, and possibly other necessary parameters.

Remove the animal from the array. This typically involves shifting
all subsequent elements in the array to fill the gap left by the removed animal.
*/
int rmv_animal(
            int animal_id, Animal* animal_array,
            size_t number_of_animals_present,
            size_t* new_number_of_animals_present){
    //Iterate through the array of animals to find the animal with the specified ID
    int index;
    for (int i = 0; i < number_of_animals_present; ++i) {
        //Find the animal in the array
        if (animal_array[i] == animal_id) {
            index = i;
            break;
        }
    }
    //Remove the animal from the array
    
    //Update the count of animals present if
    number_of_animals_present --;
    //Update the pointer value for the number of animals present.
    *new_number_of_animals_present = number_of_animals_present;

    return 0;
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
