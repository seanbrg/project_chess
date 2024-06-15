#include "utilities.h"


// remove duplicates from a chessPos list and print as a board
void display(chessPosList* lst) 
{
	chessPosCell* node = lst->head;
	chessPosCell* check, * prev = NULL;

	while (node != NULL) // iterate over all the nodes in lst
	{
		printf("%c %c", node->position[0], node->position[1]);
		check = lst->head;
		while (check != node) // find out if this node's position is
		{					 // identical to a previous node - "check"
			if (comparePos(check->position, node->position))
			{
				printf("removed!");
				removePosCell(lst, node, prev);
				node = prev;
				break;
			}
			prev = check;
			check = check->next;
		}
		prev = node;
		node = node->next;
		putchar('\n');
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
	for (i = 1; i <= COLS; ++i)
	{
		printf("%3d", i);        // top row
	}
	putchar('\n');
	for (i = 0; i < ROWS; ++i)
	{
		printf("%c|", 'A' + i);  // left column
		for (j = 0; j < COLS; ++j)
		{   // number in a cell
			if (board[i][j] != 0) printf("%.2d|", board[i][j]);
			else printf("  |");
		}
		putchar('\n');
	}

	for (i = 0; i < ROWS; ++i)
		free(board[i]);
	free(board);
}


// initialize an empty board of ints
int** initBoard() 
{
    int i = 0;
    int j = 0;

	int** board = (int***)malloc(ROWS * sizeof(int*));
    CHECK_MALLOC(board);
    for (int i = 0; i < ROWS; ++i)
    {
        board[i] = (int*)malloc(COLS * sizeof(int));
		CHECK_MALLOC(board[i]);
        for (int j = 0; j < COLS; ++j)
        {
			board[i][j] = 0;
        }
    }
    return board;
}