#include "./StartingValues.h"

enum MoveType {
    Reversible,
    PawnAdvance,
    Capture,
    CastleKing,
    CastleQueen,
    Promotion,
    EnPassantCapture
};


class Move {
    public:
        // default constructor
        Move() {

        };
        Move(PieceType pieceType, PlayerColor playerColor, uint64_t start, uint64_t end, bool isCapture);
        // specific type of move, used for castling
        Move(MoveType moveType, PlayerColor playerColor, uint64_t start, uint64_t end);
        // promotion-only constructor
        Move(MoveType moveType, PlayerColor playerColor, uint64_t start, uint64_t end, PieceType promoType, bool isCapture);

        PieceType piece;
        PieceType promotionPiece;
        PlayerColor color;

        MoveType type; // need special handling for promotion, castling, and perhaps enPassant

        uint64_t startingSquare;
        uint64_t endingSquare;

        bool capturedPiece;
};