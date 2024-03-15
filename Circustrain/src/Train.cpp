//
// Created by Lynn Tedje Anna Meindertsma on 15 Mar 2024.
//
#include "Train.hpp"

Train::Train(uint64_t animals[6]) {
    fit_animals(animals);
}

void Train::fit_animals(uint64_t animals[6]) {
    // Carnivores have to go in separate carts no matter what
    for (int i = B_CARNIVORE; i <= S_CARNIVORE; ++i) {
        while (animals[i] > 0) {
            Cart cart;
            cart.add_animal(static_cast<AnimalType>(i));
            carts.push_back(cart);
            animals[i]--;
        }
    }

    // Distribute herbivores among existing carts
    for (uint8_t i = 0; i < carts.size(); ++i) {
        for (int j = B_HERBIVORE; j <= S_HERBIVORE; ++j) {
            while (animals[j] > 0 && carts[i].add_animal(static_cast<AnimalType>(j))) {
                animals[j]--;
            }
        }
    }

    // If there are remaining herbivores, create new carts
    for (int i = B_HERBIVORE; i <= S_HERBIVORE; ++i) {
        while (animals[i] > 0) {
            Cart cart;
            while (animals[i] > 0 && cart.add_animal(static_cast<AnimalType>(i))) {
                animals[i]--;
            }
            carts.push_back(cart);
        }
    }
}
