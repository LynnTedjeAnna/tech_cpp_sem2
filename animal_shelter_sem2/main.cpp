#include <iostream>

#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "shelter.hpp"
#include "administrationForm.hpp"
int main()
{
    Cat cat(0,Simple_Date(1, 1, 1), " ", "ycgcghgjhvj");
    Dog dog(0,Simple_Date(1, 1, 1), " ", Simple_Date(2, 1, 1));

    std::cout << cat.to_string() << "\n";
    std::cout << dog.to_string() << "\n";

    // Create an instance of the AdministrationForm
    AdministrationForm administrationForm;

    // Run the console application loop
    int choice;
    do {
        std::cout << "Menu:\n1. Create Animal\n2. Show Animal Info\n3. Exit\nEnter choice: ";
        std::cin >> choice;


        //todo: says it creates an animal (cat/dog) but doesnt show in option 2

        // Perform corresponding action based on user choice
        switch (choice) {
            case 1:
                administrationForm.createAnimal();
            break;
            case 2:
                administrationForm.showInfo();
            break;
            case 3:
                std::cout << "Exiting program." << std::endl;
            break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}

