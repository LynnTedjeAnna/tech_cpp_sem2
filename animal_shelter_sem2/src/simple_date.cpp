//
// Created by Lynn Tedje Anna Meindertsma on 06 Mar 2024.
//
#include <iostream>
#include "simple_date.hpp"
/// <summary>
/// A simple class to store dates.
/// This class is called SimpleDate because it's a simplyfied version of
/// the .Net DateTime object. SimpleDate hides the more complex interface of DateTime
/// and makes it easy to work with dates only.

// Constructor implementation.
Simple_Date::Simple_Date(uint8_t day, uint8_t month, uint16_t year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

// Getter implementations.
uint8_t Simple_Date::get_day() {
    return day;
}

uint8_t Simple_Date::get_month() {
    return month;
}

uint16_t Simple_Date::get_year() {
    return year;
}

bool Simple_Date::is_valid() {
    return this->day && this->month && this->year;
}

// ToString method implementation.
std::string Simple_Date::to_string() {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}
