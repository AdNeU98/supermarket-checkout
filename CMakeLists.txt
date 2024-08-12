cmake_minimum_required(VERSION 3.28)
project(Catapult)

set(CMAKE_CXX_STANDARD 17)

# Include the headers directory
include_directories(${PROJECT_SOURCE_DIR}/headers)

# Add the executable with the correct paths
add_executable(Catapult
        cpp/Checkout.cpp
        cpp/StrategyB2G1.cpp
        cpp/StrategyB3CF.cpp
        cpp/Driver.cpp
)
