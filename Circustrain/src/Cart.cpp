//
// Created by Lynn Tedje Anna Meindertsma on 15 Mar 2024.
//
class Cart {
public:
    Cart() {}

    bool add_animal(uint8_t animal) {
        //if animal is smaller than danger it will not fit in the cart and so will be filterd out
        if (animal < danger_level) {
            return false;
        }
        // if animal is uneven it is a carnivor and so if there is a current carnivor in the cart will be filterd out
        if (animal % 2) {
            if (danger_level != 0){
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
        //if it is over capacity animal cannot fit in cartand so will be filterd out
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

private:
    uint8_t s_herbivore_count = 0;
    uint8_t s_carnivore_count = 0;
    uint8_t m_herbivore_count = 0;
    uint8_t m_carnivore_count = 0;
    uint8_t b_herbivore_count = 0;
    uint8_t b_carnivore_count = 0;

    uint8_t capacity = CAPACITY;
    uint8_t danger_level = 0;

    // < ignore ( made by differnt student :) ) >
    friend std::ostream& operator<<(std::ostream& os, Cart const& cart);
    // </ ignore ( made by differnt student :) ) >
};