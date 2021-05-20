#include "../include/GameState.h"
using namespace std;
// game state business logic

/************************************
 * Constructors
 ************************************/
GameState::GameState(Fen fen) {
    RepositionFromFen(fen);
}
#pragma region Functions related to converting/repositioning from Arrays, FEN and bitboards
/*******************************************************************
 * Functions to convert between BB, vector, and FEN representations
 ******************************************************************/
void GameState::RepositionFromArray(vector<vector<char>> board) {

    // clearBoard function could be useful... for now just clear each player
    white.Clear();
    black.Clear();

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

void GameState::RepositionFromFen(Fen fen) {

    white = PlayerState(PlayerColor::White);
    black = PlayerState(PlayerColor::Black);

    BuildBitboardsFromFenString(fen.piecePlacement);
    activeColor = (fen.activeColor == "w") ? PlayerColor::White : PlayerColor::Black;
    SetCastlingOptionsFromFen(fen.castlingOptions);
    SetEnPassantTargetFromFen(fen.enPassantSquare);
    halfMoveClock = fen.halfmoveClock;
    fullMoves = fen.fullMoves;
}

void GameState::BuildBitboardsFromFenString(string pieceString) {
    /** 
     * For now, assume that the piece string is VALID.
    **/
    uint64_t currentBit = (uint64_t) 1 << 63;
    for(int i = 0; i < pieceString.size(); i++) {

        char currentChar = pieceString[i];

        if (currentChar - '0' > 0 && currentChar - '0' <= 8) {
            currentBit = currentBit >> (currentChar - '0');
        } else {
            switch (currentChar) {
                case 'P':
                    white.pawns |= currentBit;
                    break;
                case 'p':
                    black.pawns |= currentBit;
                    break;
                case 'B':
                    white.bishops |= currentBit;
                    break;
                case 'b':
                    black.bishops |= currentBit;
                    break;
                case 'N':
                    white.knights |= currentBit;
                    break;
                case 'n':
                    black.knights |= currentBit;
                    break;
                case 'R':
                    white.rooks |= currentBit;
                    break;
                case 'r':
                    black.rooks |= currentBit;
                    break;
                case 'Q':
                    white.queen |= currentBit;
                    break;
                case 'q':
                    black.queen |= currentBit;
                    break;
                case 'K':
                    white.king |= currentBit;
                    break;
                case 'k':
                    black.king |= currentBit;
                    break;
                case '/':
                default:
                    currentBit = currentBit << 1; // comnpensate for the universal shift at the end of this else clause
                    break;
            }
            currentBit = currentBit >> 1;
        }


    }
}

void GameState::SetCastlingOptionsFromFen(string castlingOptions) {

    white.canCastleKing = white.canCastleQueen = black.canCastleQueen = black.canCastleKing = false;
    
    for(int i = 0; i < castlingOptions.size(); i++) {

        char currentChar = castlingOptions[i];

        switch (currentChar)
        {
        case 'K':
            white.canCastleKing = true;
            break;
        case 'Q':
            white.canCastleQueen = true;
            break;
        case 'k':
            black.canCastleKing = true;
            break;
        case 'q':
            black.canCastleQueen = true;
            break;
        default:
            break;
        }
    }
}

void GameState::SetEnPassantTargetFromFen(string targetSquare) {

    enPassantTarget = RankAndFileToBitboard(targetSquare);
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
        uint64_t currentSquare = (uint64_t) 1 << i;

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

Fen GameState::GetFenRepresentation() {

    string pieces = GetFenPiecesString();
    string castlingOptions = GetFenCastlingString();

    return Fen(pieces, this->activeColor == PlayerColor::White ? "w" : "b", 
        castlingOptions, BitboardToAlgebraicSquare(this->enPassantTarget), this->halfMoveClock, this->fullMoves);
}

string GameState::GetFenPiecesString() {

    string pieces = "";
    vector<vector<char>> arrayRep = this->GetArrayRepresentation();

    int numEmptySquares = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {

            char currentChar = arrayRep[i][j];
            if(currentChar != ' ') {
                if(numEmptySquares > 0) {
                    pieces += to_string(numEmptySquares);
                    numEmptySquares = 0;
                }
                pieces += currentChar;
            } else {
                numEmptySquares++;
            }
        }

        if(numEmptySquares > 0) {
            pieces += to_string(numEmptySquares);
            numEmptySquares = 0;
        }
        if(i < 7) {
            pieces += "/";
        }
    }
    return pieces;
}

string GameState::GetFenCastlingString() {

    string options = "";
    if(this->white.canCastleKing) { options += "K"; }
    if(this->white.canCastleQueen) { options += "Q"; }
    if(this->black.canCastleKing) { options += "k"; }
    if(this->black.canCastleQueen) { options += "q"; }

    return options.size() > 0 ? options : FEN_PLACEHOLDER;
}

#pragma endregion
/************************************
 * General use functions
 ************************************/
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

    return PieceType::Piece_None;
}

