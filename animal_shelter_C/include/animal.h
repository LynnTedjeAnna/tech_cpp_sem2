//
// Created by Lynn Tedje Anna Meindertsma on 17 Mar 2024.
//

#ifndef ANIMAL_H
#define ANIMAL_H

typedef enum
{
    Cat = 0,
    Dog,
    guienea_pig,
    Parrot
} Species;

typedef enum
{
    Male = 0,
    Female
} Sex;

typedef struct
{
    int Day;
    int Month;
    int Year;
} Date;

#define MaxNameLength 25
#define MaxLocationLength 100

typedef struct
{
    int     Id;
    Species Species;
    Sex     Sex;
    int     Age;
    Date    DateFound;
} Animal;

#endif //ANIMAL_H
