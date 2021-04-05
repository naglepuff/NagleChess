#include "./StartingValues.h"

enum MoveType {
    Reversible,
    PawnAdvance,
    Capture,
    Castle,
    Promotion,
    EnPassantCapture
};

class Move {
    public:
        PieceType piece;
        PlayerColor color;

        MoveType type; // need special handling for promotion, castling, and perhaps enPassant

        uint64_t startingSquare;
        uint64_t endingSquare;

        bool capturedPiece;
};