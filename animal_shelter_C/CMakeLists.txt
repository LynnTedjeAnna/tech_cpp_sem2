cmake_minimum_required(VERSION 3.28)
project(animal_shelter_C C)

set(CMAKE_C_STANDARD 23)

include_directories(include)
include_directories(test)
include_directories(Unity)

add_executable(
        animal_shelter_C
        src/main.c
        src/list.c
        src/resource_detector.c
        src/terminal_io.c
        src/file_element.c
        test/administration_test.c
        test/file_element_test.c
        test/main.c
        Unity/unity.c
        Unity/unity_test_module.c
)