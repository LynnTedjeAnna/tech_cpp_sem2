//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//

#ifndef FILE_ELEMENT_H
#define FILE_ELEMENT_H

#include <stddef.h>

#include "animal.h"

int readAnimals(const char* filename, Animal* animalPtr, size_t nrAnimals);
/* pre    : n.a.
 * post   : If file contains enough Animals, nrAnimals Animals are read into
 *          animalPtr. If less animals than nrAnimals exist, all animals from
 *          the file are read into animalPtr.
 * returns: Nr of animals written into animalPtr or -1 if an error occurs
 */

int writeAnimals(const char* filename, const Animal* animalPtr, size_t nrAnimals);
/* pre    : n.a.
 * post   : nrAnimals animals are written into a new file with data from
 *          animalPtr
 * returns: On succes: 0, on error (file could not be written, input pointers
 *          are NULL): -1
 */

int getNrAnimalsInFile(const char* filename, size_t* nrAnimals);
/* pre    : n.a.
 * post   : get number of animals (Animal structures) in the file
 * returns: on succes: 0, on error: -1
 *
 */


int readAnimalFromFile(
            const char* filename, size_t filePosition, Animal* animalPtr);
/* pre    : n.a.
 * post   : read the animal on filePosition (first animal is filePosition 0,
 *          second animal is filePosition 1, ...) into animalPtr
 * returns: On success: 0, on error: -1 (no data available on filePosition,
 *          file could not be read, ...)
 */

int writeAnimalToFile(
            const char* filename, size_t filePosition, const Animal* animalPtr);
/* pre    :
 * post   : write the animal in animalPtr to the file at position 'filePosition'
 * returns: On success: 0, on error: -1
 *
 **** note: do not open the file in append mode (a or a+): in append mode you
 ****       ALWAYS write to the end of the file. You cannot open the file in
 ****       write mode either (w or w+), as this will truncate an existing file
 ****       to 0 bytes. You MUST open the file in "r+" mode (means: r+w) and if
 ****       that fails (could mean: file does not exist) retry in "w" mode.
 */

int renameAnimalInFile(
            const char* filename, size_t filePosition, const char* animalSurname);
/* pre	   :
 * post    : change the animal name on the filePosition in this way:
 *	         The new animal name will start with animalSurname, followed
 *           by a space and followed by the original animal name
 * Example : We have animal called "Max" on filePosition and animalSurname
 *           "Verstappen". The new animal name will be "Verstappen Max".
 *           The renamed animal will be written back to the file.
 * returns : On success: 0, on error: -1
 */
#endif //FILE_ELEMENT_H
