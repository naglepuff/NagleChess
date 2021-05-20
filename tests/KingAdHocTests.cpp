#include <iostream>
#include "../include/King.h" 

using namespace std;

bool GenerateKingMoves_Test1_NewGame();
bool GenerateKingMoves_Test2_Empty();
bool GenerateKingMoves_Test3_Capture();
bool GenerateKingMoves_Test4_Castling();

bool TestCase(string fen, int numMoves);

int main() {

    string p = "pass";
    string f = "fail";

    cout << "New game: " << (GenerateKingMoves_Test1_NewGame() ? p : f) << endl;
    cout << "Empty:    " << (GenerateKingMoves_Test2_Empty() ? p : f) << endl;
    cout << "Capture:  " << (GenerateKingMoves_Test3_Capture() ? p : f) << endl;
    cout << "Castling: " << (GenerateKingMoves_Test4_Castling() ? p : f) << endl;
    return 0;
}

bool GenerateKingMoves_Test1_NewGame() {

    return TestCase(FEN_START, 0);
}

bool GenerateKingMoves_Test2_Empty() {

    // just a solo king on empty board (no castle options) 
    string case1 = "8/8/8/8/3K4/8/8/8 w - - 0 1";
    return TestCase(case1, 8);
}

bool GenerateKingMoves_Test3_Capture() {

    string case1 = "ppp5/pKp5/ppp5/8/8/8/8/8 w - - 0 1";
    return TestCase(case1, 8);
}

bool GenerateKingMoves_Test4_Castling() {

    // white king test cases
    string case1 = "8/8/8/8/8/8/PPPPPPPP/R3K2R w KQ - 0 1"; // 4 moves
    string case2 = "8/8/8/8/8/8/PPPPPPPP/R3K2R w K - 0 1"; // 3 moves
    string case3 = "8/8/8/8/8/8/PPPPPPPP/R3K2R w Q - 0 1"; // 3 moves
    string case4 = "8/8/8/8/8/8/PPPPPPPP/R3K2R w - - 0 1"; // 2 moves

    bool resultWhite = TestCase(case1, 4) && TestCase(case2, 3) && TestCase(case3, 3) && TestCase(case4, 2);
    if(!resultWhite) cout << "White castling failed.";

    string case5 = "r3k2r/pppppppp/8/8/8/8/8/8 b kq - 0 1"; // 4
    string case6 = "r3k2r/pppppppp/8/8/8/8/8/8 b k - 0 1"; // 3
    string case7 = "r3k2r/pppppppp/8/8/8/8/8/8 b q - 0 1"; // 3
    string case8 = "r3k2r/pppppppp/8/8/8/8/8/8 b - - 0 1"; // 2

    bool resultBlack = TestCase(case5, 4) && TestCase(case6, 3) && TestCase(case7, 3) && TestCase(case8, 2);

    return resultWhite && resultBlack;
    
    
}

bool TestCase(string fen, int numMoves) {

    GameState state = GameState(fen);
    vector<Move> moves = King::GenerateKingMoves(state);
    return (moves.size() == numMoves);
}