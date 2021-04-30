#include <iostream>
#include "../include/Queen.h" 

using namespace std;

bool GenerateQueenMoves_Test1_NewGame();
bool GenerateQueenMoves_Test2_Empty();
bool GenerateQueenMoves_Test3_Blocked();
bool GenerateQueenMoves_Test4_Capture();

bool TestCase(string fen, int numMoves);

int main() {

    string p = "pass";
    string f = "fail";

    cout << "New Game: " << (GenerateQueenMoves_Test1_NewGame() ? p : f) << endl;
    cout << "Empty:    " << (GenerateQueenMoves_Test2_Empty() ? p : f) << endl;
    cout << "Blocked:  " << (GenerateQueenMoves_Test3_Blocked() ? p : f) << endl;
    cout << "Capture:  " << (GenerateQueenMoves_Test4_Capture() ? p : f) << endl;

    return 0;
}

bool GenerateQueenMoves_Test1_NewGame() {

    return TestCase(FEN_START, 0);
}

bool GenerateQueenMoves_Test2_Empty() {

    string case1 = "Q7/8/8/8/8/8/8/8 w - - 0 1"; // case 1-4: corners
    string case2 = "7Q/8/8/8/8/8/8/8 w - - 0 1";
    string case3 = "8/8/8/8/8/8/8/Q7 w - - 0 1";
    string case4 = "8/8/8/8/8/8/8/7Q w - - 0 1";
    string case5 = "8/8/8/8/3Q4/8/8/8 w - - 0 1"; //case 5: queen on d4

    return TestCase(case1, 21) && TestCase(case2, 21) && TestCase(case3, 21)
        && TestCase(case4, 21) && TestCase(case5, 27);
}

bool GenerateQueenMoves_Test3_Blocked() {
     
    string case1 = "8/8/8/2PPP3/2PQP3/2PPP3/8/8 w - - 0 1"; // fully blocked
    string case2 = "8/8/8/3P4/2PQP3/3P4/8/8 w - - 0 1"; // r/f blocked
    string case3 = "8/8/8/2P1P3/3Q4/2P1P3/8/8 w - - 0 1"; // diag. blocked
    string case4 = "8/8/1P1P1P2/8/1P1Q1P2/8/1P1P1P2/8 w - - 0 1"; // fully blocked, can move 1 in all directions

    return TestCase(case1, 0) && TestCase(case2, 13) && TestCase(case3, 14) && TestCase(case4, 8);
}

bool GenerateQueenMoves_Test4_Capture() {

    string case1 = "8/8/8/2ppp3/2pQp3/2ppp3/8/8 w - - 0 1"; // fully surrounded
    string case2 = "8/8/1p1p1p2/8/1p1Q1p2/8/1p1p1p2/8 w - - 0 1"; // fully surrounded, can move 1 in all directions, can capture 1 square beyond that

    return TestCase(case1, 8) && TestCase(case2, 16);

}

bool TestCase(string fen, int numMoves) {

    GameState state = GameState(fen);
    vector<Move> moves = Queen::GenerateQueenMoves(state);
    return (moves.size() == numMoves);
}