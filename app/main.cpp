#include <iostream>
#include "../include/GameState.h"
using namespace std;

void PrintBoard(GameState board);
void PrintRow(vector<char> row);

int main() {
    // ad hoc testing for now
    GameState state = GameState();
    // state.RepositionFromArray(single_pawn);
    cout << state.ToString();

    Fen fen = Fen(FEN_START);
    state.RepositionFromFen(fen);
    cout << state.ToString();

    return 0;
}

void PrintBoard(GameState board) {

    string straightLine = "---------------------------------";

    vector<vector<char>> array = single_pawn;
    // vector<vector<char>> array = board.GetArrayRepresentation();
    
    for(int i = 0; i < (int) array.size(); i++) {
        
        cout << straightLine << endl;
        PrintRow(array[i]);
    }

    cout << straightLine << endl;
    
}

void PrintRow(vector<char> row) {

    string toPrint = "|";

    for(int i = 0; i < (int) row.size(); i++) {
        // should probably doa size check on row, should be 8
        toPrint = toPrint + " " + row[i] + " |";
    }
    cout << toPrint << endl;
}