
cmake_minimum_required(VERSION 3.10)
project(DeliveryManagementSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(DeliveryManagementSystem
    src/main.cpp
    src/DeliverySystem.cpp
    src/Order.cpp
)
