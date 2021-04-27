/** 
 * Move generation code 4 rooks based on given game state. 
 * Rooks can move in the 4 cardinal directions.
 * In this engine, rooks are moved by KINGS when they castle. 
 * This module does not care about castling when generating moves.
**/

#include "../include/Rook.h"

using namespace std;

const std::vector<int> Rook::DIRS ({NORTH, EAST, SOUTH, WEST});

vector<Move> Rook::GenerateRookMoves(GameState& state) {

    PlayerState activePlayer = state.white;
    PlayerState inactivePlayer = state.black;
    if(state.activeColor == PlayerColor::Black) {
        activePlayer = state.black;
        inactivePlayer = state.white;
    }

    vector<Move> rookMoves;

    for(int i = 0; i < 64; i++) {

        uint64_t currentSquare = (uint64_t) 1 << i;

        if((activePlayer.rooks & currentSquare) >= 1) {
            vector<Move> singleRookMoves = GenerateSingleRookMoves(state, currentSquare, activePlayer, inactivePlayer);
            rookMoves.insert(rookMoves.end(), singleRookMoves.begin(), singleRookMoves.end());
        }
    }
    return rookMoves;
}

vector<Move> Rook::GenerateSingleRookMoves(GameState& state, uint64_t oneRook, PlayerState& activePlayer, PlayerState& inactivePlayer) {

    return PieceHelper::GenerateMoves(state, oneRook, activePlayer, inactivePlayer, DIRS, Type);
}