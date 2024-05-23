#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COLUMN 8
#define ROW 8

typedef char chessPos[2];

typedef struct chessPosArray
{
    unsigned int size;
    chessPos* positions;
}chessPosArray;


chessPosArray*** validKnightMoves();


/*~~~~~~~~~~~~~~~~~~~~~~~~Healper Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
chessPosArray*** initPosArray();
void calculateValidMoves(chessPosArray* posArray, int rowIndex, int columnIndex);

void main() {
    validKnightMoves();

}
chessPosArray*** validKnightMoves() {

    chessPosArray*** posArray = initPosArray();//init the array

    //calculateValidMoves(**posArray,0,0);

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf("the valid moves for square : (%d, %d)\n", i, j);
            calculateValidMoves(posArray[i][j], i, j);
        }

    }


    //calculate valid positions for each square

    //add to the chessPos *positions and update size;


}

chessPosArray*** initPosArray() {

    int i = 0;
    int j = 0;


    chessPosArray*** posArray = (chessPosArray***)malloc(8 * sizeof(chessPosArray**));
    if (posArray == NULL) {
        printf("memory allocation failed\n");
    }
    for (int i = 0; i < 8; ++i)
    {
        posArray[i] = (chessPosArray**)malloc(8 * sizeof(chessPosArray*));
        if (posArray[i] == NULL) {
            printf("memory allocation failed\n");
        }
        for (int j = 0; j < 8; ++j)
        {
            posArray[i][j] = (chessPosArray*)malloc(sizeof(chessPosArray));
            if (posArray[i][j] == NULL) {
                printf("memory allocation failed\n");
                return (EXIT_FAILURE);
            }
            posArray[i][j]->size = 0;
            posArray[i][j]->positions = NULL;
        }
    }

    return posArray;

}

bool isValidPosition(int row, int column) {
    return (row >= 0 && row < 8) && (column >= 0 && column < 8);
}

void calculateValidMoves(chessPosArray* posArray, int rowIndex, int columnIndex) {
    int moves[8][2] = { {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2} };

    posArray->positions = (chessPos*)malloc(8 * sizeof(chessPos));
    if (posArray->positions == NULL) {
        printf("Memory allocation failed\n");

    }

    int count = 0;

    for (int k = 0; k < 8; ++k) {
        int newRowIndex = rowIndex + moves[k][0];
        int newColumnIndex = columnIndex + moves[k][1];

        if (isValidPosition(newRowIndex, newColumnIndex)) {
            posArray->positions[count][0] = newRowIndex + 'A';
            posArray->positions[count][1] = newColumnIndex + '1';

            ++count;
        }
    }

    posArray->size = count;

    posArray->positions = (chessPos*)realloc(posArray->positions, count * sizeof(chessPos));
    if (posArray->positions == NULL) {
        printf("Memory allocation failed\n");

    }
    //delete later
    for (int j = 0; j < posArray->size; j++) {
        printf("(%c,%c)\t", posArray->positions[j][0], posArray->positions[j][1]);
    }
    printf("\n");
}