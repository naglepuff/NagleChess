#include "../include/Pawn.h"

using namespace std;

vector<Move> Pawn::GeneratePawnMoves(GameState state) {

    PlayerState activePlayer = state.white;
    PlayerState inactivePlayer = state.black;
    if(state.activeColor == PlayerColor::Black) {
        activePlayer = state.black;
        inactivePlayer = state.white;
    }

    vector<Move> pawnMoves = vector<Move>();

    for(int i = 0; i < 64; i++) {
        uint64_t currentSquare = (uint64_t) 1 << i;
        
        if(activePlayer.pawns & currentSquare > 1) {

            vector<Move> singlePawnMoves = GenerateSinglePawnMoves(state, currentSquare, activePlayer, inactivePlayer);
            pawnMoves.insert(pawnMoves.end(), singlePawnMoves.begin(), singlePawnMoves.end());
        }
    }

    return pawnMoves;
}

vector<Move> Pawn::GenerateSinglePawnMoves(GameState state, uint64_t onePawn, PlayerState activePlayer, PlayerState inactivePlayer) {

    // for each piece we have to do some stuff to get things like occupied squares... there's probably a better way to do this, with like a struct or something
    // to memoize this part
    uint64_t opponentSquares = inactivePlayer.GetOccupiedSquares();
    uint64_t ownSquares = activePlayer.GetOccupiedSquares();
    uint64_t occupiedSquares = opponentSquares | ownSquares;
    int moveDirection = (activePlayer.color == PlayerColor::White) ? NORTH : SOUTH;

    // generate non-capture pawn moves
    uint64_t startingPosition = (activePlayer.color == PlayerColor::White) ? WHITE_PAWNS : BLACK_PAWNS;
    int maxDistance = (onePawn & startingPosition > 0) ? 2 : 1;
    int numSquaresMoved = 0;
    uint64_t currentSquare = onePawn; // copy onePawn into a starting position of sorts
    uint64_t nextSquare = NextSquare(onePawn, moveDirection);
    while(numSquaresMoved < maxDistance && !(nextSquare & opponentSquares)) {

        // add the move to the  list 
    }

    // generate captureing pawn moves

    return vector<Move>();
}



