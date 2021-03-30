/**
 * Ad-hoc testing for NagleChess, started before unit testing framework was decided.
 * As convention for these tests, a return value of true is pass and false is fail.
 **/

#include <iostream>
#include "../include/GameState.h"

using namespace std;

#pragma region declarations

bool RepositionFromArray_AdHocTest1();
bool GetPlayerOnSquare_AdHocTest1();
bool GetPieceOnSquare_AdHocTest1();
bool GetPieceOnSquare_AdHocTest2();
bool SetCastlingOptionsFromFen_AdHocTest1();
bool SetCastlingOptionsFromFen_AdHocTest2();
bool SetCastlingOptionsFromFen_AdHocTest3();
bool RankAndFileToBitboard_AdHocTest1();
bool RankAndFileToBitboard_AdHocTest2();
bool RankAndFileToBitboard_AdHocTest3();
vector<vector<char>> CreateSinglePieceBoard(PieceType type);

#pragma endregion

int main() {

    string p = "PASS";
    string f = "FAIL";
    cout << "Result for RepositionFromArray_AdHocTest1: " << (RepositionFromArray_AdHocTest1() ? p : f) << endl;
    cout << "Result for GetPlayerOnSquare_AdHocTest1: " << (GetPlayerOnSquare_AdHocTest1() ? p : f) << endl;
    cout << "Result for GetPieceOnSquare_AdHocTest1(): " << (GetPieceOnSquare_AdHocTest1() ? p : f) << endl;
    cout << "Result for GetPieceOnSquare_AdHocTest2(): " << (GetPieceOnSquare_AdHocTest2() ? p : f) << endl;
    cout << "Result for SetCastlintOptionsFromFen_AdHocTest1(): " << (SetCastlingOptionsFromFen_AdHocTest1() ? p : f) << endl;
    cout << "Result for SetCastlintOptionsFromFen_AdHocTest2(): " << (SetCastlingOptionsFromFen_AdHocTest2() ? p : f) << endl;
    cout << "Result for SetCastlintOptionsFromFen_AdHocTest3(): " << (SetCastlingOptionsFromFen_AdHocTest3() ? p : f) << endl;
    cout << "Result for RankAndFileToBitboard_AdHocTest1(): " << (RankAndFileToBitboard_AdHocTest1() ? p : f) << endl;
    cout << "Result for RankAndFileToBitboard_AdHocTest2(): " << (RankAndFileToBitboard_AdHocTest2() ? p : f) << endl;
    cout << "Result for RankAndFileToBitboard_AdHocTest3(): " << (RankAndFileToBitboard_AdHocTest3() ? p : f) << endl;
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

#pragma region SetCastlingOptionsFromFen tests
bool SetCastlingOptionsFromFen_AdHocTest1() {

    string castlingOptions = "KQkq";
    GameState state = GameState();
    state.SetCastlingOptionsFromFen(castlingOptions);
    return state.white.canCastleKing && state.white.canCastleQueen && 
        state.black.canCastleKing && state.black.canCastleQueen;
}

bool SetCastlingOptionsFromFen_AdHocTest2() {

    string castlingOptions = "-";
    GameState state = GameState();
    state.SetCastlingOptionsFromFen(castlingOptions);
    return !state.white.canCastleKing && !state.white.canCastleQueen && 
        !state.black.canCastleKing && !state.black.canCastleQueen;
}

bool SetCastlingOptionsFromFen_AdHocTest3() {

    string castlingOptions = "Kk";
    GameState state = GameState();
    state.SetCastlingOptionsFromFen(castlingOptions);
    return state.white.canCastleKing && !state.white.canCastleQueen && 
        state.black.canCastleKing && !state.black.canCastleQueen;
}
#pragma endregion 

#pragma region RankAndFileToBitboard tests

bool RankAndFileToBitboard_AdHocTest1() {

    GameState state = GameState();
    uint64_t result = state.RankAndFileToBitboard("e4");
    uint64_t expected = ((uint64_t) 1 << 27);
    return expected == result;
}

bool RankAndFileToBitboard_AdHocTest2() {
    
    GameState state = GameState();
    uint64_t result = state.RankAndFileToBitboard("");
    uint64_t expected = 0;
    return expected == result;
}

bool RankAndFileToBitboard_AdHocTest3() {

    GameState state = GameState();
    uint64_t result = state.RankAndFileToBitboard("e44");
    uint64_t expected = 0;
    return expected == result;
}


#pragma endregion

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

