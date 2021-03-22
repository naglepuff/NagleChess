# Create library with all of the stuff we need?

add_library(GameState PlayerState.cpp GameState.cpp)

#for the compiler...
target_include_directories(GameState PUBLIC "../src")