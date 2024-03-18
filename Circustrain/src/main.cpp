#include <iostream>
#include <vector>
#include "Train.hpp"
#include "Cart.hpp"

int animal_count[6];

int main() {
    printf("How many small herbivors: ");
    scanf("%llu", &animal_count[S_HERBIVORE]);
    printf("How many small carnivores: ");
    scanf("%llu", &animal_count[S_CARNIVORE]);
    printf("How many medium herbivors: ");
    scanf("%llu", &animal_count[M_HERBIVORE]);
    printf("How many medium carnivores: ");
    scanf("%llu", &animal_count[M_CARNIVORE]);
    printf("How many big herbivors: ");
    scanf("%llu", &animal_count[B_HERBIVORE]);
    printf("How many big carnivores: ");
    scanf("%llu", &animal_count[B_CARNIVORE]);
    printf("\n");

    // Creating train object and fitting animals
    Train train;
    train.fit_animals(animal_count);

    // Print the entire array
    printf("The array values are: ");
    for (int i = 0; i < 6; ++i) {
        printf("%llu ", animal_count[i]);
    }
    // Print all carts
    std::cout << "\n\n" << train;
    printf("cart count: %llu", train.get_length());

    return 0;
}