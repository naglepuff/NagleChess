cmake_minimum_required(VERSION 3.16.3)

project(naglechess VERSION 1.0
                    DESCRIPTION "C++ chess engine"
                    LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)
