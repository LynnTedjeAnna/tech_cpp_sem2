//
// Created by Lynn Tedje Anna Meindertsma on 15 Mar 2024.
//
#ifndef CART_HPP
#define CART_HPP

#include <cstdlib>

#define S_HERBIVORE 0
#define S_CARNIVORE 1
#define M_HERBIVORE 2
#define M_CARNIVORE 3
#define B_HERBIVORE 4
#define B_CARNIVORE 5


#define S_VALUE 1
#define M_VALUE 3
#define B_VALUE 5
#define CAPACITY 10

class Cart {
public:
    // Constructor
    Cart();
    // Function to add an animal to the cart
    bool add_animal(uint8_t animal);

    // Friend function declaration to overload the << operator for Cart objects
    friend std::ostream& operator<<(std::ostream& os, const Cart& cart);

private:
    uint8_t s_herbivore_count = 0;
    uint8_t s_carnivore_count = 0;
    uint8_t m_herbivore_count = 0;
    uint8_t m_carnivore_count = 0;
    uint8_t b_herbivore_count = 0;
    uint8_t b_carnivore_count = 0;

    uint8_t capacity = CAPACITY;
    uint8_t danger_level = 0;
};
#endif //CART_HPP
