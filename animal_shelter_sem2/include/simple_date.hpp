//
// Created by Lynn Tedje Anna Meindertsma on 06 Mar 2024.
//
#ifndef SIMPLE_DATE_H
#define SIMPLE_DATE_H
#include <iostream>

class Simple_date{
public:
    // Constructor
    Simple_date(int day, int month, int year);

    // Getters for day, month, and year.
    int get_day();
    int get_month();
    int get_year();

    // Convert the SimpleDate to a string representation.
    std::string to_string();

private:
    int day;
    int month;
    int year;
};


#endif //SIMPLE_DATE_H