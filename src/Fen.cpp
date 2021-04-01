#include "../include/Fen.h"
using namespace std;

void Fen::ParseString(string fenString) {

    // for now, assume valid FEN string. we should probably write a funtion to check validity at some point

    int position = fenString.find(FEN_DELIMITER);
    if(position == string::npos) {return;}
    piecePlacement = fenString.substr(0, position);
    fenString.erase(0, position + 1);
    
    position = fenString.find(FEN_DELIMITER);
    if(position == string::npos) {return;}
    activeColor = fenString.substr(0, position);
    fenString.erase(0, position + 1);

    position = fenString.find(FEN_DELIMITER);
    if(position == string::npos) {return;}
    castlingOptions = fenString.substr(0, position);
    fenString.erase(0, position + 1);

    position = fenString.find(FEN_DELIMITER);
    if(position == string::npos) {return;}
    enPassantSquare = fenString.substr(0, position);
    fenString.erase(0, position + 1);

    position = fenString.find(FEN_DELIMITER);
    if(position == string::npos) {return;}
    halfmoveClock = stoi(fenString.substr(0, position));
    fenString.erase(0, position + 1);

    fullMoves = stoi(fenString.substr(0, position));
}

string Fen::ToString() {
    
    // assumes no empty strings for now

    return piecePlacement + " " + activeColor + " " + castlingOptions
            + " " + enPassantSquare + " " + to_string(halfmoveClock) 
            + " " + to_string(fullMoves); 
}

bool Fen::IsValidFenString(string input) {

    Fen buildFen = Fen();
    buildFen.ParseString(input);

    if(buildFen.activeColor != "w" && buildFen.activeColor != "b") {
        return false;
    }

    string castle = buildFen.castlingOptions;
    for(int i = 0; i < castle.size(); i++) {
        if((castle[i] != 'k' && castle[i] != 'K' && castle[i] != 'q' && castle[i] != 'Q') || i > 3) {
            return false;
        }
    }

    string enPassant = buildFen.enPassantSquare;
    if((enPassant.size() == 2 && (enPassant[0] < 'a' || enPassant[0] > 'h' || enPassant[1] < '1' || enPassant[1] > '8'))
        || (enPassant.size() == 1 && enPassant[0] != '-') 
        || enPassant.size() > 2) {
        return false;
    }

    if(buildFen.halfmoveClock < 0) {return false;}

    if(buildFen.fullMoves < 1) {return false;} 


    return ValidPieceString(buildFen.piecePlacement);

}

bool Fen::ValidPieceString(string pieceString) {
    int count = 0;
    
    for(int i = 0; i < pieceString.size(); i++) {

        switch(pieceString[i]) {
            case 'P':
            case 'p':
            case 'B':
            case 'b':
            case 'N':
            case 'n':
            case 'R':
            case 'r':
            case 'Q':
            case 'q':
            case 'K':
            case 'k':
                count++;
                break;
            case '/':
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                count += (int) (pieceString[i] - '0');
                break;
            default:
                return false;
        }
    }
    return count == 64;
}

