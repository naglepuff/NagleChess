/** 
 * Move generation code 4 bishops based on given game state. 
 * Bishops can move on the diagonals.
 **/

#include "../include/Bishop.h"

using namespace std;

const vector<int> Bishop::DIRS ({NORTHEAST, NORTHWEST, SOUTHWEST, SOUTHEAST});

vector<Move> Bishop::GenerateBishopMoves(GameState& state) {

    PlayerState activePlayer = state.white;
    PlayerState inactivePlayer = state.black;
    if(state.activeColor == PlayerColor::Black) {
        activePlayer = state.black;
        inactivePlayer = state.white;
    }

    vector<Move> bishopMoves;

    for(int i = 0; i < 64; i++) {

        uint64_t currentSquare = (uint64_t) 1 << i;
        
        if((activePlayer.bishops & currentSquare) > 1) {
            vector<Move> singleBishopMoves = GenerateSingleBishopMoves(state, currentSquare, activePlayer, inactivePlayer);
            bishopMoves.insert(bishopMoves.end(), singleBishopMoves.begin(), singleBishopMoves.end());
        }
    }
    return bishopMoves;
}

vector<Move> Bishop::GenerateSingleBishopMoves(GameState& state, uint64_t oneBishop, PlayerState& activePlayer, PlayerState& inactivePlater) {

    return PieceHelper::GenerateMoves(state, oneBishop, activePlayer, inactivePlater, DIRS, Type);
}