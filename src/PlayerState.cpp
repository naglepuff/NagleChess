// player state business logic
#include "../include/PlayerState.h"
using namespace std;

void PlayerState::Clear() {
    /**
     * Clear all bitboards representing this player (set to 0).
     **/ 

    pawns = 0;
    bishops = 0;
    knights = 0;
    rooks = 0;
    queen = 0;
    king = 0;
}

void PlayerState::PlacePiece(PieceType type, int numShifts) {

    uint64_t newPiece = 1;
    newPiece = newPiece << numShifts; // after shifting 1 over this many bits we essentially have 2^numShifts

    switch(type) {
        case PieceType::Pawn:
            pawns = pawns | newPiece;
            break;
        case PieceType::Bishop:
            bishops = bishops | newPiece;
            break;
        case PieceType::Knight:
            knights = knights | newPiece;
            break;
        case PieceType::Rook:
            rooks = rooks | newPiece;
            break;
        // only 1 king and queen
        case PieceType::Queen:
            queen = newPiece;
            break;
        case PieceType::King:
            king = newPiece;
            break;
    }
    // check for valid game state?

}

bool PlayerState::AmIOnSquare(uint64_t square) {
    uint64_t squaresIAmOn = pawns + bishops + knights + rooks + queen + king;
    return (square & squaresIAmOn) == square; // bitwise and
}