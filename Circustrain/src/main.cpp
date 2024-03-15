#include <iostream>
#include <vector>
#include "Train.hpp"
#include "Cart.hpp"

uint64_t animal_count[6];
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
//#define DEBUG

// 37 = white  || 35 = magenta || 34 = blue
// < ignore ( made by differnt student :) ) >
std::ostream& operator<<(std::ostream& os, Cart const& cart) {
#ifdef DEBUG
	os << "sh: " << (uint16_t)cart.s_herbivore_count << ", ";
	os << "sc: " << (uint16_t)cart.s_carnivore_count << ", ";
	os << "mh: " << (uint16_t)cart.m_herbivore_count << ", ";
	os << "mc: " << (uint16_t)cart.m_carnivore_count << ", ";
	os << "bh: " << (uint16_t)cart.b_herbivore_count << ", ";
	os << "bc: " << (uint16_t)cart.b_carnivore_count << " || ";
	os << "cap: " << (uint16_t)cart.capacity << ", ";
	os << "dlvl: " << (uint16_t)cart.danger_level << "\n";
#else
	constexpr const char* colours[3] = {"\033[1;37m", "\033[1;35m", "\033[1;34m"};

    uint8_t buf[CAPACITY];
	for (uint8_t i = 0; i < CAPACITY; i++) { buf[i] = 0xFF; }
    uint8_t* ptr = buf;
    for (uint8_t i = 0; i < cart.b_carnivore_count; i++) { *ptr++ = B_CARNIVORE; }
    for (uint8_t i = 0; i < cart.b_herbivore_count; i++) { *ptr++ = B_HERBIVORE; }
    for (uint8_t i = 0; i < cart.m_carnivore_count; i++) { *ptr++ = M_CARNIVORE; }
    for (uint8_t i = 0; i < cart.m_herbivore_count; i++) { *ptr++ = M_HERBIVORE; }
    for (uint8_t i = 0; i < cart.s_carnivore_count; i++) { *ptr++ = S_CARNIVORE; }
    for (uint8_t i = 0; i < cart.s_herbivore_count; i++) { *ptr++ = S_HERBIVORE; }
	uint8_t val; char c; const char* col;
    os << "____$____\n";
	for (uint8_t i = 0; i < CAPACITY >> 1; i++) {
		val = buf[2 * i];
		c = ' '; col = "\033[0m";
		if (val != 0xFF) {
			c = val % 2 ? 'C' : 'H';
			col = colours[val >> 1];
		}
		os << "| " << col << c << "\033[0m | ";
		val = buf[(2 * i) + 1];
		c = ' '; col = "\033[0m";
		if (val != 0xFF) {
			c = val % 2 ? 'C' : 'H';
			col = colours[val >> 1];
		}
		os << col << c << "\033[0m |\n";
	}
	if (CAPACITY & 0b1) {
		val = buf[CAPACITY - 1];
		c = ' '; col = "\033[0m";
		if (val != 0xFF) {
			c = val % 2 ? 'C' : 'H';
			col = colours[val >> 1];
		}
		os << "|   " << col << c << "\033[0m   |\n";
	}
    os << "¯¯¯¯$¯¯¯¯\n";
#endif
    return os;
}
std::ostream& operator<<(std::ostream& os, Train const& train) {
#ifdef DEBUG
	for (Cart cart : train.carts) {
		os << cart;
	}
#else
    for (uint8_t i = 0; i < train.carts.size(); i++) {
    	Cart cart = train.carts[i];
        if (i == train.carts.size() - 1) {
	        os << cart << "   \033[7;47m |   \033[0m \n";
        } else {
        	os << cart << "    |    \n";
        }
    }
    os << "__\033[7;47m__$____\033[0m\n";
	os << "|  \033[7;47m     \033[0m|\n";
	os << "|  \033[7;47m    \033[0m |\n";
	os << "|   \033[7;47m# \033[0m  |\n";
	os << "|       |\n";
	os << " \\     /\n";
	os << "  ¯-_-¯ \n";
#endif
    return os;
}
// </ ignore ( made by differnt student :) ) >

int main()
{
    Train train;

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

    train.fit_animals(animal_count);

    // Print the entire array
    printf("The array values are: ");
    for (int i = 0; i < 6; ++i) {
        printf("%llu ", animal_count[i]);
    }

    printf("\n\n");
    printf("Train: \n");
	std::cout << train;
    printf("\n\n");
    printf("The train has %llu amount of carts", 0); // TODO...

    return 0;
}