//
// Created by Lynn Tedje Anna Meindertsma on 05 Mar 2024.
//
#include "administrationForm.hpp"
#include "animal.hpp"
#include <iostream>

// Constructor implementation
AdministrationForm::AdministrationForm() : animal(nullptr) {
    // Initialize any necessary variables or settings here
}

// Method to create an animal object implementation
void AdministrationForm::createAnimal() {
    // Get user input for animal type
    std::string animalType;
    std::cout << "Enter animal type (Dog/Cat): ";
    std::cin >> animalType;

    //todo: finish create animal
    //todo: niet string maar nummer
    //todo: error unknown type name dog and cat
    // Create animal object based on user input
    if (animalType == "Dog") {
        // Get user input for dog properties
        uint64_t chipRegistrationNumber; Simple_Date dateOfBirth; std::string name; Simple_Date lastWalkDate;
        // Create Dog object
        animal = new Dog(chipRegistrationNumber, dateOfBirth, name, lastWalkDate);
        std::cout << "Dog created." << std::endl;
    } else if (animalType == "Cat") {
        // Get user input for cat properties
        uint64_t chipRegistrationNumber; Simple_Date dateOfBirth; std::string name; std::string badHabits;
        // Create Cat object
        animal = new Cat(chipRegistrationNumber, dateOfBirth, name, badHabits);
        std::cout << "Cat created." << std::endl;
    } else {
        std::cout << "Invalid animal type." << std::endl;
    }
}

// Method to show information of the animal implementation
void AdministrationForm::showInfo() {
    // Check if animal object is created
    if (animal != nullptr) {
        // Print information of the animal
        std::cout << animal->to_string() << std::endl;
    } else {
        std::cout << "No animal created yet." << std::endl;
    }
}
