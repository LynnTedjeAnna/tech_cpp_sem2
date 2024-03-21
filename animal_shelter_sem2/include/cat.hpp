//
// Created by Lynn Tedje Anna Meindertsma on 05/03/2024.
//

#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "animal.hpp"
#include "simple_date.hpp"


class Cat : public Animal {
public:
    //test
    Cat(uint64_t tag_ID, Simple_Date date, std::string name, std::string bad_habits) : Animal(tag_ID, date, name) {
        this->bad_habits = bad_habits;
    }

    std::string to_string() {
        // TODO
        return "";
    }
private:
    std::string bad_habits;
};

#endif //CAT_HPP