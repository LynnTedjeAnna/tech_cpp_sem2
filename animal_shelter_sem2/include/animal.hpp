//
// Created by Lynn Tedje Anna Meindertsma on 05/03/2024.
//
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
private:
    int chip_registration_number;  // The chipnumber of the animal. Must be unique. Must be zero or greater than zero.
    SimpleDate date_of_birth;      // Date of birth of the animal.
    std::string name;              // The name of the animal.
    bool is_reserved;              // Is the animal reserved by a future owner, yes or no.

public:
    Animal(int chipRegistrationNumber, SimpleDate dateOfBirth, std::string name);

    int get_chip_reg_nbr() const;
    SimpleDate get_date_of_birth() const;
    std::string get_name() const;
    bool get_is_reserved() const;

    void set_is_reserved(bool is_reserved);

    std::string to_string() const;  // Retrieve information about this animal
};

#endif //ANIMAL_HPP