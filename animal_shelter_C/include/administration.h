//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//

#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H
#include <stddef.h>

#include "animal.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* pre    : animal_array_length must be greater than number_of_animals_present
 * post   : animal_array is updated with the information from animal_ptr, the
 * updated number of animals is passed in new_number_of_animals_present returns: 0
 * on success or -1 if an error occurs
 */
int add_animal(
            const Animal* animal_ptr, Animal* animal_array,
            size_t animal_array_length, size_t number_of_animals_present,
            size_t* new_number_of_animals_present);

/* pre    :
 * post   : All animals with id 'animal_id' are removed from AnimalArray, the
 * updated number of animals is passed in new_number_of_animals_present returns: The
 * number of removed animals, 0 if no animals removed or -1 if an error occurs
 */
int rmv_animal(
            int animal_id, Animal* animal_array,
            size_t number_of_animals_present,
            size_t* new_number_of_animals_present);

/* pre    :
 * post   : The first animal from animal_array with id 'animal_id' is copied into
 * animal_ptr returns: 1 on success, 0 if not found or -1 if an error occurs
 */
int find_animal_by_id(
            int animal_id, const Animal* animal_array,
            size_t number_of_animals_present, Animal* animal_ptr);

/* pre    :
 * post   : All animals in animal_array are sorted by age
 * returns: 0 on success or -1 if an error occurs
 */
int sort_animals_by_age(Animal* animal_array, size_t number_of_animals_present);

/* pre    :
 * post   : All animals in animal_array are sorted by the year in which they were
 * found returns: 0 on success or -1 if an error occurs
 */
int sort_animals_by_year_found(
            Animal* animal_array, size_t number_of_animals_present);

/* pre    :
 * post   : All animals in animal_array are sorted: first female animals and then
 * male animals returns: 0 on success or -1 if an error occurs
 */
int sort_animals_by_sex(Animal* animal_array, size_t number_of_animals_present);

#endif //ADMINISTRATION_H
