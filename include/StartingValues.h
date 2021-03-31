// constant starting values for standard game of chess

// TODO use the correct numbers instead of placeholders

#include <cstdint>
#include <vector>
#include <string>
#include <iostream>

enum PieceType {
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King,
    Piece_None
};

enum PlayerColor {
    White,
    Black,
    Player_None 
};

const uint64_t WHITE_PAWNS = 0b0000000000000000000000000000000000000000000000001111111100000000;
const uint64_t BLACK_PAWNS = 0b0000000011111111000000000000000000000000000000000000000000000000;

const uint64_t WHITE_KNIGHTS = 0b0000000000000000000000000000000000000000000000000000000001000010;
const uint64_t BLACK_KNIGHTS = 0b0100001000000000000000000000000000000000000000000000000000000000;

const uint64_t WHITE_BISHOPS = 0b0000000000000000000000000000000000000000000000000000000000100100;
const uint64_t BLACK_BISHOPS = 0b0010010000000000000000000000000000000000000000000000000000000000;

const uint64_t WHITE_ROOKS = 0b0000000000000000000000000000000000000000000000000000000010000001;
const uint64_t BLACK_ROOKS = 0b1000000100000000000000000000000000000000000000000000000000000000;

const uint64_t WHITE_QUEEN = 0b0000000000000000000000000000000000000000000000000000000000010000;
const uint64_t BLACK_QUEEN = 0b0001000000000000000000000000000000000000000000000000000000000000;

const uint64_t WHITE_KING = 0b0000000000000000000000000000000000000000000000000000000000001000;
const uint64_t BLACK_KING = 0b0000100000000000000000000000000000000000000000000000000000000000;

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

// FEN info
const std::string FEN_START = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
const std::string FEN_DELIMITER = " ";
const std::string FEN_PLACEHOLDER = "-";

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

// SQUARES
const uint64_t H1 = 1;
const uint64_t H2 = 1 << 1;
const uint64_t H3 = 1 << 2;
const uint64_t H4 = 1 << 3;
const uint64_t H5 = 1 << 4;
const uint64_t H6 = 1 << 5;
const uint64_t H7 = 1 << 6;
const uint64_t H8 = 1 << 7;