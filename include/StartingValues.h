// constant starting values for standard game of chess

// TODO use the correct numbers instead of placeholders

#include <cstdint>
#include <vector>
#include <iostream>

const uint64_t white_pawns = 0b0000000000000000000000000000000000000000000000001111111100000000;
const uint64_t black_pawns = 0b0000000011111111000000000000000000000000000000000000000000000000;

const uint64_t white_knights = 0b0000000000000000000000000000000000000000000000000000000001000010;
const uint64_t black_knights = 0b0100001000000000000000000000000000000000000000000000000000000000;

const uint64_t white_bishops = 0b0000000000000000000000000000000000000000000000000000000000100100;
const uint64_t black_bishops = 0b0010010000000000000000000000000000000000000000000000000000000000;

const uint64_t white_rooks = 0b0000000000000000000000000000000000000000000000000000000010000001;
const uint64_t black_rooks = 0b1000000100000000000000000000000000000000000000000000000000000000;

const uint64_t white_queen = 0b0000000000000000000000000000000000000000000000000000000000010000;
const uint64_t black_queen = 0b0001000000000000000000000000000000000000000000000000000000000000;

const uint64_t white_king = 0b0000000000000000000000000000000000000000000000000000000000001000;
const uint64_t black_king = 0b0000100000000000000000000000000000000000000000000000000000000000;

const std::vector<std::vector<char>> single_pawn = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', 'P', ' ', ' ', ' ', ' '}, 
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

// Directions for bit shift right
const int     NORTH = 8;
const int      WEST = 1;
const int NORTHEAST = 7;
const int NORTHWEST = 9;

// Directions for bit shift south
const int     SOUTH = 8;
const int      EAST = 1;
const int SOUTHEAST = 9;
const int SOUTHWEST = 7;

// Edges of the board
const uint64_t TOP =    0b1111111100000000000000000000000000000000000000000000000000000000;
const uint64_t BOTTOM = 0b0000000000000000000000000000000000000000000000000000000011111111;
const uint64_t RIGHT  = 0b0000000100000001000000010000000100000001000000010000000100000001;
const uint64_t LEFT   = 0b1000000010000000100000001000000010000000100000001000000010000000;

