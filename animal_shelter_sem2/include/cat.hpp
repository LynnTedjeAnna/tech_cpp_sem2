//
// Created by Lynn Tedje Anna Meindertsma on 05/03/2024.
//

#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "animal.hpp"

class Cat : public Animal {
public:
    std::string bad_habits;

    Cat(uint64_t tag_ID, Date date, std::string name, std::string bad_habits) {
        // TODO
    }

    std::string to_string() {
        // TODO
        return "";
    }
private:
    std::string name;
};

#endif //CAT_HPP