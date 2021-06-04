#include "GameState.h"
#include "PieceHelper.h"

class Knight {
    
    public:
    const static PieceType Type = PieceType::Knight;
    // notice that a knight doesn't have any "DIRS" property

    static std::vector<Move> GenerateKnightMoves(GameState& state);
    static std::vector<Move> GenerateSingleKnightMoves(GameState& state, uint64_t oneKnight, PlayerState& activePlayer, PlayerState& inactivePlayer);
    
};