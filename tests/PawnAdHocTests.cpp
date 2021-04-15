#include <iostream>
#include "../include/Pawn.h"

using namespace std;

bool GeneratePawnMoves_Test1_NewGame();
bool GeneratePawnMoves_Test2_Blocked();
bool GeneratePawnMoves_Test3_BlockedLong();
bool GeneratePawnMoves_Test4_OneCanCapture();
bool GeneratePawnMoves_Test5_FriendlyDiags();
bool GeneratePawnMoves_Test6_TwoCanCapture();
bool GeneratePawnMoves_Test7_EnPassant();
bool GeneratePawnMoves_Test8_Promotion();
bool GeneratePawnMoves_Test9_RegularMove();

// Test ideas:
// 4. single pawn promoting itself

int main() {

    string p = "pass";
    string f = "fail";
    cout << "New Game:         " << (GeneratePawnMoves_Test1_NewGame() ? p : f) << endl;
    cout << "Blocked:          " << (GeneratePawnMoves_Test2_Blocked() ? p : f) << endl;
    cout << "Blocked long:     " << (GeneratePawnMoves_Test3_BlockedLong() ? p : f) << endl;
    cout << "One pawn capture: " << (GeneratePawnMoves_Test4_OneCanCapture() ? p : f) << endl;
    cout << "Friendly on diag: " << (GeneratePawnMoves_Test5_FriendlyDiags() ? p : f) << endl;
    cout << "Two pawn capture: " << (GeneratePawnMoves_Test6_TwoCanCapture() ? p : f) << endl;
    cout << "En passant:       " << (GeneratePawnMoves_Test7_EnPassant() ? p : f) << endl;
    cout << "Promotion:        " << (GeneratePawnMoves_Test8_Promotion() ? p : f) << endl;
    cout << "Regular Moves:    " << (GeneratePawnMoves_Test9_RegularMove() ? p : f) << endl;
    return 0;
}

bool GeneratePawnMoves_Test1_NewGame() {
    /** Test starting pawn moves for each side */

    bool result = true;
    GameState state = GameState(FEN_START);
    vector<Move> pawnMoves = Pawn::GeneratePawnMoves(state);
    result = result && pawnMoves.size() == 16;
    string blackActive = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    state = GameState(blackActive);
    pawnMoves = Pawn::GeneratePawnMoves(state);
    return result && pawnMoves.size() == 16;
}

bool GeneratePawnMoves_Test2_Blocked() {
    /** Test when a pawn not in starting position is blocked by another piece from moving forward */ 
    bool result = true;
    string oppBlock = "8/8/8/5p2/5P2/8/8/8 w - - 0 1";
    string selfBlock = "8/8/8/5Q2/5P2/8/8/8 w - - 0 1";
    GameState state = GameState(oppBlock);
    vector<Move> pawnMoves = Pawn::GeneratePawnMoves(state);
    result = result && pawnMoves.size() == 0;
    state = GameState(selfBlock);
    pawnMoves = Pawn::GeneratePawnMoves(state);
    return result && pawnMoves.size() == 0;
}

bool GeneratePawnMoves_Test3_BlockedLong() {
    /** Test when a pawn in starting position can only move one square (no capture options) */
    bool result = true;
    vector<Move> pMoves;
    string oppBlock = "8/8/8/8/p7/8/P7/8 w - - 0 1";
    string selfBlock = "8/8/8/8/Q7/8/P7/8 w - - 0 1";

    GameState state = GameState(oppBlock);
    pMoves = Pawn::GeneratePawnMoves(state);
    result = result && pMoves.size() == 1;

    state = GameState(selfBlock);
    pMoves = Pawn::GeneratePawnMoves(state);
    return result && pMoves.size() == 1;

}

bool GeneratePawnMoves_Test4_OneCanCapture() {
    /** test generation of capture moves for a single white pawn (non EP) for these tests, the pawn is blocked from moving forward */ 

    bool result = true;
    string singleCapture = "8/8/8/4pp2/5P2/8/8/8 w - - 0 1";
    string doubleCapture = "8/8/8/4ppp1/5P2/8/8/8 w - - 0 1";
    vector<Move> pMoves;
    GameState state;

    state = GameState(singleCapture);
    pMoves = Pawn::GeneratePawnMoves(state);
    result = result && pMoves.size() == 1;

    state = GameState(doubleCapture);
    pMoves = Pawn::GeneratePawnMoves(state);
    return result && pMoves.size() == 2;
}

bool GeneratePawnMoves_Test5_FriendlyDiags() {
    /** test generation of moves when friendly pieces occupy diagonals of a pawn */

    string fen = "8/8/8/4BBB1/5P2/8/8/8 w - - 0 1";
    GameState state = GameState(fen);
    vector<Move> moves = Pawn::GeneratePawnMoves(state);
    return moves.size() == 0;
}

bool GeneratePawnMoves_Test6_TwoCanCapture() {
    /** Test when two pawns are attacking the same enemy piece */

    string fen = "8/8/8/ppp5/P1P5/8/8/8 w - - 0 1";
    GameState state = GameState(fen);
    vector<Move> moves = Pawn::GeneratePawnMoves(state);
    return moves.size() == 2;
}

bool GeneratePawnMoves_Test7_EnPassant() {
    /** test en passant capture given a gamestate with and without a valid target */

    bool result = true;
    string singleAttack = "8/8/8/1Pp5/8/8/8 w - c6 0 1";
    string doubleAttack = "8/8/8/1PpP4/8/8/8 w - c6 0 1";
    string fakeEnPassant = "8/8/8/1Pp5/8/8/8 w - - 0 1";
    GameState state;
    vector<Move> moves;

    state = GameState(singleAttack);
    moves = Pawn::GeneratePawnMoves(state);
    result = result && moves.size() == 2;

    state = GameState(fakeEnPassant);
    moves = Pawn::GeneratePawnMoves(state);
    result = result && moves.size() == 1;

    state = GameState(doubleAttack);
    moves = Pawn::GeneratePawnMoves(state);
    return result && moves.size() == 4;
}

bool GeneratePawnMoves_Test8_Promotion() {

    string fenNoCap = "8/P7/8/8/8/8/8/8 w - - 0 1";
    string fenCap = "1p6/P7/8/8/8/8/8/8 w - - 0 1";
    string blackPro = "8/8/8/8/8/8/p7/8 b - - 0 1";
    bool result = true;
    GameState state;
    vector<Move> moves;

    state = GameState(fenNoCap);
    moves = Pawn::GeneratePawnMoves(state);
    result = result && moves.size() == 4;

    state = GameState(fenCap);
    moves = Pawn::GeneratePawnMoves(state);
    result = result && moves.size() == 8;

    state = GameState(blackPro);
    moves = Pawn::GeneratePawnMoves(state);
    result = result && moves.size() == 4;

    return result;

}

bool GeneratePawnMoves_Test9_RegularMove() {

    GameState state;
    bool result = true;
    vector<Move> moves;

    string whitePawn = "8/8/8/8/3P4/8/8/8 w - - 0 1";
    string blackPawn = "8/8/8/8/3p4/8/8/8 b - - 0 1";

    state = GameState(whitePawn);
    moves = Pawn::GeneratePawnMoves(state);
    uint64_t endSquare = moves[0].endingSquare;
    result = result && (moves.size() == 1) && (endSquare == state.RankAndFileToBitboard("d5"));

    state = GameState(blackPawn);
    moves = Pawn::GeneratePawnMoves(state);
    endSquare = moves[0].endingSquare;
    result = result && (moves.size() == 1) && (endSquare == state.RankAndFileToBitboard("d3"));

    return result;
}