cmake_minimum_required(VERSION 3.20)

project(Softwareprojekt_2 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add compile options
add_compile_options(-Wall -Wextra -pedantic -O0)

# add a library for your student structure
add_library(Developer src/developer.cpp)

# add the includes to the library
target_include_directories(Developer PUBLIC include)

# assign files to executable
add_executable(sample_exec src/main.cpp)

# add include directrories to executable
target_include_directories(sample_exec PUBLIC include)

# link libraries
target_link_libraries(sample_exec PUBLIC Developer)




