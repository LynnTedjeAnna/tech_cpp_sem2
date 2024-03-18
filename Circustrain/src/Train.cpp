//
// Created by Lynn Tedje Anna Meindertsma on 15 Mar 2024.
//
#include "Train.hpp"

//defines the default constructor for the Train class
Train::Train() {}

int Train::get_length() {
    return carts.size();
}

void Train::fit_animals(int animals[6]) {
    // Carnivores have to go in separate carts no matter what
    while (animals[B_CARNIVORE]) {
        Cart cart;
        cart.add_animal(B_CARNIVORE);
        carts.push_back(cart);
        animals[B_CARNIVORE]--;
    }
    while (animals[M_CARNIVORE]) {
        Cart cart;
        cart.add_animal(M_CARNIVORE);
        carts.push_back(cart);
        animals[M_CARNIVORE]--;
    }
    while (animals[S_CARNIVORE]) {
        Cart cart;
        cart.add_animal(S_CARNIVORE);
        carts.push_back(cart);
        animals[S_CARNIVORE	]--;
    }

    //dividing the herbivors over the excisiting carts
    for (uint8_t i = 0; i < carts.size(); i++) {
        while (animals[B_HERBIVORE] && carts[i].add_animal(B_HERBIVORE)) {
            animals[B_HERBIVORE]--;
        }
        while (animals[M_HERBIVORE] && carts[i].add_animal(M_HERBIVORE)) {
            animals[M_HERBIVORE]--;
        }
        while (animals[S_HERBIVORE] && carts[i].add_animal(S_HERBIVORE)){
            animals[S_HERBIVORE]--;
        }
    }
    //dividing herbivors over new carts
    while (animals[B_HERBIVORE] != 0 || animals[M_HERBIVORE] != 0 || animals[S_HERBIVORE] != 0) {
        Cart cart;
        while (animals[B_HERBIVORE] && cart.add_animal(B_HERBIVORE)) {
            animals[B_HERBIVORE]--;
        }
        while (animals[M_HERBIVORE] && cart.add_animal(M_HERBIVORE)) {
            animals[M_HERBIVORE]--;
        }
        while (animals[S_HERBIVORE] && cart.add_animal(S_HERBIVORE)){
            animals[S_HERBIVORE]--;
        }
        carts.push_back(cart);
    }
}


//printing carts
std::ostream& operator<<(std::ostream& os, const Train& train) {
    for (Cart cart : train.carts) {
        os << cart;
    }
    return os;
}
