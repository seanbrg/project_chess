#include "utilities.h"


// calculate all valid knight moves for each position on a chessboard
chessPosArray*** validKnightMoves() {

    chessPosArray*** posArray = initPosArray(); //initialize the array

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {

            calculateValidMoves(posArray[i][j], i, j);
        }
    }
    return posArray;
}


// initialize an empty array of chessPos
chessPosArray*** initPosArray() {
    int i = 0;
    int j = 0;

    //allocate memory for the first dimension of the 3D array (rows)
    chessPosArray*** posArray = (chessPosArray***)malloc(ROWS * sizeof(chessPosArray**));
    CHECK_MALLOC(posArray);

    for (int i = 0; i < ROWS; ++i)
    {
        //allocate memory for the second dimension of the 3D array (columns)
        posArray[i] = (chessPosArray**)malloc(COLS * sizeof(chessPosArray*));
        CHECK_MALLOC(posArray[i]);

        for (int j = 0; j < COLS; ++j)
        {
            //allocate memory for the third dimension (chessPosArray structs)
            posArray[i][j] = (chessPosArray*)malloc(sizeof(chessPosArray));
            CHECK_MALLOC(posArray[i][j]);

            posArray[i][j]->size = 0;
            posArray[i][j]->positions = NULL;
        }
    }
    return posArray;
}


// check if a given position is in the board
bool isValidPosition(int row, int column) {
    return (row >= 0 && row < ROWS) && (column >= 0 && column < COLS);
}


// calculate all valid knight moves from a given position and save in posArray
void calculateValidMoves(chessPosArray* posArray, int rowIndex, int columnIndex) {
    //all possible moves for a knight from any given position
    int moves[8][2] = { {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2} };

    posArray->positions = (chessPos*)malloc(KNIGHT_MOVES * sizeof(chessPos));
    CHECK_MALLOC(posArray->positions);

    int count = 0;

    for (int i = 0; i < KNIGHT_MOVES; ++i) {
        int newRowIndex = rowIndex + moves[i][0];
        int newColumnIndex = columnIndex + moves[i][1];

        //check if the new position is valid
        if (isValidPosition(newRowIndex, newColumnIndex)) {
            //store the valid position 
            posArray->positions[count][0] = newRowIndex + 'A';
            posArray->positions[count][1] = newColumnIndex + '1';

            ++count;
        }
    }
    posArray->size = count;
    //reallocate memory to fit the actual number of valid moves
    if (count != 0)
    {
        chessPos* temp = (chessPos*)realloc(posArray->positions, count * sizeof(chessPos));
        CHECK_MALLOC(temp);
        posArray->positions = temp;
    }
    else posArray->positions = NULL;
}


// free the array
void freePosArray(chessPosArray*** posArray) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {

            free(posArray[i][j]->positions);
            free(posArray[i][j]);
        }
        free(posArray[i]);
    }
    free(posArray);
}