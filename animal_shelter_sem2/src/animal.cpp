//
// Created by Lynn Tedje Anna Meindertsma on 05/03/2024.
//
#include "animal.hpp"

// Constructor initializes the Animal object with provided values.
Animal::Animal(int chipRegistrationNumber, SimpleDate dateOfBirth, std::string name)
    : chip_registration_number(chipRegistrationNumber), date_of_birth(dateOfBirth), name(name), is_reserved(false)
{
}

// Getter method to retrieve the chip registration number of the animal.
int Animal::get_chip_registration_number() const
{
    return chip_registration_number;
}

// Getter method to retrieve the date of birth of the animal.
SimpleDate Animal::get_date_of_birth() const
{
    return date_of_birth;
}

// Getter method to retrieve the name of the animal.
std::string Animal::get_name() const
{
    return name;
}

// Getter method to check if the animal is reserved.
bool Animal::get_is_reserved() const
{
    return is_reserved;
}

// Setter method to update the reservation status of the animal.
void Animal::set_is_reserved(bool isReserved)
{
    is_reserved = isReserved;
}

// Method to convert the animal information to a string for display.
std::string Animal::to_string() const
{
    // Determine if the animal is reserved and create a string accordingly.
    std::string is_reserved_string = is_reserved ? "reserved" : "not reserved";

    // Format the information of this animal into a string.
    return std::to_string(chip_registration_number) + ", " + date_of_birth.to_string() +
           ", " + name + ", " + is_reserved_string;
}
