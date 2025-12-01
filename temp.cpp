#include <iostream>
#include <tuple>

using namespace std;


int Chessboard[8][8] = {
        {-4, -3, -2, -5, -6, -2, -3, -4},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        {+1, +1, +1, +1, +1, +1, +1, +1},
        {+4, +3, +2, +5, +6, +2, +3, +4}
    };

tuple<int, int, int, int> PossiblePawnMoves[24];
tuple<int, int, int, int> PossibleKnightMoves[16];
tuple<int, int, int, int> PossibleBishopMoves[26];
tuple<int, int, int, int> PossibleRookMoves[28];
tuple<int, int, int, int> PossibleQueenMoves[27];
tuple<int, int, int, int> PossibleKingMoves[8];

int possibleMovesOfPawns() {
    int counter = 0;
    for (int line = 0; line < 8; line++) {
        for (int column = 0; column < 8; column++) {
            if (Chessboard[line][column] == 1) {
                if (Chessboard[line - 1][column - 1] < 0) {
                    PossiblePawnMoves[counter] = {line, column, line - 1, column - 1};
                    counter += 1;
                };
                if (Chessboard[line - 1][column + 1] < 0) {
                    PossiblePawnMoves[counter] = {line, column, line - 1, column + 1};
                    counter += 1;
                };
                if (Chessboard[line - 1][column] == 0) {
                    PossiblePawnMoves[counter] = {line, column, line - 1, column};
                    counter += 1;
                };
                if (line == 6) {
                    if (Chessboard[line - 1][column] == 0) {
                        if (Chessboard[line - 2][column] == 0) {
                            PossiblePawnMoves[counter] = {line, column, line - 2, column};
                            counter += 1;
                        };
                    };
                };
            };
        };
    };
    return 0;
};

int possibleMovesOfKnights() {
    int counter = 0;
    for (int line = 0; line < 8; line++) {
        for (int column = 0; column < 8; column++) {
            if (Chessboard[line][column] == 3) {
                if (-1 < (line - 2) < 8 && -1 < (column - 1) < 8) {
                    if (Chessboard[line - 2][column - 1] == 0) {
                        PossibleKnightMoves[counter] = {line, column, line - 2, column - 1};
                        counter += 1;
                    };
                };
                if (-1 < (line - 2) < 8 && -1 < (column + 1) < 8) {
                    if (Chessboard[line - 2][column + 1] == 0) {
                        PossibleKnightMoves[counter] = {line, column, line - 2, column + 1};
                        counter += 1;
                    };
                };
                if (-1 < (line - 1) < 8 && -1 < (column + 2) < 8) {
                    if (Chessboard[line - 1][column + 2] == 0) {
                        PossibleKnightMoves[counter] = {line, column, line - 1, column + 2};
                        counter += 1;
                    };
                };
                if (-1 < (line + 1) < 8 && -1 < (column + 2) < 8) {
                    if (Chessboard[line + 1][column + 2] == 0) {
                        PossibleKnightMoves[counter] = {line, column, line + 1, column + 2};
                        counter += 1;
                    };
                };
                if (-1 < (line + 2) < 8 && -1 < (column + 1) < 8) {
                    if (Chessboard[line + 2][column + 1] == 0) {
                        PossibleKnightMoves[counter] = {line, column, line + 2, column + 1};
                        counter += 1;
                    };
                };
                if (-1 < (line + 2) < 8 && -1 < (column - 1) < 8) {
                    if (Chessboard[line + 2][column - 1] == 0) {
                        PossibleKnightMoves[counter] = {line, column, line + 2, column - 1};
                        counter += 1;
                    };
                };
                if (-1 < (line + 1) < 8 && -1 < (column - 2) < 8) {
                    if (Chessboard[line + 1][column - 2] == 0) {
                        PossibleKnightMoves[counter] = {line, column, line + 1, column - 2};
                        counter += 1;
                    };
                };
                if (-1 < (line - 1) < 8 && -1 < (column - 2) < 8) {
                    if (Chessboard[line - 1][column - 2] == 0) {
                        PossibleKnightMoves[counter] = {line, column, line - 1, column - 2};
                        counter += 1;
                    };
                };
            };
        };
    };
    for (int nummber = 0; nummber < size(PossibleKnightMoves); nummber++) {
        if ((get<2>(PossibleKnightMoves[nummber]) < 0 || get<2>(PossibleKnightMoves[nummber]) > 7) || (get<3>(PossibleKnightMoves[nummber]) < 0 || get<3>(PossibleKnightMoves[nummber]) > 7)) {
            PossibleKnightMoves[nummber] = {0, 0, 0, 0};
        };
    };
    return 0;
};

