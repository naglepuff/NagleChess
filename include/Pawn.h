#include "./Move.h"
#include "./GameState.h"

class Pawn {

    public:
    static std::vector<Move> GeneratePawnMove(GameState state);
    //private:
    static uint64_t PotentialPawnMoveSquares(uint64_t position, PlayerColor color);
    static uint64_t PotentialPawnAttackSquares(uint64_t position, PlayerColor color);
    static std::vector<Move> GenerateSinglePawnMoves(GameState state, uint64_t onePawn, uint64_t moveSquares, uint64_t attackSquares); 
};