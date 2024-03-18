//
// Created by Lynn Tedje Anna Meindertsma on 15 Mar 2024.
//
#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <vector>
#include "Cart.hpp"
#include <iostream>

class Train {
public:
    // Constructor
    Train();
    // Function to fit animals into carts
    void fit_animals(int animals[6]);

    // Getter function to retrieve carts
    int get_length(); // Returns a constant reference to the carts vector

    // Friend function declaration to overload the << operator for Cart objects
    friend std::ostream& operator<<(std::ostream& os, const Train& train);

private:
    std::vector<Cart> carts;                    // Vector to store Cart objects
};
#endif // TRAIN_HPP