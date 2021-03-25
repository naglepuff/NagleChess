#include "./StartingValues.h"

class Move {
    public:
        PieceType piece;
        PlayerColor color;

        uint64_t startingSquare;
        uint64_t endingSquare;

        bool capturedPiece;
};