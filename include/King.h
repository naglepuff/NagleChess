#include "GameState.h"
#include "PieceHelper.h"

class King {
    public:
    const static PieceType Type = PieceType::King;
    const static std::vector<int> DIRS;

    static std::vector<Move> GenerateKingMoves(GameState& state);
    static std::vector<Move> GenerateCastlingMoves(GameState& state, uint64_t king, PlayerState& activePlayer, uint64_t occupiedSquares);
};
