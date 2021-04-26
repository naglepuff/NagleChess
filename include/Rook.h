#include "./GameState.h"
#include "./PieceHelper.h"

class Rook {

    public:
    const static PieceType Type = PieceType::Rook;
    const static std::vector<int> DIRS;
    static std::vector<Move> GenerateRookMoves(GameState& state);

    static std::vector<Move> GenerateSingleRookMoves(GameState& state, uint64_t oneRook, PlayerState& activePlayer, PlayerState& inactivePlayer);

};