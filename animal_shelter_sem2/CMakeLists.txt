cmake_minimum_required(VERSION 3.28)
project(animal_shelter_sem2)

set(CMAKE_CXX_STANDARD 26)

set(SOURCE
    main.cpp
    src/animal.cpp
    src/cat.cpp
    src/dog.cpp
    src/shelter.cpp
    src/simple_date.cpp
    src/administrationForm.cpp
        include/animal.hpp
        include/cat.hpp
        include/dog.hpp
        include/shelter.hpp
        include/simple_date.hpp
        include/administrationForm.hpp
)
include_directories(include)

add_executable(animal_shelter_sem2 ${SOURCE})
