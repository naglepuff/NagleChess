#include "../include/Pawn.h"

using namespace std;

const std::vector<int> Pawn::CAPTURE_DIRS_B ({SOUTHEAST, SOUTHWEST});
const std::vector<int> Pawn::CAPTURE_DIRS_W ({NORTHEAST, NORTHWEST});

vector<Move> Pawn::GeneratePawnMoves(GameState& state) {

    PlayerState activePlayer = state.white;
    PlayerState inactivePlayer = state.black;
    if(state.activeColor == PlayerColor::Black) {
        activePlayer = state.black;
        inactivePlayer = state.white;
    }

    vector<Move> pawnMoves = vector<Move>();

    for(int i = 0; i < 64; i++) {
        uint64_t currentSquare = (uint64_t) 1 << i;
        
        if((activePlayer.pawns & currentSquare) >= 1) {
            vector<Move> singlePawnMoves = GenerateSinglePawnMoves(state, currentSquare, activePlayer, inactivePlayer);
            pawnMoves.insert(pawnMoves.end(), singlePawnMoves.begin(), singlePawnMoves.end());
        }
    }
    return pawnMoves;
}

vector<Move> Pawn::GenerateSinglePawnMoves(GameState& state, uint64_t onePawn, PlayerState& activePlayer, PlayerState& inactivePlayer) {

    // for each piece we have to do some stuff to get things like occupied squares... there's probably a better way to do this, with like a struct or something
    // to memoize this part
    vector<Move> singlePawnMoves;
    
    uint64_t opponentSquares = inactivePlayer.GetOccupiedSquares();
    uint64_t ownSquares = activePlayer.GetOccupiedSquares();
    uint64_t occupiedSquares = opponentSquares | ownSquares;
    int moveDirection = (activePlayer.color == PlayerColor::White) ? NORTH : SOUTH;
    
    uint64_t startingPosition = (activePlayer.color == PlayerColor::White) ? WHITE_PAWNS : BLACK_PAWNS;
    uint64_t promotionRank = (activePlayer.color == PlayerColor::White) ? TOP : BOTTOM;
    int maxDistance = ((onePawn & startingPosition) > 0) ? 2 : 1;
    
    // generate non-capture pawn moves
    int numSquaresMoved = 0;
    uint64_t currentSquare = onePawn; // copy onePawn into a starting position of sorts
    uint64_t nextSquare = NextSquare(currentSquare, moveDirection);
    
    while(numSquaresMoved < maxDistance && !(nextSquare & occupiedSquares)) {
        // add the move to the  list
        
        if((nextSquare & promotionRank)) {
            AddPromotionMoves(singlePawnMoves, onePawn, nextSquare, activePlayer.color, false);
        } else {
        
            Move move = Move(Pawn::Type, activePlayer.color, onePawn, nextSquare, false);
            if(state.IsLegal(move)) {
                singlePawnMoves.push_back(move);
            }
        }
        
        
        currentSquare = nextSquare;
        nextSquare = NextSquare(currentSquare, moveDirection);
        numSquaresMoved++;
    }

    // generate capturing pawn moves
    const vector<int> dirs = (moveDirection == NORTH) ? Pawn::CAPTURE_DIRS_W : Pawn::CAPTURE_DIRS_B;
    for(int dir : dirs) {

        nextSquare = NextSquare(onePawn, dir);
        if(nextSquare > 0) {
            
            Move move;
            if((nextSquare & opponentSquares)) {
                
                if((nextSquare & promotionRank)) {
                    AddPromotionMoves(singlePawnMoves, onePawn, nextSquare, activePlayer.color, true);
                } else {
                    move = Move(Pawn::Type, activePlayer.color, onePawn, nextSquare, true);
                }
            } else if(nextSquare == state.enPassantTarget) {
                move = Move(MoveType::EnPassantCapture, activePlayer.color, onePawn, nextSquare);
            }
            if(move.type != MoveType::MoveType_None && state.IsLegal(move)) {
                singlePawnMoves.push_back(move);
            } 
        }
    }


    return singlePawnMoves;
}

void Pawn::AddPromotionMoves(vector<Move>& singlePawnMoves, uint64_t start, uint64_t end, PlayerColor activeColor, bool isCapture) {

    Move queenPromo = Move(MoveType::Promotion, activeColor, start, end, PieceType::Queen, isCapture);
    Move rookPromo = Move(MoveType::Promotion, activeColor, start, end, PieceType::Rook, isCapture);
    Move knightPromo = Move(MoveType::Promotion, activeColor, start, end, PieceType::Knight, isCapture);
    Move bishopPromo = Move(MoveType::Promotion, activeColor, start, end, PieceType::Bishop, isCapture);

    singlePawnMoves.push_back(queenPromo);
    singlePawnMoves.push_back(rookPromo);
    singlePawnMoves.push_back(knightPromo);
    singlePawnMoves.push_back(bishopPromo);
}


