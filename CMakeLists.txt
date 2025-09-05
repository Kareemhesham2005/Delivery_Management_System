
cmake_minimum_required(VERSION 3.10)
project(DeliveryManagementSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(DeliveryManagementSystem
    src/main.cpp
    src/DeliverySystem.cpp
    src/Point.cpp
    src/Driver.cpp
    src/Restaurant.cpp
    src/Order.cpp
)

# Optional: simple tests target (no external frameworks)
add_executable(tests_runner
    tests/tests.cpp
    src/Point.cpp
    src/DeliverySystem.cpp
    src/Driver.cpp
    src/Restaurant.cpp
    src/Order.cpp
)

enable_testing()
add_test(NAME basic-tests COMMAND tests_runner)
