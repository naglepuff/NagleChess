// player state defs

#include "./StartingValues.h"

enum PieceType {
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King
};

class PlayerState {

    public:
    // constructor and destructor
        PlayerState(bool isWhite) {
            pawns = isWhite ? white_pawns : black_pawns;
            rooks = isWhite ? white_rooks : black_rooks;
            knights = isWhite ? white_knights : black_knights;
            bishops = isWhite ? white_bishops : black_bishops;
            queen = isWhite ? white_queen : black_queen;
            king = isWhite ? white_king : black_king;
        }
        PlayerState() {
            pawns = rooks = bishops = queen = knights = king = 0;
        }
    // bitboards for pieces
        uint64_t pawns;
        uint64_t rooks;
        uint64_t knights;
        uint64_t bishops;
        uint64_t queen;
        uint64_t king;
    // gamestate information
        bool kingMoved;
        bool hasCastled;
        bool check;
    // functions
        bool CanCastle();
        int CurrentScore();
        void PlacePiece(PieceType pieceType, int numShifts);

        

};