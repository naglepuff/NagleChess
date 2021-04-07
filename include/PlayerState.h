// player state defs

#include "./Fen.h"

class PlayerState {

    public:
    // constructor and destructor
        PlayerState(bool isWhite) {
            color = isWhite ? PlayerColor::White : PlayerColor::Black;
            pawns = isWhite ? WHITE_PAWNS : BLACK_PAWNS;
            rooks = isWhite ? WHITE_ROOKS : BLACK_ROOKS;
            knights = isWhite ? WHITE_KNIGHTS : BLACK_KNIGHTS;
            bishops = isWhite ? WHITE_BISHOPS : BLACK_BISHOPS;
            queen = isWhite ? WHITE_QUEEN : BLACK_QUEEN;
            king = isWhite ? WHITE_KING : BLACK_KING;
        }
        PlayerState(PlayerColor playerColor) {
            Clear();
            color = playerColor;
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
        bool canCastleKing;
        bool canCastleQueen;
        bool inCheck;
        PlayerColor color;
    // functions
        bool CanCastle();
        int CurrentScore();
        void PlacePiece(PieceType pieceType, int numShifts);
        void Clear();
        bool AmIOnSquare(uint64_t square);
        uint64_t GetOccupiedSquares();
    // move generation

        

};