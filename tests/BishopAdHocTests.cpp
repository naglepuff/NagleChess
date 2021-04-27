#include <iostream>
#include "../include/Bishop.h"

using namespace std;

bool GenerateBishopMoves_Test1_NewGame();
bool GenerateBishopMoves_Test2_Corners();

bool TestCase(string fen, int numMoves);

int main() {
    string p = "pass";
    string f = "fail";

    cout << "New Game: " << (GenerateBishopMoves_Test1_NewGame() ? p : f) << endl;
    cout << "Corners:  " << (GenerateBishopMoves_Test2_Corners() ? p : f) << endl;
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

bool TestCase(string fen, int numMoves) {

    GameState state = GameState(fen);
    vector<Move> moves = Bishop::GenerateBishopMoves(state);
    return (moves.size() == numMoves);
}