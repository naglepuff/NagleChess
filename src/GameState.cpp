#include "../include/GameState.h"
using namespace std;
// game state business logic

void GameState::RepositionFromArray(vector<vector<char>> board) {

    // clearBoard function could be useful...

    for(int i = 0; i < (int) board.size(); i++) {
        for(int j = 0; j < (int) board[i].size(); j++) {
            
            char currentSquare = board[i][j];
            int numShifts = (7 - j) + (8 * (7 - i));

            switch (currentSquare)
            {
                case 'P':
                    white.PlacePiece(PieceType::Pawn, numShifts);
                    break;
                case 'B':
                    white.PlacePiece(PieceType::Bishop, numShifts);
                    break;
                case 'N':
                    white.PlacePiece(PieceType::Knight, numShifts);
                    break;
                case 'R':
                    white.PlacePiece(PieceType::Rook, numShifts);
                    break;
                case 'Q':
                    white.PlacePiece(PieceType::Queen, numShifts);
                    break;
                case 'K':
                    white.PlacePiece(PieceType::King, numShifts);
                    break;
                case 'p':
                    black.PlacePiece(PieceType::Pawn, numShifts);
                    break;
                case 'b':
                    black.PlacePiece(PieceType::Bishop, numShifts);
                    break;
                case 'n':
                    black.PlacePiece(PieceType::Knight, numShifts);
                    break;
                case 'r':
                    black.PlacePiece(PieceType::Rook, numShifts);
                    break;
                case 'q':
                    black.PlacePiece(PieceType::Queen, numShifts);
                    break;
                case 'k':
                    black.PlacePiece(PieceType::King, numShifts);
                    break;
                default:
                    break;
            }
        }
    }
}