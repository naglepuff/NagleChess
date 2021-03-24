/**
 * Ad-hoc testing for NagleChess, started before unit testing framework was decided.
 * As convention for these tests, a return value of true is pass and false is fail.
 **/

#include <iostream>
#include "../include/GameState.h"

using namespace std;

bool RepositionFromArray_AdHocTest1();
bool GetPlayerOnSquare_AdHocTest1();
bool GetPieceOnSquare_AdHocTest1();
bool GetPieceOnSquare_AdHocTest2();
vector<vector<char>> CreateSinglePieceBoard(PieceType type);

int main() {

    string p = "PASS";
    string f = "FAIL";
    cout << "Result for RepositionFromArray_AdHocTest1: " << (RepositionFromArray_AdHocTest1() ? p : f) << endl;
    cout << "Result for GetPlayerOnSquare_AdHocTest1: " << (GetPlayerOnSquare_AdHocTest1() ? p : f) << endl;
    cout << "Result for GetPieceOnSquare_AdHocTest1(): " << (GetPieceOnSquare_AdHocTest1() ? p : f) << endl;
    cout << "Result for GetPieceOnSquare_AdHocTest2(): " << (GetPieceOnSquare_AdHocTest2() ? p : f) << endl;
    return 0;
}

bool RepositionFromArray_AdHocTest1() {
    /** 
     * Test RepositionFromArray given an array with a single white pawn on D02.
     * A bitstring with a pawn in the D2 will evaluate to 4096.  
    **/

    GameState state = GameState();
    state.RepositionFromArray(single_pawn);
    return state.white.pawns == 4096;
}

bool GetPlayerOnSquare_AdHocTest1() {

    GameState state = GameState();
    state.RepositionFromArray(single_pawn);
    return state.GetPlayerOnSquare(4096) == PlayerColor::White;
}

bool GetPieceOnSquare_AdHocTest1() {
    GameState state = GameState();
    state.RepositionFromArray(single_pawn);
    return state.GetPieceOnSquare(1 << 12) == PieceType::Pawn;
}

bool GetPieceOnSquare_AdHocTest2() {
    GameState state = GameState();
    state.RepositionFromArray(single_pawn);
    return state.GetPieceOnSquare((uint64_t) 1 << 44) == PieceType::Piece_None;
}

vector<vector<char>> CreateSinglePieceBoard(PieceType type) {
    char pieceChar;

    switch(type) {
        case PieceType::Pawn:
            // eventually black pawns could be useful here too
            pieceChar = 'P';
            break;
        case PieceType::Bishop:
            pieceChar = 'B';
            break;
        case PieceType::Knight:
            pieceChar = 'N';
            break;
        case PieceType::Rook:
            pieceChar = 'R';
            break;
        case PieceType::Queen:
            pieceChar = 'Q';
            break;
        case PieceType::King:
            pieceChar = 'K';
            break;
        default:
            pieceChar = ' ';
            break;
    }

    vector<vector<char>> array = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', pieceChar, ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    return array;
}

