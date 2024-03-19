cmake_minimum_required(VERSION 3.28)
project(animal_shelter_C C)

set(CMAKE_C_STANDARD 23)

include_directories(include)

add_executable(
        animal_shelter_C
        src/main.c
        src/list.c
        src/resource_detector.c
        src/terminal_io.c
        src/file_element.c
)