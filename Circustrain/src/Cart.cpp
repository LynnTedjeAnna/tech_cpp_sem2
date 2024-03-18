#include <iostream>
#include "Cart.hpp"

//defines the default constructor for the Cart class
Cart::Cart() {}

bool Cart::add_animal(uint8_t animal) {
    // If animal is smaller than danger_level, it will not fit in the cart and will be filtered out
    if (animal < danger_level) {
        return false;
    }

    // If animal is uneven, it is a carnivore, and if there is a current carnivore in the cart,
    // it will be filtered out
    if (animal % 2) {
        if (danger_level != 0) {
            return false;
        }
        danger_level = animal;
    }

    //assign value of b/m/s to animal_value
    uint8_t animal_value;
    if (animal > 3) {
        //value 5
        animal_value = B_VALUE;
    }
    else if (animal > 1) {
        //value 3
        animal_value = M_VALUE;
    }
    else {
        //value 1
        animal_value = S_VALUE;
    }

    // If it is over capacity, animal cannot fit in cart and will be filtered out
    if (animal_value > capacity) {
        return false;
    }

    //new capacity value
    capacity -= animal_value;

    //add animlas to the cart
    switch (animal) {
        case S_HERBIVORE:
            s_herbivore_count++;
        break;
        case S_CARNIVORE:
            s_carnivore_count++;
        break;
        case M_HERBIVORE:
            m_herbivore_count++;
        break;
        case M_CARNIVORE:
            m_carnivore_count++;
        break;
        case B_HERBIVORE:
            b_herbivore_count++;
        break;
        case B_CARNIVORE:
            b_carnivore_count++;
        break;
    }
    return true;
}

// < ignore ( made by differnt student :) ) >
// Overloaded operator<< function definition for printing Cart objects
std::ostream& operator<<(std::ostream& os, Cart const& cart) {
    os << "sh: " << (uint16_t)cart.s_herbivore_count << ", ";
    os << "sc: " << (uint16_t)cart.s_carnivore_count << ", ";
    os << "mh: " << (uint16_t)cart.m_herbivore_count << ", ";
    os << "mc: " << (uint16_t)cart.m_carnivore_count << ", ";
    os << "bh: " << (uint16_t)cart.b_herbivore_count << ", ";
    os << "bc: " << (uint16_t)cart.b_carnivore_count << " || ";
    os << "cap: " << (uint16_t)cart.capacity << ", ";
    os << "dlvl: " << (uint16_t)cart.danger_level << "\n";
    return os;
}