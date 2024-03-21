//
// Created by Lynn Tedje Anna Meindertsma on 05/03/2024.
//
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "simple_date.hpp"

class Animal {
public:
    Animal(uint32_t chip_reg_number, Simple_Date date_of_birth, std::string name);

    uint32_t get_chip_reg_number() const;
    Simple_Date get_date_of_birth() const;
    std::string get_name() const;
    bool get_reserved() const;

    std::string to_string();

private:
    uint32_t chip_reg_number;
    Simple_Date date_of_birth;
    std::string name;
    bool reserved = false;
};


#endif //ANIMAL_HPP