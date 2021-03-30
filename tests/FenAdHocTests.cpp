/**
 * Ad-hoc testing for NagleChess, started before unit testing framework was decided.
 * As convention for these tests, a return value of true is pass and false is fail.
 **/

#include <iostream>
#include "../include/GameState.h"

using namespace std;

bool ParseString_AdHocTest1();
bool ParseString_AdHocTest2();

int main() {
    
    string p = "PASS";
    string f = "FAIL";

    cout << "The result of ParseString_AdHocTest1 is: " << (ParseString_AdHocTest1() ? p : f) << endl;
    cout << "The result of ParseString_AdHocTest2 is: " << (ParseString_AdHocTest2() ? p : f) << endl;
    
    return 0;
}

bool ParseString_AdHocTest1() {

    string fenString = FEN_START + " w KQkq - 0 1";
    Fen fen;
    fen.ParseString(fenString);
    if(fen.piecePlacement != FEN_START
        || fen.activeColor != "w"
        || fen.castlingOptions != "KQkq"
        || fen.enPassantSquare != "-"
        || fen.halfmoveClock != 0
        || fen.fullMoves != 1) {
        return false;
    }
    return true;
}

bool ParseString_AdHocTest2() {

    string fenString = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";
    Fen fen;
    fen.ParseString(fenString);
    if(fen.piecePlacement != "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR"
        || fen.activeColor != "b"
        || fen.castlingOptions != "KQkq"
        || fen.enPassantSquare != "e3"
        || fen.halfmoveClock != 0
        || fen.fullMoves != 1) {
        return false;
    }
    return true;
}