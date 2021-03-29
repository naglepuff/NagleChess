#include <string>
class Fen {

    public:
        std::string piecePlacement;
        std::string activeColor;
        std::string castlingOptions;
        std::string enPassantSquare;
        int halfmoveClock;
        int fullMoves;

        // ctors
        Fen() {

        };
        Fen(std::string pieces) {
            piecePlacement = pieces;
        }

};