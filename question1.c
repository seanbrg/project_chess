#include "common.h"


// calculate all valid knight moves for each position on a chessboard
chessPosArray*** validKnightMoves() {

    chessPosArray*** posArray = initPosArray(); // initialize the array

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {

            calculateValidMoves(posArray[i][j], i, j);
        }
    }
    return posArray;
}


// calculate all valid knight moves from a given position and save in posArray
void calculateValidMoves(chessPosArray* posArray, int rowIndex, int columnIndex) {
    // all physically possible moves for a knight relative to its starting position
    static const int moves[KNIGHT_MOVES][2] = 
                { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };

    posArray->positions = (chessPos*)malloc(KNIGHT_MOVES * sizeof(chessPos));
    CHECK_MALLOC(posArray->positions);

    int count = 0;

    for (int i = 0; i < KNIGHT_MOVES; ++i) {
        int newRowIndex = rowIndex + moves[i][0];
        int newColumnIndex = columnIndex + moves[i][1];

        // check if the new position is valid
        if (isValidPosition(newRowIndex, newColumnIndex)) {
            // store the valid position 
            posArray->positions[count][0] = newRowIndex + 'A';
            posArray->positions[count][1] = newColumnIndex + '1';

            ++count;
        }
    }
    posArray->size = count;
    // reallocate memory to fit the actual number of valid moves
    if (count != 0)
    {
        chessPos* temp = (chessPos*)realloc(posArray->positions, count * sizeof(chessPos));
        CHECK_MALLOC(temp);
        posArray->positions = temp;
    }
    else posArray->positions = NULL;
}