// game state defs

#include "./player_state.h"

enum GamePhase {
    Opening,
    Midgame,
    Endgame
};

class GameState {
    
    public:
        // constructor and destructor
        GameState();
        // properties
        GamePhase phase;
        PlayerState white;
        PlayerState black;
        int move_counter;
};