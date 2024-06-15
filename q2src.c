#include "utilities.h"


// remove duplicates from a chessPos list and print as a board
void display(chessPosList* lst) 
{
	chessPosCell* node = lst->head;
	chessPosCell* check, *prev;

	while (node != NULL) // iterate over all the nodes in lst
	{
		check = lst->head;
		prev = NULL;
		while (check != node) // find out if this node's position is
		{					 // identical to a previous node - "check"
			if (check->position == node->position)
				removePosCellFromEnd(lst, check, prev);
			prev = check;
			check = check->next;
		}
	}
	printBoard(lst);
}


// print a board marked by lst
void printBoard(chessPosList* lst)
{
    int** board = initBoard(lst);
    int i = 1, j, x, y;
	chessPosCell* posNode = lst->head;

	while (posNode != NULL) // fill up the 2D board array
	{
		y = posRow(posNode->position);
		x = posCol(posNode->position);
		board[y][x] = i;
		i++;
		posNode = posNode->next;
	}
	
	putchar(' ');			// print this whole shebang
	for (i = 1; i <= COLUMN; ++i)
	{
		printf("%3d", i);        // top row
	}
	putchar('\n');
	for (i = 0; i < ROW; ++i)
	{
		printf("%c|", 'A' + i);  // left column
		for (j = 0; j < COLUMN; ++j)
		{   // number in a cell
			if (board[i][j] != 0) printf("%.2d|", board[i][j]);
			else printf("  |");
		}
		putchar('\n');
	}

	for (i = 0; i < ROW; ++i)
		free(board[i]);
	free(board);
}


// initialize an empty board of ints
int** initBoard() 
{
    int i = 0;
    int j = 0;

	int** board = (int***)malloc(ROW * sizeof(int*));
    CHECK_MALLOC(board);
    for (int i = 0; i < ROW; ++i)
    {
        board[i] = (int*)malloc(COLUMN * sizeof(int));
		CHECK_MALLOC(board[i]);
        for (int j = 0; j < COLUMN; ++j)
        {
			board[i][j] = 0;
        }
    }
    return board;
}