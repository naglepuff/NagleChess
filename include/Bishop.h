#include "./GameState.h"
#include "./PieceHelper.h"

class Bishop {

    public:
    const static PieceType Type = PieceType::Bishop;
    const static std::vector<int> DIRS;
    static std::vector<Move> GenerateBishopMoves(GameState& state);

    static std::vector<Move> GenerateSingleBishopMoves(GameState& state, uint64_t oneBishop, PlayerState& activePlayer, PlayerState& inactivePlayer);
};