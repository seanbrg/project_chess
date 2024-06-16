#include "utilities.h"


void main()
{
	
	// test for q1	
	chessPosArray*** movesTable = validKnightMoves();

	printf("ALLOWED PATHS: \n");
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			printf("FOR (%c %c):\n", i + 'A', j + '1');
			for (int k = 0; k < movesTable[i][j]->size; ++k)
			{
				printf("(%c %c), ", movesTable[i][j]->positions[k][0], movesTable[i][j]->positions[k][1]);
			}
			putchar('\n');
		}
	}

	/*
	// test for q2
	chessPosList lst;
	makeEmptyPosList(&lst);
	for (int k = 0; k < movesTable[4][4]->size; ++k)
	{
		insertPosDataToStart(&lst, movesTable[4][4]->positions[k]);
	}
	for (int k = 0; k < movesTable[0][0]->size; ++k)
	{
		insertPosDataToStart(&lst, movesTable[0][0]->positions[k]);
	}
	display(&lst);
	
	// test for q3
	printf("\n\n\n CALCULATION: \n");
	int counter = 0;
	chessPos pos = { 'A', '1' };

	findAllPossibleKnightPaths(&pos, &counter);
	printf("COUNTER: %d", counter);
	*/


}