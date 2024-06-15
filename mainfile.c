#include "utilities.h"

void main()
{
	//test for q1 func

    chessPosArray*** validKnightMovesArr = validKnightMoves();

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf("The square: (%c,%d)\n",'A' + i, j + 1);

            chessPosArray* posArray = validKnightMovesArr[i][j];

            for (int k = 0; k < posArray->size; k++) {

                printf("(%c,%c)\t", posArray->positions[k][0], posArray->positions[k][1]);
            }
            printf("\n\n");
        }
    }

    freePosArray(validKnightMovesArr);


	
}