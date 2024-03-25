//
// Created by Lynn Tedje Anna Meindertsma on 06 Mar 2024.
//
#ifndef SIMPLE_DATE_H
#define SIMPLE_DATE_H
#include <iostream>

class Simple_Date{
public:

    // default and copy constructor
    Simple_Date() = default;
    Simple_Date& operator=(Simple_Date const& data) = default;

    // Constructor
    Simple_Date(uint8_t day, uint8_t month, uint16_t year);

    // Getters for day, month, and year.
    uint8_t get_day();
    uint8_t get_month();
    uint16_t get_year();
    bool is_valid();

    // Convert the SimpleDate to a string representation.
    std::string to_string();

private:
    uint8_t day = 0;
    uint8_t month = 0;
    uint16_t year = 0;
};


#endif //SIMPLE_DATE_H