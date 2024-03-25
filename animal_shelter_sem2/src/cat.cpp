//
// Created by Lynn Tedje Anna Meindertsma on 05/03/2024.
//

#include "cat.hpp"

// TODO: Modify the constructor. Make sure it initializes all properties of the class.
// Constructor
Cat::Cat(uint64_t tag_ID, Simple_Date date, std::string name, std::string bad_habits)
    : Animal(tag_ID, date, name), bad_habits(bad_habits) {}

// Getter method for bad habits
std::string Cat::get_bad_habits() const {
    return this->bad_habits;
}

// Override method to retrieve information about the cat

/// <summary>
/// Retrieve information about this cat
///
/// Note: Every class inherits (automagically) from the 'Object' class,
/// which contains the virtual ToString() method which you can override.
/// </summary>
/// <returns>A string containing the information of this animal.
///          The format of the returned string is
///          "Cat: <ChipRegistrationNumber>, <DateOfBirth>, <Name>, <IsReserved>, <BadHabits>"
///          Where: IsReserved will be "reserved" if reserved or "not reserved" otherwise.
///                 BadHabits will be "none" if the cat has no bad habits, or the bad habits string otherwise.
/// </returns>
std::string Cat::to_string() {
    std::string is_reserved_string = this->get_reserved() ? "reserved" : "not reserved";
    std::string bad_habits_string = this->bad_habits.empty() ? "none" : this->bad_habits;
    return "Cat: " + std::to_string(this->get_chip_reg_number()) + ", " +
           this->get_date_of_birth().to_string() + ", " +
           this->get_name() + ", " +
           is_reserved_string + ", " +
           bad_habits_string;
}
// TODO: Put your own code here to make the method return the string specified in the method description.
