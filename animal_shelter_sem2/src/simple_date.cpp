//
// Created by Lynn Tedje Anna Meindertsma on 06 Mar 2024.
//
#include <iostream>
#include "simple_data.hpp"
/// <summary>
/// A simple class to store dates.
/// This class is called SimpleDate because it's a simplyfied version of
/// the .Net DateTime object. SimpleDate hides the more complex interface of DateTime
/// and makes it easy to work with dates only.

// Constructor implementation.
Simple_date::Simple_date(int day, int month, int year)
    : day(day), month(month), year(year)

// Getter implementations.
int Simple_date::get_day() const
{
    return day;
}

int Simple_date::get_month() const
{
    return month;
}

int Simple_date::get_year() const
{
    return year;
}

// ToString method implementation.
std::string Simple_date::to_string() const
{
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}