void GameState::ClearBoard() {
    white.Clear();
    black.Clear();

    // TODO reset other properties?
}

string GameState::BitboardToAlgebraicSquare(uint64_t square) {

    if (square == 0) {
        return "";
    }

    int counter = 0; // how many times has 1 been shifted? i.e. square = 1 << counter
    while (square && square % 2 == 0) {
        
        square = square >> 1;
        counter++; 
    }

    if(square > 1) {
        // more than 1 bit set to 1
        return "";
    }

    char file = 'h' - (counter % 8);
    char rank = '0' + ((counter / 8) + 1);
    string algebraicSquare = "";
    algebraicSquare += file;
    algebraicSquare += rank;
    return algebraicSquare;
}

uint64_t GameState::RankAndFileToBitboard(string square) {

    if(square.size() != 2) {
        return (uint64_t) 0;
    }
    
    int file = (int) square[0] - 'a'; // 0-7
    int rank = (int) square[1] - '1'; // 0-7

    int shiftAmount = (7 - file) + (8 * rank);
    return (uint64_t) 1 << shiftAmount;
}

/************************************
 * To string + helper functions
 ************************************/
string GameState::ToString() {

    string straightLine = "  +---+---+---+---+---+---+---+---+\n";
    string boardString = straightLine;

    vector<vector<char>> array = GetArrayRepresentation();
    
    for(int i = 0; i < (int) array.size(); i++) {
        
        boardString = boardString + to_string(8 - i) + " " + GetRowString(array[i]);
        boardString = boardString + straightLine;
    }
    boardString = boardString + "    A   B   C   D   E   F   G   H\n";
    return boardString;
}

string GameState::GetRowString(vector<char> row) {
    
    string rowString = "|";

    for(int i = 0; i < (int) row.size(); i++) {
        rowString = rowString + " " + row[i] + " |";
    }
    return rowString + "\n";
}

/************************************
 * Game playing functions (stubs as of 4/14)
 ************************************/
void GameState::MakeMove(Move move) {
    // Todo
    // 1. actually make the move
    moveHistory.push(move);
    return;
}

Move GameState::UndoMove() {

    // undo the previous move and return it
    // TODO 
    // 1. Handle empty moveHistory
    // 2. actually undo the move
    Move lastMove = moveHistory.top();
    moveHistory.pop();
    return lastMove;
}

bool GameState::InactivePlayerInCheck() {

    // TODO: implement
    return true;
}

bool GameState::ActivePlayerInCheck() {
    //TODO: implements
    return true;
}

bool GameState::IsLegal(Move move) {

    MakeMove(move);
    bool legal = InactivePlayerInCheck();
    UndoMove();
    return legal;
}

/************************************
 * Validation and state checking
 ************************************/

bool GameState::PiecePlacementIsValid() {

    uint64_t whitePieces = white.GetOccupiedSquares();
    uint64_t blackPieces = black.GetOccupiedSquares();


    // if xor =/= or, then black and white both have a piece on the same square
    return white.PiecePlacementIsValid() && black.PiecePlacementIsValid() && ((whitePieces ^ blackPieces) == (whitePieces | blackPieces));

}