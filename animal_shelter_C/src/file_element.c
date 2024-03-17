//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//
#include "file_element.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

int read_animals(const char* filename, Animal* animal_ptr, size_t nr_animals)
{
    return -1;
}

int write_animals(const char* filename, const Animal* animal_ptr, size_t nr_animals)
{
    return -1;
}

int get_nr_animal_in_file(const char* filename, size_t* nr_animals)
{
    return -1;
}

int readAnimalFromFile(
            const char* filename, size_t file_position, Animal* animal_ptr)
{
    return -1;
}

int writeAnimalToFile(
            const char* filename, size_t file_position, const Animal* animal_ptr)
{
    return -1;
}

int renameAnimalInFile(
            const char* filename, size_t file_position, const char* animal_surname)
{
    return -1;
}
