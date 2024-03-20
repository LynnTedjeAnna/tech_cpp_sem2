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

typedef bool (animal_compare)(Animal* A, Animal* B);

static void sort_animals(Animal* animal_array, size_t number_of_animals_present, animal_compare compare){
    Animal temp;
    // Iterate through each animal in the array
    for(int i = 0; i < number_of_animals_present; i++) {
        // Compare each animal's ... with the age of subsequent animals
        for(int j = i + 1; j < number_of_animals_present; j++) {
            // If the ... of the current animal is greater than the ... of the next animal, swap them
            if(compare(&animal_array[i], &animal_array[j])) {
                temp = animal_array[i];
                animal_array[i] = animal_array[j];
                animal_array[j] = temp;
            }
        }
    }
}

bool compare_animals_by_age(Animal* A, Animal* B) {
    return A->Age > B->Age;    //arrows are pointer to a more specific data piece, in animal (animal -> Age)
}
bool compare_animals_by_date_found(Animal* A, Animal* B) {
    return A->DateFound.Year > B->DateFound.Year;    //arrows are pointer to a more specific data piece, in animal (animal -> DateFound)
}
bool compare_animals_by_sex(Animal* A, Animal* B) {
    return A->Sex < B->Sex;    //arrows are pointer to a more specific data piece, in animal (animal -> Sex)
}

// Function to sort animals in the animal_array by their ages in ascending order
int sort_animals_by_age(Animal* animal_array, size_t number_of_animals_present) {
    sort_animals(animal_array, number_of_animals_present, compare_animals_by_age);
    // Print the sorted array of animals (for debugging or verification purposes)
    printf("After Sorting:\n");
    for(int i = 0; i < number_of_animals_present; i++) {
        printf("%d ", animal_array[i].Age);
    }
    return 0; // Return 0 indicating successful sorting
}

// Function to sort animals in the animal_array by their year found in ascending order
int sort_animals_by_year_found(Animal* animal_array, size_t number_of_animals_present) {
    sort_animals(animal_array, number_of_animals_present, compare_animals_by_date_found);
    // Print the sorted array of animals (for debugging or verification purposes)
    printf("After Sorting:\n");
    for(int i = 0; i < number_of_animals_present; i++) {
        printf("%d ", animal_array[i].DateFound.Year);
    }
    return 0; // Return 0 indicating successful sorting
}

// Function to sort animals in the animal_array by their sex in female first
//female = 0 male = 1
int sort_animals_by_sex(Animal* animal_array, size_t number_of_animals_present){
    sort_animals(animal_array, number_of_animals_present, compare_animals_by_sex);

    // Print the sorted array of animals (for debugging or verification purposes)
    printf("After Sorting:\n");
    for(int i = 0; i < number_of_animals_present; i++) {
        printf("%d ", animal_array[i].Sex);
    }
    return 0; // Return 0 indicating successful sorting}
}
