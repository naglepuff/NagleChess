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
            activeColor = color.size() == 1 ? color : FEN_PLACEHOLDER;
            castlingOptions = castling.size() > 0 ? castling : FEN_PLACEHOLDER;
            enPassantSquare = enPassantTarget.size() == 2 ? enPassantTarget : FEN_PLACEHOLDER;
            halfmoveClock = halfmoves >= 0 ? halfmoves : 0;
            fullMoves = fullMoveNum >= 1 ? fullMoves : 1;
        };
        std::string piecePlacement;
        std::string activeColor;
        std::string castlingOptions;
        std::string enPassantSquare;
        int halfmoveClock;
        int fullMoves;
        std::string ToString();
        static bool IsValidFenString(std::string input);
        static bool ValidPieceString(std::string pieceString);
    //private:
        void ParseString(std::string fenString);

        

};