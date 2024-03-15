//
// Created by Lynn Tedje Anna Meindertsma on 15 Mar 2024.
//
// Train.hpp
#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <vector>
#include "Cart.hpp"

enum AnimalType {
    B_CARNIVORE,
    M_CARNIVORE,
    S_CARNIVORE,
    B_HERBIVORE,
    M_HERBIVORE,
    S_HERBIVORE
};

class Train {
private:
    std::vector<Cart> carts;

public:
    Train(uint64_t animals[6]);
    void fit_animals(uint64_t animals[6]);
};

#endif // TRAIN_HPP
