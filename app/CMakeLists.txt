# add the main executable, the chess application
add_executable(naglechess main.cpp)

# link libraries
target_link_libraries(naglechess LINK_PUBLIC GameState)