// constant starting values for standard game of chess

// TODO use the correct numbers instead of placeholders

#include <cstdint>
#include <vector>
#include <iostream>

const uint64_t white_pawns = 0;
const uint64_t black_pawns = 1;

const uint64_t white_knights = 0;
const uint64_t black_knights = 1;

const uint64_t white_bishops = 0;
const uint64_t black_bishops = 1;

const uint64_t white_rooks = 0;
const uint64_t black_rooks = 1;

const uint64_t white_queen = 0;
const uint64_t black_queen = 1;

const uint64_t white_king = 0;
const uint64_t black_king = 1;

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