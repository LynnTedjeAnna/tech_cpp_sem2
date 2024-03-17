//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//

#ifndef FILE_ELEMENT_H
#define FILE_ELEMENT_H

#include <stddef.h>

#include "animal.h"

int read_animals(const char* filename, Animal* animal_ptr, size_t nr_animals);
/* pre    : n.a.
 * post   : If file contains enough Animals, nr_animals Animals are read into
 *          animal_ptr. If less animals than nr_animals exist, all animals from
 *          the file are read into animal_ptr.
 * returns: Nr of animals written into animal_ptr or -1 if an error occurs
 */

int write_animals(const char* filename, const Animal* animal_ptr, size_t nr_animals);
/* pre    : n.a.
 * post   : nr_animals animals are written into a new file with data from
 *          animal_ptr
 * returns: On succes: 0, on error (file could not be written, input pointers
 *          are NULL): -1
 */

int get_nr_animal_in_file(const char* filename, size_t* nr_animals);
/* pre    : n.a.
 * post   : get number of animals (Animal structures) in the file
 * returns: on succes: 0, on error: -1
 *
 */


int readAnimalFromFile(
            const char* filename, size_t file_position, Animal* animal_ptr);
/* pre    : n.a.
 * post   : read the animal on file_position (first animal is file_position 0,
 *          second animal is file_position 1, ...) into animal_ptr
 * returns: On success: 0, on error: -1 (no data available on file_position,
 *          file could not be read, ...)
 */

int writeAnimalToFile(
            const char* filename, size_t file_position, const Animal* animal_ptr);
/* pre    :
 * post   : write the animal in animal_ptr to the file at position 'file_position'
 * returns: On success: 0, on error: -1
 *
 **** note: do not open the file in append mode (a or a+): in append mode you
 ****       ALWAYS write to the end of the file. You cannot open the file in
 ****       write mode either (w or w+), as this will truncate an existing file
 ****       to 0 bytes. You MUST open the file in "r+" mode (means: r+w) and if
 ****       that fails (could mean: file does not exist) retry in "w" mode.
 */

int renameAnimalInFile(
            const char* filename, size_t file_position, const char* animal_surname);
/* pre	   :
 * post    : change the animal name on the file_position in this way:
 *	         The new animal name will start with animal_surname, followed
 *           by a space and followed by the original animal name
 * Example : We have animal called "Max" on file_position and animal_surname
 *           "Verstappen". The new animal name will be "Verstappen Max".
 *           The renamed animal will be written back to the file.
 * returns : On success: 0, on error: -1
 */
#endif //FILE_ELEMENT_H
