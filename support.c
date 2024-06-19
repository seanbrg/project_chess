#include "common.h"


// check if user input is valid
chessPos* checkInput(char* string)
{
	// designate board boundaries
	char firstRow = 'A';
	char lastRow = firstRow + ROWS - 1;
	char firstCol = '1';
	char lastCol = firstCol + COLS - 1;

	if (strlen(string) == POS_LEN + 1) // valid input length
		if (string[0] <= lastRow && string[0] >= firstRow) // valid position on the board
			if (string[1] <= lastCol && string[1] >= firstCol)
			{
				chessPos* res;
				res = (chessPos*)malloc(sizeof(chessPos));
				CHECK_MALLOC(res);

				(*res)[0] = string[0];
				(*res)[1] = string[1];
				return res;
			}

	return NULL;
}


// free paths tree
void freeTree(pathTree* tr)
{

}



// free positions list
void freePosList(chessPosList* lst)
{

}



// free a 3D chessPosArray
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


// initialize an empty board of ints (2D array)
int** initBoard()
{
	int i = 0;
	int j = 0;

	int** board = (int**)malloc(ROWS * sizeof(int*));
	CHECK_MALLOC(board);
	for (int i = 0; i < ROWS; ++i)
	{
		board[i] = (int*)calloc(COLS, sizeof(int));
		CHECK_MALLOC(board[i]);
	}
	return board;
}


// free a 2D array of ints
void freeBoard(int** board)
{
	for (int i = 0; i < ROWS; ++i)
		free(board[i]);

	free(board);
}