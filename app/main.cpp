#include <iostream>
#include "../include/GameState.h"
using namespace std;


// TODO: move menu stuff to its own files. Static functions would probably be ok?
// Should the whole game be controlled by a separate object? GameState probably shouldn't be asking for moves...
string GetFenStringFromUser();
void StartGame(); // load from file, type in FEN, or new game
void PlayGame(GameState state);

int main() {

    StartGame();

    //cout << Fen::IsValidFenString(FEN_START) << endl;


    return 0;
}

void StartGame() {
    // Starts a game of NagleChess
    // initial options are quit, new game, and FEN
    int option;
    GameState state;
    string fenString;
    cout << "\n***********************\n*WELCOME TO NAGLECHESS*\n***********************\n";
    cout << "MAIN MENU:" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Start from a position in FEN" << endl;
    cout << "\n\nHow would you like to start? (0 to quit): ";
    cin >> option;

    switch(option) {
        case 1:
            state = GameState(FEN_START);
            break;
        case 2:
            fenString = GetFenStringFromUser();
            if(fenString == "q") {return;}
            state = GameState(fenString);
            break;
        default:
            return;
    }

    PlayGame(state);
}

string GetFenStringFromUser() {

    cin.clear();
    cin.ignore(10000, '\n');

    string fenString = "";
    do {
        if(fenString.size() > 0) {
            cout << "The previously entered string was invalid." << endl;
        }

        cout << "Enter the FEN for the starting position (q to quit): ";
        getline(cin, fenString);

    } while(!Fen::IsValidFenString(fenString) && fenString != "q");
    
    return fenString;
}

void PlayGame(GameState state) {

    cout << state.ToString() << endl;
}