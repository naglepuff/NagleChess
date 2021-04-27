#include "../include/PieceHelper.h"
#include <iostream>

using namespace std;

vector<Move> PieceHelper::GenerateMoves(GameState& state, uint64_t pieceSquare, PlayerState& activePlayer, PlayerState& inactivePlayer, 
        const std::vector<int> dirs, PieceType pieceType) {

    vector<Move> pieceMoves;
    uint64_t opponentSquares = inactivePlayer.GetOccupiedSquares();
    uint64_t ownSquares = activePlayer.GetOccupiedSquares();
    uint64_t occupiedSquares = opponentSquares | ownSquares;

    for(int dir: dirs) {
        uint64_t currentSquare = pieceSquare;
        uint64_t nextSquare = NextSquare(currentSquare, dir);

        while(nextSquare > 0 && !(nextSquare & occupiedSquares)) {

            //in here are reversible moves
            Move move = Move(pieceType, activePlayer.color, pieceSquare, nextSquare, false);
            AddMove(state, pieceMoves, move);

            currentSquare = nextSquare;
            nextSquare = NextSquare(currentSquare, dir);
        }

        //next square might have an enemy piece that we can capture
        if((nextSquare & opponentSquares)) {

            Move move = Move(pieceType, activePlayer.color, pieceSquare, nextSquare, true);
            AddMove(state, pieceMoves, move);
        }
    }

    return pieceMoves;
}

void PieceHelper::AddMove(GameState& state, vector<Move>& moves, Move move) {

    if(state.IsLegal(move)) {

        moves.push_back(move);
    }
}