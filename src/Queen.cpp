# include "../include/Queen.h"

using namespace std;

const vector<int> Queen::DIRS ({NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST});

vector<Move> Queen::GenerateQueenMoves(GameState& state) {

    // This part could probabl be a piece helper function
    PlayerState activePlayer = state.white;
    PlayerState inactivePlayer = state.black;
    if(state.activeColor == PlayerColor::Black) {
        activePlayer = state.black;
        inactivePlayer = state.white;
    }

    vector<Move> queenMoves;

    for(int i = 0; i < 64; i++) {

        uint64_t currentSquare = (uint64_t) 1 << i;

        if((activePlayer.queen & currentSquare) >= 1) {
            vector<Move> singleQueenMoves = GenerateSingleQueenMoves(state, currentSquare, activePlayer, inactivePlayer);
            queenMoves.insert(queenMoves.end(), singleQueenMoves.begin(), singleQueenMoves.end());
        }
    }

    return queenMoves;
}

vector<Move> Queen::GenerateSingleQueenMoves(GameState& state, uint64_t oneQueen, PlayerState& activePlayer, PlayerState& inactivePlayer) {

    return PieceHelper::GenerateMoves(state, oneQueen, activePlayer, inactivePlayer, DIRS, Type);
}