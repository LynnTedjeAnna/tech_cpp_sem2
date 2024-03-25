//
// Created by Lynn Tedje Anna Meindertsma on 05/03/2024.
//

#include "dog.hpp"

// TODO: Modify the constructor. Make sure it initializes all properties of the class.

// Constructor definition
Dog::Dog(uint64_t chip_registration_number, Simple_Date date_of_birth,
         std::string name, Simple_Date last_walk_date)
    : Animal(chip_registration_number, date_of_birth, name), last_walk_date(last_walk_date) {}

// Getter method for last walk date
Simple_Date Dog::get_last_walk_date() const {
    return this->last_walk_date;
}

// Override method to retrieve information about the dog

/// <summary>
/// Retrieve information about this dog
///
/// Note: Every class inherits (automagically) from the 'Object' class,
/// which contains the virtual ToString() method which you can override.
/// </summary>
/// <returns>A string containing the information of this animal.
///          The format of the returned string is
///          "Dog: <ChipRegistrationNumber>, <DateOfBirth>, <Name>, <IsReserved>, <LastWalkDate>"
///          Where: IsReserved will be "reserved" if reserved or "not reserved" otherwise.
///                 LastWalkDate will be "unknown" if unknown or the date of the last doggywalk otherwise.
/// </returns>
std::string Dog::to_string() {
    std::string is_reserved_string = this->get_reserved() ? "reserved" : "not reserved";
    std::string last_walk_date_string = this->last_walk_date.is_valid() ? this->last_walk_date.to_string() : "unknown";
    return "Dog: " + std::to_string(this->get_chip_reg_number()) + ", " +
           this->get_date_of_birth().to_string() + ", " +
           this->get_name() + ", " +
           is_reserved_string + ", " +
           last_walk_date_string;
}
// TODO: Put your own code here to make the method return the string specified in the method description.