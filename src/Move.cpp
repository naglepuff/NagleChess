#include "../include/Move.h"

Move::Move(PieceType pieceType, PlayerColor playerColor, uint64_t start, uint64_t end, bool isCapture) {

    piece = pieceType;
    color = playerColor;
    startingSquare = start;
    endingSquare = end;
    capturedPiece = isCapture;

    type = MoveType::Reversible; // assume reversible

    if(piece == PieceType::Pawn) {
        type = MoveType::PawnAdvance;
    }

    if(isCapture) { // capture gets precedence over pawn advancement type moves
        type = MoveType::Capture;
    }

}

Move::Move(MoveType moveType, PlayerColor playerColor, uint64_t start, uint64_t end) {

    // with these types of moves, there is enough information from the move type
    type = moveType;
    color = playerColor;
    startingSquare = start;
    endingSquare = end;
    capturedPiece = false;

    switch (moveType)
    {
    case MoveType::CastleKing:
    case MoveType::CastleQueen:
        piece = PieceType::King;
        break;
    case MoveType::EnPassantCapture:
        piece = PieceType::Pawn;
        capturedPiece = true;
        break;
    default:
        piece = PieceType::Piece_None;
        break;
    }
}

Move::Move(MoveType moveType, PlayerColor playerColor, uint64_t start, uint64_t end, PieceType promoType, bool isCapture) {

    type = moveType; // this better be MoveType::Promotion....
    color = playerColor;
    piece = PieceType::Pawn;
    promotionPiece = promoType;
    startingSquare = start;
    endingSquare = end;
    capturedPiece = isCapture; // technically could happen in a game
}