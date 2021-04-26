#ifndef PIECEHELPER_H
#define PIECEHELPER_H

#include "./GameState.h"

class PieceHelper {

    public:
    static std::vector<Move> GenerateMoves(GameState& state, uint64_t pieceSquare, PlayerState& activePlayer, PlayerState& inactivePlayer, 
        const std::vector<int> dirs, PieceType pieceType);
    static void GenerateMovesMaxDistance();
    static void AddMove(GameState& state, std::vector<Move>& moves, Move move);
};

#endif /** PIECEHELPER_H **/