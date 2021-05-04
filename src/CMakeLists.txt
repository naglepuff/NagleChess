# Create library with all of the stuff we need?

add_library(GameState PlayerState.cpp GameState.cpp Fen.cpp Move.cpp PieceHelper.cpp Pawn.cpp Rook.cpp Bishop.cpp Queen.cpp King.cpp)

#for the compiler...
target_include_directories(GameState PUBLIC "../src")