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
    Train(uint64_t animals[6]);
    // Function to fit animals into carts
    void fit_animals(uint64_t animals[6]);

    // Getter function to retrieve carts
    const std::vector<Cart>& get_carts() const; // Returns a constant reference to the carts vector

private:
    std::vector<Cart> carts;                    // Vector to store Cart objects
};
#endif // TRAIN_HPP