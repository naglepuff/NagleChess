#include <iostream>
#include "../include/Rook.h"

using namespace std;

bool GenerateRookMoves_Test1_NewGame();
bool GenerateRookMoves_Test2_Blocked();
bool GenerateRookMoves_Test3_Empty();

int main() {

    string p = "pass";
    string f = "fail";

    cout << "New Game: " << (GenerateRookMoves_Test1_NewGame() ? p : f) << endl;
    cout << "Blocked:  " << (GenerateRookMoves_Test2_Blocked() ? p : f) << endl;
    cout << "Empty:    " << (GenerateRookMoves_Test3_Empty() ? p : f) << endl;
}

bool GenerateRookMoves_Test1_NewGame() {

    GameState state = GameState(FEN_START);
    vector<Move> moves = Rook::GenerateRookMoves(state);
    // black and white rooks move in the same direction, so we'll only do tests with white as active player
    return moves.size() == 0;
}

bool GenerateRookMoves_Test2_Blocked() {

    // this tests a rook blocked by friendly pieces
    // Case 1: Center, blocked on 4 sides
    // Case 2: Edge, blocked on 3 sides
    // Case 3: Corner, blocked on 2 sides

    bool res = true;

    string case1 = "8/8/3P4/2PRP3/3P4/8/8/8 w - - 0 1";
    string case2 = "8/8/P7/RP6/P7/8/8/8 w - - 0 1";
    string case3 = "RP6/P7/8/8/8/8/8/8 w - - 0 1";

    GameState state = GameState(case1);
    vector<Move> moves = Rook::GenerateRookMoves(state);
    res = res && (moves.size() == 0);

    state = GameState(case2);
    moves = Rook::GenerateRookMoves(state);
    res = res && (moves.size() == 0);

    state = GameState(case3);
    moves = Rook::GenerateRookMoves(state);
    return res && (moves.size() == 0);
}

bool GenerateRookMoves_Test3_Empty() {

    // test move generation for a rook on an empty board
    // Case 1: center, all 4 directions
    // Case 2: edge, 3 directions
    // Case 3: corner, 2 directions

    bool res = true;

    string case1 = "8/8/8/8/3R4/8/8/8 w - - 0 1";
    string case2 = "3R4/8/8/8/8/8/8/8 w - - 0 1";
    string case3 = "R7/8/8/8/8/8/8/8 w - - 0 1";

    GameState state = GameState(case1);
    vector<Move> moves = Rook::GenerateRookMoves(state);
    res = res && (moves.size() == 14);

    state = GameState(case2);
    moves = Rook::GenerateRookMoves(state);
    res = res && (moves.size() == 14);

    state = GameState(case3);
    moves = Rook::GenerateRookMoves(state);
    return res && (moves.size() == 14);
}