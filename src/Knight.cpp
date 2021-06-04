#include "../include/Knight.h"

// working on the knight moves... call me Bob Seger

using namespace std;

vector<Move> Knight::GenerateKnightMoves(GameState& state) {
    
    PlayerState activePlayer = state.white;
    PlayerState inactivePlayer = state.black;
    if(state.activeColor == PlayerColor::Black) {
        activePlayer = state.black;
        inactivePlayer = state.white;
    }

    vector<Move> knightMoves;

    for(int i = 0; i < 64; i++) {

        uint64_t currentSquare = (uint64_t) 1 << i;
        
        if((activePlayer.bishops & currentSquare) >= 1) {
            vector<Move> singleKnightMoves = GenerateSingleKnightMoves(state, currentSquare, activePlayer, inactivePlayer);
            knightMoves.insert(knightMoves.end(), singleKnightMoves.begin(), singleKnightMoves.end());
        }
    }
    return knightMoves;
}

vector<Move> Knight::GenerateSingleKnightMoves(GameState& state, uint64_t oneKnight, PlayerState& activePlayer, PlayerState& inactivePlayer) {

    vector<int> dirs = {NORTH, EAST, SOUTH, WEST};
    vector<Move> singleKnightMoves;

    for(auto dir: dirs) {
        
        // move 2 squares in one direction to start, then look to each of the
        // perpendicular directions
        uint64_t cursorSquare = NextSquare(oneKnight, dir);
        cursorSquare = NextSquare(cursorSquare, dir);

        uint64_t opponentSquares = inactivePlayer.GetOccupiedSquares();
        uint64_t ownSquares = activePlayer.GetOccupiedSquares();
        uint64_t occupiedSquares = opponentSquares | ownSquares;

        if(cursorSquare == 0) continue;

        vector<int> perpDirs = PieceHelper::GetPerpendicularDirections(dir);
        for(auto perpDir: perpDirs) {
            uint64_t finalSquare = NextSquare(cursorSquare, perpDir);
            if(finalSquare == 0) continue;

            if(!(finalSquare & occupiedSquares)) {
                // add move non capture
                Move move = Move(Type, activePlayer.color, oneKnight, finalSquare, false);
                PieceHelper::AddMove(state, singleKnightMoves, move);
                continue;
            }

            if(finalSquare & opponentSquares) {
                Move move = Move(Type, activePlayer.color, oneKnight, finalSquare, true);
                PieceHelper::AddMove(state, singleKnightMoves, move);
                continue;
            }
        }
    }
    return singleKnightMoves;
}