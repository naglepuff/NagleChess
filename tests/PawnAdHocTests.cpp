#include <iostream>
#include "../include/Pawn.h"

using namespace std;

bool GeneratePawnMoves_Test1_NewGame();

int main() {

    string p = "pass";
    string f = "fail";
    cout << "New Game: " << (GeneratePawnMoves_Test1_NewGame() ? p : f) << endl;
    return 0;
}

bool GeneratePawnMoves_Test1_NewGame() {

    GameState state = GameState(FEN_START);
    vector<Move> pawnMoves = Pawn::GeneratePawnMoves(state);
    return pawnMoves.size() == 16;
}
