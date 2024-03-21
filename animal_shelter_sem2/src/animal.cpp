//
// Created by Lynn Tedje Anna Meindertsma on 05/03/2024.
//
#include <iostream>
#include "animal.hpp"

/// <summary>
/// Creates an animal.
/// </summary>
/// <param name="chipRegistrationNumber">The chipnumber of the animal.
///                                      Must be unique. Must be zero or greater than zero.</param>
/// <param name="dateOfBirth">The date of birth of the animal.</param>
/// <param name="name">The name of the animal.</param>

//constructor
Animal::Animal(uint32_t chip_reg_number, Simple_Date date_of_birth, std::string name) {
    this->chip_reg_number = chip_reg_number;
    this->date_of_birth =   date_of_birth;
    this->name =            name;
    this->reserved =        false;
}

uint32_t Animal::get_chip_reg_number() const {
    return this->chip_reg_number;
}

Simple_Date Animal::get_date_of_birth() const {
    return this->date_of_birth;
}

std::string Animal::get_name() const {
    return this->name;
}

bool Animal::get_reserved() const {
    return this->reserved;
}

std::string Animal::to_string() {
    // TODO
    return "";
}

/// <summary>
/// Class representing an animal in the shelter.
