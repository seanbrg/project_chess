#include "common.h"


// check if a given position is in the board
bool isValidPosition(int row, int column) {
	return (row >= 0 && row < ROWS) && (column >= 0 && column < COLS);
}


// turn row of pos into int
int posRow(chessPos pos)
{
	return pos[0] - 'A';
}


// turn column of pos into int
int posCol(chessPos pos)
{
	return pos[1] - '1';
}


// compare two positions
bool comparePos(chessPos A, chessPos B)
{
	return (A[0] == B[0] && A[1] == B[1]);
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


// create new positions list cell
chessPosCell* createNewPosCell(chessPos data, chessPosCell* next)
{
	chessPosCell* res;
	res = (chessPosCell*)malloc(sizeof(chessPosCell));
	CHECK_MALLOC(res);
	res->position[0] = data[0];
	res->position[1] = data[1];
	res->next = next;
	return res;
}


// make empty positions list
void makeEmptyPosList(chessPosList* lst)
{
	lst->head = lst->tail = NULL;
}


// check if list is empty
bool isEmptyPosList(chessPosList* lst)
{
	return (lst->head == NULL) ? true : false;
}


// insert cell to the end of a positions list
void insertPosCellToEnd(chessPosList* lst, chessPosCell* node)
{
	if (isEmptyPosList(lst) == true)
	{
		node->next = NULL;
		lst->head = lst->tail = node;
	}
	else
	{
		lst->tail->next = node;
		node->next = NULL;
		lst->tail = node;
	}
}


// insert data (chessPos) as new cell to end of a positions list
void insertPosDataToEnd(chessPosList* lst, chessPos data)
{
	chessPosCell* newTail;
	newTail = createNewPosCell(data, NULL);
	insertPosCellToEnd(lst, newTail);
}


// remove cell from a positions list (requires previous cell)
void removePosCell(chessPosList* lst, chessPosCell* node, chessPosCell* prev)
{
	if (lst->tail == node)
		lst->tail = prev; // prev will be NULL if node is also head

	if (lst->head == node)
		lst->head = node->next;
	else prev->next = node->next;

	free(node);
}