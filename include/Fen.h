#include <string>
#include "./StartingValues.h"

class Fen {

    public:
        // ctors
        Fen() {

        };
        Fen(std::string fenString) {
            
            ParseString(fenString);
        };
        Fen(std::string pieces, std::string color, std::string castling, std::string enPassantTarget, int halfmoves, int fullMoveNum) {
            piecePlacement = pieces;
            activeColor = color;
            castlingOptions = castling;
            enPassantSquare = enPassantTarget;
            halfmoveClock = halfmoves;
            fullMoves = fullMoveNum;
        };
        std::string piecePlacement;
        std::string activeColor;
        std::string castlingOptions;
        std::string enPassantSquare;
        int halfmoveClock;
        int fullMoves;
        std::string ToString();
        bool IsValidFenString(); // TODO
    //private:
        void ParseString(std::string fenString);

        

};