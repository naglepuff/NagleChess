/**
 * Test for any constexpr in startingvalues.h
 **/

#include "../include/StartingValues.h"
#include <iostream>

using namespace std;

bool DirectionTest(int dir, uint64_t passCase, uint64_t exp, uint64_t failCase);
bool NextSquare_TestNorth();
bool NextSquare_TestEast();
bool NextSquare_TestSouth();
bool NextSquare_TestWest();
bool NextSquare_TestNE();
bool NextSquare_TestSE();
bool NextSquare_TestSW();
bool NextSquare_TestNW();

int main() {

    string p = "pass";
    string f = "fail";
    cout << "North results: " + (NextSquare_TestNorth() ? p : f) << endl;
    cout << "East results:  " + (NextSquare_TestEast() ? p : f) << endl;
    cout << "South results: " + (NextSquare_TestSouth() ? p : f) << endl;
    cout << "West results:  " + (NextSquare_TestWest() ? p : f) << endl;
    cout << "NE results:    " + (NextSquare_TestNE() ? p : f) << endl;
    cout << "SE results:    " + (NextSquare_TestSE() ? p : f) << endl; 
    cout << "SW results:    " + (NextSquare_TestSW() ? p : f) << endl;  
    
    return 0;
}

bool NextSquare_TestNorth() {

    uint64_t sq, exp, fail;
    sq = (uint64_t) 1 << 27; // test case 1: not on top edge
    exp = sq << 8;
    fail = (uint64_t) 1 << 60; // test case 2: top edge
    return DirectionTest(NORTH, sq, exp, fail);
}
bool NextSquare_TestEast() {

    uint64_t sq, exp, fail;
    sq = (uint64_t) 1 << 27; // test case 1: not on right edge
    exp = sq >> 1;
    fail = (uint64_t) 1; // test case 2: right edge
    return DirectionTest(EAST, sq, exp, fail);

}
bool NextSquare_TestSouth() {

    uint64_t sq, exp, fail;
    sq = (uint64_t) 1 << 27; // test case 1: not bottom
    exp = sq >> 8;
    fail = (uint64_t) 1 << 4; // test case 2: bottom
    return DirectionTest(SOUTH, sq, exp, fail);
}
bool NextSquare_TestWest() {

    uint64_t sq, exp, fail;
    sq = (uint64_t) 1 << 27; // test case 1: not left
    exp = sq << 1;
    fail = (uint64_t) 1 << 15; // test case 2: left
    return DirectionTest(WEST, sq, exp, fail);
}
bool NextSquare_TestNE() {

    uint64_t sq, exp, fail, fail2, fail3;
    sq = (uint64_t) 1 << 27; // test case 1: should pass
    exp = sq << 7;
    fail = (uint64_t) 1 << 60; // test case 2: top
    fail2 = (uint64_t) 1 << 8; // test case 3: right
    fail3 = (uint64_t) 1 << 56; // test case 3: top right corner
    bool otherCases = (NextSquare(fail2, NORTHEAST) == 0) && (NextSquare(fail3, NORTHEAST) == 0);
    return DirectionTest(NORTHEAST, sq, exp, fail) && otherCases;
}
bool NextSquare_TestSE() {

    uint64_t sq, exp, fail, fail2, fail3;
    sq = (uint64_t) 1 << 27; // test case 1: should pass
    exp = sq >> 9;
    fail = (uint64_t) 1 << 5; // test case 2: bottom
    fail2 = (uint64_t) 1 << 8; // test case 3: right
    fail3 = (uint64_t) 1; // test case 3: bottom right corner
    bool otherCases = (NextSquare(fail2, SOUTHEAST) == 0) && (NextSquare(fail3, SOUTHEAST) == 0);
    return DirectionTest(SOUTHEAST, sq, exp, fail) && otherCases;
}
bool NextSquare_TestSW() {

    uint64_t sq, exp, fail, fail2, fail3;
    sq = (uint64_t) 1 << 27; // test case 1: should pass
    exp = sq >> 7;
    fail = (uint64_t) 1 << 5; // test case 2: bottom
    fail2 = (uint64_t) 1 << 15; // test case 3: left
    fail3 = (uint64_t) 1 << 7; // test case 3: bottom left corner
    bool otherCases = (NextSquare(fail2, SOUTHWEST) == 0) && (NextSquare(fail3, SOUTHWEST) == 0);
    return DirectionTest(SOUTHWEST, sq, exp, fail) && otherCases;
}
bool NextSquare_TestNW() {

    uint64_t sq, exp, fail, fail2, fail3;
    sq = (uint64_t) 1 << 27; // test case 1: should pass
    exp = sq << 9;
    fail = (uint64_t) 1 << 60; // test case 2: top
    fail2 = (uint64_t) 1 << 15; // test case 3: left
    fail3 = (uint64_t) 1 << 63; // test case 3: top left corner
    bool otherCases = (NextSquare(fail2, NORTHWEST) == 0) && (NextSquare(fail3, NORTHWEST) == 0);
    return DirectionTest(NORTHWEST, sq, exp, fail) && otherCases;
}

// eh, probably should have passes an array/vector of bbs as fail cases instead of just 1...
bool DirectionTest(int dir, uint64_t passCase, uint64_t exp, uint64_t failCase) {

    bool res = true;
    res = (NextSquare(passCase, dir) == exp);
    res = (NextSquare(failCase, dir) == (uint64_t) 0);
    return res;
}
