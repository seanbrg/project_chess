#include "common.h"


// remove duplicates from a chessPos list and print as a board
void display(chessPosList* lst) 
{
	chessPosCell* node = lst->head;
	chessPosCell* check, * prev = NULL;

	while (node != NULL) // iterate over all the nodes in lst
	{
		check = lst->head;
		while (check != node) // find out if this node's position is
		{					 // identical to a previous node - "check"
			if (comparePos(check->position, node->position))
			{
				removePosCell(lst, node, prev);
				node = prev;
				break;
			}
			check = check->next;
		}
		prev = node;
		node = node->next;
	}
	printBoard(lst);
}


// print a board marked by lst
void printBoard(chessPosList* lst)
{
    int** board = initBoard(lst);
    int i = 1, j, x, y;
	chessPosCell* posNode = lst->head;

	while (posNode != NULL)		// fill up the 2D board array
	{
		y = posRow(posNode->position);
		x = posCol(posNode->position);
		board[y][x] = i;
		i++;
		posNode = posNode->next;
	}
	
	putchar(' ');				// print
	for (i = 1; i <= COLS; ++i)
	{
		printf("%3d", i);		// top row
	}
	putchar('\n');
	for (i = 0; i < ROWS; ++i)
	{
		printf("%c|", 'A' + i); // left column
		for (j = 0; j < COLS; ++j)
		{						// number in a cell
			if (board[i][j] != 0) printf("%2d|", board[i][j]);
			else printf("  |");
		}
		putchar('\n');
	}
	freeBoard(board);
}