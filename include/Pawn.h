#include "./GameState.h"

class Pawn {

    public:
    const static PieceType Type = PieceType::Pawn;
    const static std::vector<int> CAPTURE_DIRS_B;
    const static std::vector<int> CAPTURE_DIRS_W;
    static std::vector<Move> GeneratePawnMoves(GameState& state);
    //private:
    static uint64_t PotentialPawnMoveSquares(uint64_t position, PlayerColor color);    // could be useful if we could generate some "Position" object...
    static uint64_t PotentialPawnAttackSquares(uint64_t position, PlayerColor color);
    static std::vector<Move> GenerateSinglePawnMoves(GameState& state, uint64_t onePawn, PlayerState& activePlayer, PlayerState& inactivePlayer); 
};
