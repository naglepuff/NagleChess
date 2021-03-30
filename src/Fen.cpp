#include "../include/Fen.h"
using namespace std;

void Fen::ParseString(string fenString) {

    // for now, assume valid FEN string. we should probably write a funtion to check validity at some point

    int position = fenString.find(FEN_DELIMITER);
    piecePlacement = fenString.substr(0, position);
    fenString.erase(0, position + 1);
    
    position = fenString.find(FEN_DELIMITER);
    activeColor = fenString.substr(0, position);
    fenString.erase(0, position + 1);

    position = fenString.find(FEN_DELIMITER);
    castlingOptions = fenString.substr(0, position);
    fenString.erase(0, position + 1);

    position = fenString.find(FEN_DELIMITER);
    enPassantSquare = fenString.substr(0, position);
    fenString.erase(0, position + 1);

    position = fenString.find(FEN_DELIMITER);
    halfmoveClock = stoi(fenString.substr(0, position));
    fenString.erase(0, position + 1);

    position = fenString.find(FEN_DELIMITER);
    fullMoves = stoi(fenString.substr(0, position));
}

string Fen::ToString() {
    
    // assumes no empty strings for now

    return piecePlacement + " " + activeColor + " " + castlingOptions
            + " " + enPassantSquare + " " + to_string(halfmoveClock) 
            + " " + to_string(fullMoves); 
}

