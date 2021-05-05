#include "../include/King.h"

using namespace std;

const vector<int> King::DIRS ({NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST});

vector<Move> King::GenerateKingMoves(GameState& state) {

    PlayerState activePlayer = state.white;
    PlayerState inactivePlayer = state.black;
    if(state.activeColor == PlayerColor::Black) {
        activePlayer = state.black;
        inactivePlayer = state.white;
    }

    uint64_t opponentSquares = inactivePlayer.GetOccupiedSquares();
    uint64_t ownSquares = activePlayer.GetOccupiedSquares();
    uint64_t occupiedSquares = opponentSquares | ownSquares;

    uint64_t kingSquare = activePlayer.king;
    vector<Move> kingMoves;

    for(int dir : DIRS) {

        uint64_t nextSquare = NextSquare(kingSquare, dir);
        if(nextSquare > 0 && !(nextSquare & occupiedSquares)) {
            // reversible king move
            Move move = Move(Type, activePlayer.color, kingSquare, nextSquare, false);
            PieceHelper::AddMove(state, kingMoves, move);
        } else if(nextSquare > 0 && (nextSquare & opponentSquares) > 0) {
            // king capture move
            Move move = Move(Type, activePlayer.color, kingSquare, nextSquare, true);
            PieceHelper::AddMove(state, kingMoves, move);
        }
    }

    vector<Move> castlingMoves = GenerateCastlingMoves(state, kingSquare, activePlayer, occupiedSquares);
    kingMoves.insert(kingMoves.end(), castlingMoves.begin(), castlingMoves.end());
    return kingMoves;
}

vector<Move> King::GenerateCastlingMoves(GameState& state, uint64_t king, PlayerState& activePlayer, uint64_t occupiedSquares) {

    PlayerColor activeColor = activePlayer.color;
    vector<Move> castleMoves;
    uint64_t startingSquare = (activeColor == PlayerColor::White) ? WHITE_KING : BLACK_KING;

    if(activePlayer.canCastleKing) {
        uint64_t castlePath = (activeColor == PlayerColor::White) ? CASTLE_W_KING : CASTLE_B_KING;
        uint64_t endingSquare = (activeColor == PlayerColor::White) ? state.RankAndFileToBitboard("g1") : state.RankAndFileToBitboard("g8");
        if((occupiedSquares & castlePath) > 0) {
            // and castle king side
            Move move = Move(MoveType::CastleKing, activeColor, startingSquare, endingSquare);
            PieceHelper::AddMove(state, castleMoves, move);
        }
    }

    if(activePlayer.canCastleQueen) {
        uint64_t castlePath = (activeColor == PlayerColor::White) ? CASTLE_W_QUEEN : CASTLE_B_QUEEN;
        uint64_t endingSquare = (activeColor == PlayerColor::White) ? state.RankAndFileToBitboard("c1") : state.RankAndFileToBitboard("c8");
        if((occupiedSquares & castlePath) > 0) {
            // add castle queen size
            Move move = Move(MoveType::CastleQueen, activeColor, startingSquare, endingSquare);
            PieceHelper::AddMove(state, castleMoves, move);
        }
    }

    return castleMoves;
}