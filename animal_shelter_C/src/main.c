#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "administration.h"
#include "animal.h"
#include "file_element.h"
#include "terminal_io.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

const char* filename = "testFile";

static void add_animal_admin( Animal* animals, size_t array_length, size_t* nr_animals_present){
    // this function does not test the validity of input parameters as it is
    // a static function (equivalent to private in a C# class). Please do not
    // confuse this use of static with a static method in C#!
    Animal animal = { 1, 0, 0, 0, { 0, 0, 0 } };

    animal.Id = get_int("enter animal Id: ");
    animal.Species = get_species();
    animal.Sex = get_sex();
    animal.Age = get_int("enter age: ");
    animal.DateFound = get_date("enter found date:\n");

    int result = add_animal(&animal, animals, array_length, *nr_animals_present,
                           nr_animals_present);
    printf("\nAdd animal result: %s\n", result == 0 ? "success" : "fail");
}

static void rmv_animal_admin(Animal* animals, size_t* nr_animals){
    int animal_id = get_int("enter animal id: ");

    int result = rmv_animal(animal_id, animals, *nr_animals, nr_animals);
    printf("removed animal with code: %d", result);
}

static void find_print_animal(const Animal* animals, size_t nr_animals){
    Animal animal = { 1, 0, 0, 0, { 0, 0, 0 } };

    int animal_id = get_int("enter animal id: ");

    int result = find_animal_by_id(animal_id, animals, nr_animals, &animal);
    if (result == 0){
        print_animals(&animal, 1);
    }else if (result == -1){
        printf("Find animal result: animal_id %d not found\n", animal_id);
    }else{
        printf("Find animal result: fail\n");
    }
}

static void add_test_data(Animal* animals, size_t* nr_animals){
    Animal a1 = { 1, Dog, Male, 12, { 1, 2, 3 } };
    Animal a2 = { 2, Cat, Female, 4, { 4, 3, 2 } };
    Animal a3 = { 3, Parrot, Male, 40, { 8, 9, 10 } };
    Animal a4 = { 4, Dog, Female, 1, { 1, 1, 100 } };
    Animal a5 = { 5, guienea_pig, Male, 3, { 3, 4, 1 } };

    animals[(*nr_animals)++] = a1;
    animals[(*nr_animals)++] = a2;
    animals[(*nr_animals)++] = a3;
    animals[(*nr_animals)++] = a4;
    animals[(*nr_animals)++] = a5;
}

int main(int argc, char* argv[]){
    const size_t max_nr_animals = 20;
    // char filename[MAX_STRLEN] = "";
    Animal animals[max_nr_animals];
    size_t nr_animals = 0;
    menu_options choice = MO_SHOW_ANIMALS;

    add_test_data(animals, &nr_animals);

    printf("PRC assignment 'Animal Shelter'\n"
           "-------------------------------------------");

    if (argc != 1){
        fprintf(stderr, "%s: argc=%d\n", argv[0], argc);
    }

    while (choice != MO_QUIT){
        printf("\n\nMENU\n====\n\n");
        choice = get_menu_choice();

        switch (choice){
        // case MO_SelectFile:
        //     getStr("enter administration filename: ", filename, MAX_STRLEN);
        //     break;
        case MO_SHOW_ANIMALS:
            print_animals(animals, nr_animals);
            break;

        case MO_ADD_ANIMAL:
            add_animal_admin(animals, max_nr_animals, &nr_animals);
            break;

        case MO_REMOVE_ANIMAL:
            rmv_animal_admin(animals, &nr_animals);
            break;

        case MO_SORT_ANIMALS_BY_AGE:{
            int result = sort_animals_by_age(animals, nr_animals);
            printf("Sort animal by age result: %s\n", result == 0 ? "success" : "fail");
        }
        break;

        case MO_SORT_ANIMALS_BY_YEAR_FOUND:{
            int result = sort_animals_by_year_found(animals, nr_animals);
            printf("Sort animal by year found result: %s\n", result == 0 ? "success" : "fail");
        }
        break;

        case MO_SORT_ANIMALS_BY_SEX:{
            int result = sort_animals_by_sex(animals, nr_animals);
            printf("Sort animal by sex result: %s\n",result == 0 ? "success" : "fail");
        }
        break;

        case MO_FIND_ANIMAL:
            find_print_animal(animals, nr_animals);
            break;

        case MO_SAVE:{
            int result = write_animals(filename, animals, nr_animals);
            printf("Save animals to file result %s\n", result == 0 ? "success" : "fail");
        }
        break;

        case MO_LOAD:{
            int result = get_nr_animal_in_file(filename, &nr_animals);
            if (result != -1){
                nr_animals = read_animals(filename, animals, nr_animals);
            }
            printf("Load animals from file result %s\n", result != -1 ? "succes" : "fail");
        }
        break;

        case MO_QUIT:
            // nothing to do here
            break;

        default:
            printf("ERROR: invalid choice: %d\n", choice);
            break;
        }
    }
    return 0;
}
