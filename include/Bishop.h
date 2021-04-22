#include "./GameState.h"

class Bishop {

    public:
    const static PieceType Type = PieceType::Bishop;
    const static std::vector<int> DIRS;
    static std::vector<Move> GenerateBishopMoves(GameState& state);

    static std::vector<Move> GenerateSingleBishopMoves(GameState& state);
};