int printingchessboard() {
    for (int line = 0; line < 8; line++) {
        for (int column = 0; column < 8; column++) {
            cout << Chessboard[line][column];
        };
        cout << endl;
    };
    return 0;
};    

int printingpossiblemoves() {
    for (int pawns = 0; pawns < std::size(PossiblePawnMoves); pawns++) {
        int pfirst = get<0>(PossiblePawnMoves[pawns]);
        int psecond = get<1>(PossiblePawnMoves[pawns]);
        int pthird = get<2>(PossiblePawnMoves[pawns]);
        int pforth = get<3>(PossiblePawnMoves[pawns]);
        cout << pfirst << psecond << endl << pthird << pforth << endl << endl;
    };
    for (int knights = 0; knights < std::size(PossiblePawnMoves); knights++) {
        int kfirst = get<0>(PossibleKnightMoves[knights]);
        int ksecond = get<1>(PossibleKnightMoves[knights]);
        int kthird = get<2>(PossibleKnightMoves[knights]);
        int kforth = get<3>(PossibleKnightMoves[knights]);
        cout << endl << endl << kfirst << ksecond << endl << kthird << kforth << endl << endl;
    };
    //for (int pawns = 0; pawns < size(PossiblePawnMoves); pawns++) {
        //int first = get<0>(PossibleBishopMoves[pawns]);
        //int second = get<1>(PossibleBishopMoves[pawns]);
        //int third = get<2>(PossibleBishopMoves[pawns]);
        //int forth = get<3>(PossibleBishopMoves[pawns]);
        //cout << first << second << endl << third << forth << endl << endl;    
    //};
    //for (int pawns = 0; pawns < size(PossiblePawnMoves); pawns++) {
        //int first = get<0>(PossibleRookMoves[pawns]);
        //int second = get<1>(PossibleRookMoves[pawns]);
        //int third = get<2>(PossibleRookMoves[pawns]);
        //int forth = get<3>(PossibleRookMoves[pawns]);
        //cout << first << second << endl << third << forth << endl << endl;
    //};
    //for (int pawns = 0; pawns < size(PossiblePawnMoves); pawns++) {
        //int first = get<0>(PossibleQueenMoves[pawns]);
        //int second = get<1>(PossibleQueenMoves[pawns]);
        //int third = get<2>(PossibleQueenMoves[pawns]);
        //int forth = get<3>(PossibleQueenMoves[pawns]);
        //cout << first << second << endl << third << forth << endl << endl;
    //};
    //for (int pawns = 0; pawns < size(PossiblePawnMoves); pawns++) {
        //int first = get<0>(PossibleKingMoves[pawns]);
        //int second = get<1>(PossibleKingMoves[pawns]);
        //int third = get<2>(PossibleKingMoves[pawns]);
        //int forth = get<3>(PossibleKingMoves[pawns]);
        //cout << first << second << endl << third << forth << endl << endl;
    //};
    return 0;
};

int main() {
    //startingpositionofpawns();
    //startingpositionofbishops();
    //startingpositionofknights();
    //startingpositionofkings();
    //startingpositionofrooks();
    //startingpositionofqueens();
    //startingpositionofkings();
    printingchessboard();
    possibleMovesOfPawns();
    possibleMovesOfKnights();
    printingpossiblemoves();
    return 0;
}