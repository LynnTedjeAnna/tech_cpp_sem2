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

int rmv_animal(
            int animal_id, Animal* animal_array,
            size_t number_of_animals_present,
            size_t* new_number_of_animals_present){
    //Iterate through the array of animals to find the animal with the specified ID
    int index = -1;
    for (int i = 0; i < number_of_animals_present; ++i) {
        //Find the animal in the array
        if (animal_array[i].Id == animal_id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return -1;
    }
    // Copy next element value to current element en remove the animal from the array consequently
    for(int i = index; i < number_of_animals_present; i++)
    {
        animal_array[i] = animal_array[i + 1];
    }
    //Update the count of animals present if
    number_of_animals_present --;
    //Update the pointer value for the number of animals present.
    *new_number_of_animals_present = number_of_animals_present;

    return 0;
}

int find_animal_by_id(
            int animal_id, const Animal* animal_array,
            size_t number_of_animals_present, Animal* animal_ptr){
    //Iterate through the array of animals to find the animal with the specified ID.
    for(int i = 0; i < number_of_animals_present; i++) {
        //If the animal is found, copy its data into the provided Animal structure pointer.
        if (animal_array[i].Id == animal_id) {
            *animal_ptr = animal_array[i];
            return 0;
        }
    }
    //Return a value indicating that the animal was not found
    return -1;
}

/*-------------------------------------------------------------------------------*/
/*
*For sorting animals by age: Define a comparison function that compares the ages of two animals.
*For sorting animals by year found: Define a comparison function that compares the years in which two animals were found.
*For sorting animals by sex: Define a comparison function that compares the sexes of two animals.
*
*Implement a generic sorting function that accepts a function pointer to the appropriate comparison function:
*Define a function that takes an array of animals, the number of animals, and a function pointer to the comparison function.
*Inside this function, use a sorting algorithm (e.g., bubble sort, insertion sort, or quicksort) to sort the array of animals based on the specified criterion.
*
*Call the generic sorting function for each sorting criterion:
*In your animal.c module, call the generic sorting function for each sorting criterion (sortAnimalsByAge, sortAnimalsByYearFound, and sortAnimalsBySex).
*Pass the appropriate comparison function as a function pointer to the generic sorting function for each sorting operation.
*
*Test each sorting function:
*After implementing each sorting function, ensure that they correctly sort the array of animals according to the specified criterion.
*Test the sorting functions with different arrays of animals and verify that the sorting results are as expected.
*/
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
