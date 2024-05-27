#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "chess.h"

#define KNIGHT_MOVES 8

/*~~~~~~~~~~~~~~~~~~~~~~~~Helper Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
chessPosArray*** initPosArray();
void calculateValidMoves(chessPosArray* posArray, int rowIndex, int columnIndex);
bool isValidPosition(int row, int column);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name: validKnightMoves

Description: calculate all valid knight moves for each position on a chessboard
Arguments: none
Return: array the contains the valid knight moves for the corresponding position on the chessboard
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
chessPosArray*** validKnightMoves() {

    chessPosArray*** posArray = initPosArray(); //initialize the array

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {

            calculateValidMoves(posArray[i][j], i, j);
        }
    }
    return posArray;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name: initPosArray

Description: initializes the array 
Arguments: none
Return: initialized array 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
chessPosArray*** initPosArray() {
    int i = 0;
    int j = 0;

    //allocate memory for the first dimension of the 3D array (rows)
    chessPosArray*** posArray = (chessPosArray***)malloc(ROW * sizeof(chessPosArray**));
    CHECK_MALLOC(posArray);

    for (int i = 0; i < ROW; ++i)
    {
        //allocate memory for the second dimension of the 3D array (columns)
        posArray[i] = (chessPosArray**)malloc(COLUMN * sizeof(chessPosArray*));
        CHECK_MALLOC(posArray[i]);

        for (int j = 0; j < COLUMN; ++j)
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

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name:isValidPosition 

Description: checks if a given position on a chessboard is valid(if it falls within the bounds of the chessboard)

Arguments: row - row index of the position to check
           column - column index of the position to check
Return: true if the position is within the bounds of the  chessboard, otherwise returns false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool isValidPosition(int row, int column) {
    return (row >= 0 && row < 8) && (column >= 0 && column < 8);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name:calculateValidMoves

Description: calculates all valid knight moves from a given position on a chessboard ans stores in the posArray
Arguments: posArray - pointer to a chessPosArray where the valid moves will be stored
           rowIndex - row index of the current position of the knight
           columnIndex - column index of the current position of the knight
Return:void
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
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
    chessPos* temp = (chessPos*)realloc(posArray->positions, count * sizeof(chessPos));
    if (temp != NULL) {
        posArray->positions = temp;
    }
    else {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}
//delete
void freePosArray(chessPosArray*** posArray) {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COLUMN; ++j) {

            free(posArray[i][j]->positions);
            free(posArray[i][j]);
        }
        free(posArray[i]);
    }
    free(posArray);
}