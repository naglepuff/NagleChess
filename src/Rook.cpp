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

        if((activePlayer.rooks & currentSquare) > 1) {
            vector<Move> singleRookMoves = GenerateSingleRookMoves(state, currentSquare, activePlayer, inactivePlayer);
            rookMoves.insert(rookMoves.end(), singleRookMoves.begin(), singleRookMoves.end());
        }
    }
    return rookMoves;
}

vector<Move> Rook::GenerateSingleRookMoves(GameState& state, uint64_t oneRook, PlayerState& activePlayer, PlayerState& inactivePlayer) {

    vector<Move> singleRookMoves;
    uint64_t opponentSquares = inactivePlayer.GetOccupiedSquares();
    uint64_t ownSquares = activePlayer.GetOccupiedSquares();
    uint64_t occupiedSquares = ownSquares | opponentSquares;

    for(int dir: DIRS) {
        
        uint64_t currentSquare = oneRook;
        uint64_t nextSquare = NextSquare(currentSquare, dir);

        while(nextSquare > 0 && !(nextSquare & occupiedSquares)) {

            // in here are reversible moves.
            Move move = Move(PieceType::Rook, activePlayer.color, oneRook, nextSquare, false);
            if(state.IsLegal(move)) { singleRookMoves.push_back(move);}

            currentSquare = nextSquare;
            nextSquare = NextSquare(currentSquare, dir);
        }

        // next square might have an enemy piece that we can capture!
        if((nextSquare & opponentSquares)) {
            Move move = Move(PieceType::Rook, activePlayer.color, oneRook, nextSquare, true);
            if(state.IsLegal(move)){singleRookMoves.push_back(move);}
        }
    }
    return singleRookMoves;
}