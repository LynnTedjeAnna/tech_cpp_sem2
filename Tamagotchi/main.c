#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint16_t width;
    uint16_t height;
} Screen_Config;

/*!< get_pixel_count
 * calculates pixel count based on screen configuration
 */
uint32_t get_pixel_count(Screen_Config config) {
    return config.width * config.height;
}

/*!< get_pixel_array_size
 * calculates pixel array size based on screen configuration
 */
uint32_t get_pixel_array_size(Screen_Config config) {
    uint32_t pixel_count = get_pixel_count(config);
    // every pixel is stored in one bit (there are 8 bits in one byte (uint8_t))
    uint32_t array_size = pixel_count / 8;
    // check if there was a remainder in the above division and add one if so (round up)
    if (pixel_count % 8) { array_size++; }
    return array_size;
}

/*!< print_function
 * prints pixels in pixel array
 */
void print_function(uint8_t* pixel_array, Screen_Config config) {
    uint32_t pixel_count = get_pixel_count(config);
    uint32_t index = 0; // index in pixel_array
    uint8_t pixels;     // group of 8 pixels
    uint8_t bit_index;  // index in pixels
    uint8_t mask;
    for (uint32_t i = 0; i < pixel_count; ++i) {
        //bit_index is i divided by 8
        bit_index = i % 8;
        // increment index on every multiple of 8
        if (i != 0 && bit_index == 0) { index++; }
        // print newline at the end of screen width
        if (i != 0 && (i % config.width) == 0) { printf("\n"); }
        pixels = pixel_array[index];
        mask = 1 << bit_index;
        if ((pixels & mask) != 0)   { printf("█"); }
        else                        { printf(" "); }
    }
    printf("\n");
}

int main(void) {
    Screen_Config config;
    config.width = 96;
    config.height = 252;

    uint8_t* pixel_array = malloc(get_pixel_array_size(config));

    uint16_t pixel_index;
    uint16_t array_index;
    uint8_t  bit_index;
    uint8_t  mask;
    //for current print
    for (uint16_t i = 0; i < config.height; i++) {
        pixel_index = i % config.width;     // x position
        pixel_index += i * config.width;    // y position
        // Calculate the index in the pixel_array where the pixel is stored
        array_index = pixel_index / 8;
        // Calculate the bit_index within the byte where the pixel is stored
        bit_index = pixel_index % 8;
        // Create a mask with the appropriate bit set based on the bit_index
        mask = 1 << bit_index;
        // Set the corresponding bit in the pixel_array to 1 to represent the pixel being "on"
        pixel_array[array_index] |= mask;
    }

    print_function(pixel_array, config);
    return 0;
}
