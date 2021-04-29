#include "./GameState.h"
#include "./PieceHelper.h"

class Queen {

    const static PieceType Type = PieceType::Queen;
    const static std::vector<int> DIRS;

    static std::vector<Move> GenerateQueenMoves(GameState& state);

    static std::vector<Move> GenerateSingleQueenMoves(GameState& state, uint64_t oneQueen, PlayerState& activePlayer, PlayerState& inactivePlayer); // a player could have more than one queen after a promotion
};