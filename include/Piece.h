#include "./StartingValues.h"



class Piece {
    protected:
        uint64_t position;
    public:
        uint64_t GetPosition();
        PieceType type; // actually might not need this, could use inheritance for piecetypes...
};