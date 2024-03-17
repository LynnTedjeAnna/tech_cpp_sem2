//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//
#include <stdio.h>
#include <string.h>

#include "terminal_io.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

#define MAX_STRLEN 80

static const char* species_names[] = {
    "Cat", "Dog", "Guinea pig", "Parrot"
};
static const size_t nr_species_names = sizeof(species_names) / sizeof(species_names[0]);

static const char* sex_names[] = {
    "Male", "Female"
};
static const size_t nr_sex_names = sizeof(sex_names) / sizeof(sex_names[0]);

static const char* menu_strings[] = {
    "Show animals",
    "Add animal",
    "Remove animal",
    "Sort animals by age",
    "Sort animals by year found",
    "Sort animals by sex",
    "Find animal",
    "Load file from disk",
    "Save administration to disk",
    "Quit"
};
static const size_t nr_menu_strings =
            sizeof(menu_strings) / sizeof(menu_strings[0]);

int get_int(const char* message){
    char line[MAX_STRLEN];
    char* result = NULL;
    int value = -1;

    printf("%s", message);
    result = fgets(line, sizeof(line), stdin);
    if (result != NULL){
        sscanf(result, "%d", &value);
    }

    return value;
}

int get_limited_int(const char* message, const char* items[], int nrItems){
    int choice = -1;
    do{
        for (int i = 0; i < nrItems; i++){
            printf("  [%d] %s\n", i, items[i]);
        }
        choice = get_int(message);
    } while (choice < 0 || choice >= nrItems);

    return choice;
}

Species get_species(void)
{
    return (Species)get_limited_int("enter species: ", species_names, nr_species_names);
}

Sex get_sex(void)
{
    return (Sex)get_limited_int("enter sex: ", sex_names, nr_sex_names);
}

menu_options get_menu_choice(void)
{
    return (menu_options)get_limited_int("choice: ", menu_strings, nr_menu_strings);
}

Date get_date(const char* message)
{
    Date temp = { 0, 0, 0 };
    printf("%s", message);
    temp.Day = get_int("  enter day: ");
    temp.Month = get_int("  enter month: ");
    temp.Year = get_int("  enter year: ");
    return temp;
}

void getStr(const char* message, char* str, int max_length){
    char line[max_length];
    char* result = NULL;

    printf("%s", message);
    result = fgets(line, sizeof(line), stdin);
    if (result != NULL){
        if (result[strlen(result) - 1] == '\n')
        {
            result[strlen(result) - 1] = '\0';
        }
        strncpy(str, result, max_length);
    }
}

void print_animals(const Animal* animals, int nr_animals){
    if (animals != NULL){
        if (nr_animals <= 0){
            printf("\nAnimal array is empty, or nr_animals is less than 0\n\n");
        }else{
            for (int i = 0; i < nr_animals; i++){
                printf("\nAnimal %d:\n", i + 1);
                printf("Id:     %d\n", animals[i].Id);
                printf("Species:  %s\n", species_names[animals[i].Species]);
                printf("Sex:      %s\n", sex_names[animals[i].Sex]);
                printf("Age:      %d\n", animals[i].Age);
                printf("Animal was found:\n");
                printf("  at date:     %02d-%02d-%02d\n", animals[i].DateFound.Day, animals[i].DateFound.Month, animals[i].DateFound.Year);
            }
        }
    }
}
