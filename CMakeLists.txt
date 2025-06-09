cmake_minimum_required(VERSION 3.20)
project(Softwareprojekt_2)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable strict compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# Define logo path as a compile-time constant
add_definitions(-DDEV_LOGO_PATH=\"${CMAKE_SOURCE_DIR}/logos/\")

# Include header files from the include directory
include_directories(include)

# Build the shared developer library
add_library(developer_lib
    src/developer.cpp
    src/junior_developer.cpp
    src/senior_developer.cpp
)

# Build the main application executable
add_executable(main_app
    src/main.cpp
)

# Link the main application with the developer library
target_link_libraries(main_app developer_lib)