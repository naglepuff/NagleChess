// game state defs

#include "./player_state.h"
#include <vector>

enum GamePhase {
    Opening,
    Midgame,
    Endgame
};

class GameState {
    
    public:
        // constructor and destructor
        GameState() {
            phase = GamePhase::Opening;
        };
        // properties
        GamePhase phase;
        PlayerState white;
        PlayerState black;
        int move_counter;
        // methods
        std::vector<std::vector<char>> GetArrayRepresentation();
        void RepositionFromArray(std::vector<std::vector<char>> board);
        void PrintBoard();
        void ClearBoard();
};