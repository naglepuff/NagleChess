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

vector<vector<char>> GameState::GetArrayRepresentation() {
    vector<vector<char>> board;

    for(int i = 7; i >= 0; i--) {
        
        vector<char> row = GetOneRow(i);
        board.push_back(row);
    }
    return board;
}

vector<char> GameState::GetOneRow(int rowNum) {
    
    if(rowNum < 0 || rowNum > 7) {
        return {' '};
    }

    vector<char> row;

    // row H on a chess board is represented here by rowNum=7
    int startVal = ((rowNum + 1) * 8) - 1;
    int endVal = (rowNum * 8);
    for(int i = startVal; i >= endVal; i--) {
        
        char currentSquarePiece = ' ';
        uint64_t currentSquare = 1 << i;

        PieceType pieceType = GetPieceOnSquare(currentSquare);
        PlayerColor playerOnSquare = GetPlayerOnSquare(currentSquare);

        switch(pieceType) {
            case PieceType::Pawn:
                currentSquarePiece = (playerOnSquare == PlayerColor::White ? 'P' : 'p');
                break;
            case PieceType::Bishop:
                currentSquarePiece = (playerOnSquare == PlayerColor::White ? 'B' : 'b');
                break;
            case PieceType::Knight:
                currentSquarePiece = (playerOnSquare == PlayerColor::White ? 'N' : 'n');
                break;
            case PieceType::Rook:
                currentSquarePiece = (playerOnSquare == PlayerColor::White ? 'R' : 'r');
                break;
            case PieceType::Queen:
                currentSquarePiece = (playerOnSquare == PlayerColor::White ? 'Q' : 'q');
                break;
            case PieceType::King:
                currentSquarePiece = (playerOnSquare == PlayerColor::White ? 'K' : 'k');
                break;
            case PieceType::Piece_None:
                currentSquarePiece = ' ';
                break;
        }   
        row.push_back(currentSquarePiece);
    }
    return row;

}

/**
 * Return the color of the player occupying a given square.
 * If no player has a piece on the given square, return PlayerColor::None.
 **/ 
PlayerColor GameState::GetPlayerOnSquare(uint64_t square) {

    if(white.AmIOnSquare(square)) {
        return PlayerColor::White;
    } else if(black.AmIOnSquare(square)) {
        return PlayerColor::Black;
    }
    return PlayerColor::Player_None;
}

PieceType GameState::GetPieceOnSquare(uint64_t square) {

    // yikes. for now.
    if (GetPlayerOnSquare(square) == PlayerColor::Player_None) {return PieceType::Piece_None;}
    if ((white.pawns + black.pawns) & square) {return PieceType::Pawn;}
    if ((white.bishops + black.bishops) & square) {return PieceType::Bishop;}
    if ((white.knights + black.knights) & square) {return PieceType::Knight;}
    if ((white.rooks + black.rooks) & square) {return PieceType::Rook;}
    if ((white.queen + black.queen) & square) {return PieceType::Queen;}
    if ((white.king + black.king) & square) {return PieceType::King;}
}
