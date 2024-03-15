//
// Created by Lynn Tedje Anna Meindertsma on 15 Mar 2024.
//

#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <vector>

class Train {
public:
    // Constructor
    Train(uint64_t animals[6]);
    //public function to fit animals in carts
    void fit_animals();

private:
    std::vector<Cart> carts;  // create a vector (array that can grow) for Carts
    // < ignore ( made by differnt student :) ) >
    friend std::ostream& operator<<(std::ostream& os, Train const& train);
    // </ ignore ( made by differnt student :) ) >
};
#endif //TRAIN_H