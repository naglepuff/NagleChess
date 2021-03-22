#include <iostream>
#include "../include/GameState.h"
using namespace std;

void TestPrint();

int main() {
    // ad hoc testing for now
    GameState state = GameState();
    
    cout << state.white.pawns << endl; // should be 0

    state.RepositionFromArray(single_pawn);

    cout << state.white.pawns <<endl; // should be 32

    return 0;
}