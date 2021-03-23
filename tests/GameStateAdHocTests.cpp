/**
 * Ad-hoc testing for NagleChess, started before unit testing framework was decided.
 * As convention for these tests, a return value of true is pass and false is fail.
 **/

#include <iostream>
#include "../include/GameState.h"

using namespace std;

bool RepositionFromArray_AdHocTest1();

int main() {

    string p = "PASS";
    string f = "FAIL";
    cout << "Result for RepositionFromArray_AdHocTest1: " << (RepositionFromArray_AdHocTest1() ? p : f) << endl;
    return 0;
}

bool RepositionFromArray_AdHocTest1() {
    /** 
     * Test RepositionFromArray given an array with a single white pawn on D02.
     * A bitstring with a pawn in the D2 will evaluate to 4096.  
    **/

    GameState state = GameState();
    state.RepositionFromArray(single_pawn);
    return state.white.pawns == 4096;
}