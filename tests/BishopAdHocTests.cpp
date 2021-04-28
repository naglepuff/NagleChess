#include <iostream>
#include "../include/Bishop.h"

using namespace std;

bool GenerateBishopMoves_Test1_NewGame();
bool GenerateBishopMoves_Test2_Corners();
bool GenerateBishopMoves_Test3_Empty();
bool GenerateBishopMoves_Test4_Blocked();
bool GenerateBishopMoves_Test5_Capture();

bool TestCase(string fen, int numMoves);

int main() {
    string p = "pass";
    string f = "fail";

    cout << "New Game: " << (GenerateBishopMoves_Test1_NewGame() ? p : f) << endl;
    cout << "Corners:  " << (GenerateBishopMoves_Test2_Corners() ? p : f) << endl;
    cout << "Empty:    " << (GenerateBishopMoves_Test3_Empty() ? p : f) << endl;
    cout << "Blocked:  " << (GenerateBishopMoves_Test4_Blocked() ? p : f) << endl;
    cout << "Capture:  " << (GenerateBishopMoves_Test5_Capture() ? p : f) << endl;
}

bool GenerateBishopMoves_Test1_NewGame() {

    return TestCase(FEN_START, 0);
}

bool GenerateBishopMoves_Test2_Corners() {

    string case1 = "B7/8/8/8/8/8/8/8 w - - 0 1";
    string case2 = "7B/8/8/8/8/8/8/8 w - - 0 1";
    string case3 = "8/8/8/8/8/8/8/7B w - - 0 1";
    string case4 = "8/8/8/8/8/8/8/B7 w - - 0 1";

    return (TestCase(case1, 7) && TestCase(case2, 7) && TestCase(case3, 7) && TestCase(case4, 7));
}

bool GenerateBishopMoves_Test3_Empty() {

    // empty board test cases along main light diag. testing dark diag seems redundant

    string case1 = "8/1B6/8/8/8/8/8/8 w - - 0 1";
    string case2 = "8/8/2B5/8/8/8/8/8 w - - 0 1";
    string case3 = "8/8/8/3B4/8/8/8/8 w - - 0 1";
    string case4 = "8/8/8/8/4B3/8/8/8 w - - 0 1";
    string case5 = "8/8/8/8/8/5B2/8/8 w - - 0 1";
    string case6 = "8/8/8/8/8/8/6B1/8 w - - 0 1";

    return TestCase(case1, 9) && TestCase(case2, 11) && TestCase(case3, 13)
            && TestCase(case4, 13) && TestCase(case5, 11) && TestCase(case6, 9);
}

bool GenerateBishopMoves_Test4_Blocked() {

    string case1 = "8/8/2P1P3/3B4/2P1P3/8/8/8 w - - 0 1"; // completely blocked
    string case2 = "8/1P3P2/8/3B4/8/1P3P2/8/8 w - - 0 1"; // can move 1 square in each direction
    
    return TestCase(case1, 0) && TestCase(case2, 4);
}

bool GenerateBishopMoves_Test5_Capture() {

    string case1 = "8/1p3p2/8/3B4/8/1p3p2/8/8 w - - 0 1"; // move 1 square or capture 2 squares away
    return TestCase(case1, 8);
}

bool TestCase(string fen, int numMoves) {

    GameState state = GameState(fen);
    vector<Move> moves = Bishop::GenerateBishopMoves(state);
    return (moves.size() == numMoves);
}