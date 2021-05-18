#include <iostream>
#include "../include/King.h" 

using namespace std;

bool GenerateKingMoves_Test1_NewGame();

bool TestCase(string fen, int numMoves);

int main() {

    string p = "pass";
    string f = "fail";

    cout << "New game: " << (GenerateKingMoves_Test1_NewGame() ? p : f) << endl;

    return 0;
}

bool GenerateKingMoves_Test1_NewGame() {

    return TestCase(FEN_START, 0);
}

bool TestCase(string fen, int numMoves) {

    GameState state = GameState(fen);
    vector<Move> moves = King::GenerateKingMoves(state);
    return (moves.size() == numMoves);
}