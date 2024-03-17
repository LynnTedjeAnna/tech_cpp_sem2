//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//

#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H
#include <stddef.h>

#include "animal.h"

/* pre    : animalArrayLength must be greater than numberOfAnimalsPresent
 * post   : animalArray is updated with the information from animalPtr, the
 * updated number of animals is passed in newNumberOfAnimalsPresent returns: 0
 * on success or -1 if an error occurs
 */
int addAnimal(
            const Animal* animalPtr, Animal* animalArray,
            size_t animalArrayLength, size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent);

/* pre    :
 * post   : All animals with id 'animalId' are removed from AnimalArray, the
 * updated number of animals is passed in newNumberOfAnimalsPresent returns: The
 * number of removed animals, 0 if no animals removed or -1 if an error occurs
 */
int removeAnimal(
            int animalId, Animal* animalArray,
            size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent);

/* pre    :
 * post   : The first animal from animalArray with id 'animalId' is copied into
 * animalPtr returns: 1 on success, 0 if not found or -1 if an error occurs
 */
int findAnimalById(
            int animalId, const Animal* animalArray,
            size_t numberOfAnimalsPresent, Animal* animalPtr);

/* pre    :
 * post   : All animals in animalArray are sorted by age
 * returns: 0 on success or -1 if an error occurs
 */
int sortAnimalsByAge(Animal* animalArray, size_t numberOfAnimalsPresent);

/* pre    :
 * post   : All animals in animalArray are sorted by the year in which they were
 * found returns: 0 on success or -1 if an error occurs
 */
int sortAnimalsByYearFound(
            Animal* animalArray, size_t numberOfAnimalsPresent);

/* pre    :
 * post   : All animals in animalArray are sorted: first female animals and then
 * male animals returns: 0 on success or -1 if an error occurs
 */
int sortAnimalsBySex(Animal* animalArray, size_t numberOfAnimalsPresent);

#endif //ADMINISTRATION_H
