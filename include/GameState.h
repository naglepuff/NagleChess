// game state defs

#include "./PlayerState.h"
// #include <vector>
// #include <string>

enum GamePhase {
    Opening,
    Midgame,
    Endgame
};

class GameState {
    
    public:
        // constructor and destructor
        GameState() {
            phase = GamePhase::Opening;
            white = PlayerState(true);
            black = PlayerState(false);
        };
        GameState(Fen fen);
        // properties
        GamePhase phase;
        PlayerState white;
        PlayerState black;
        PlayerColor activeColor;
        int halfMoveClock;
        int fullMoves;
        uint64_t enPassantTarget;
        // methods
        std::vector<std::vector<char>> GetArrayRepresentation();
        void RepositionFromArray(std::vector<std::vector<char>> board);
        std::string GetFenRepresentation();
        void RepositionFromFen(Fen fen);
        void PrintBoard();
        void ClearBoard();
        std::string ToString();
    //private: // nothing actually private for now
        std::vector<char> GetOneRow(int rowNum);
        void BuildBitboardsFromFenString(std::string pieceString);
        void SetCastlingOptionsFromFen(std::string castlingOptions);
        void SetEnPassantTargetFromFen(std::string targetSquare);
        PlayerColor GetPlayerOnSquare(uint64_t square);
        PieceType GetPieceOnSquare(uint64_t square);
        std::string GetRowString(std::vector<char> row);

        std::string NotatedSquare(uint64_t square);
        char GetRankOfSquare(uint64_t square);
        char GetFileOfSquare(uint64_t square);
        uint64_t RankAndFileToBitboard(std::string square);
};