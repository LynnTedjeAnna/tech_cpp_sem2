cmake_minimum_required(VERSION 3.28)
project(Circustrain)

set(CMAKE_CXX_STANDARD 17)

add_executable(Circustrain src/main.cpp src/Train.cpp src/Cart.cpp)
include_directories(/Users/lynn.meindertsma/Github/tech_cpp_sem2/Circustrain/include)
include_directories(/Users/lynn.meindertsma/Github/tech_cpp_sem2/Circustrain/src)
