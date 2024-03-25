//
// Created by Lynn Tedje Anna Meindertsma on 05 Mar 2024.
//

#ifndef ADMINISTRATIONFORM_HPP
#define ADMINISTRATIONFORM_HPP

#include "animal.hpp" // Include the Animal class header

class AdministrationForm {
private:
    Animal* animal;

public:
    // Constructor
    AdministrationForm();

    // Method to create an animal object
    void createAnimal();

    // Method to show information of the animal
    void showInfo();
};

#endif //ADMINISTRATIONFORM_HPP
