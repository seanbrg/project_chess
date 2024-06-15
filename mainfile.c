#include "utilities.h"

void main()
{
	//test for q2

	chessPosArray*** movesTable = validKnightMoves();

	chessPosList lst;
	makeEmptyPosList(&lst);

	
	for (int k = 0; k < movesTable[3][5]->size; ++k)
	{
		insertPosDataToStart(&lst, movesTable[3][5]->positions[k]);
	}
	

	for (int k = 0; k < movesTable[3][1]->size; ++k)
	{
		insertPosDataToStart(&lst, movesTable[3][1]->positions[k]);
	}

	display(&lst);
}