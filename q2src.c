#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "chess.h"

void display(chessPosList* lst)
{
	chessPosCell* node = lst->head;
	chessPosCell* check, *prev;

	while (node != NULL)
	{
		check = lst->head;
		prev = NULL;

		while (check != node) // find out if this node's position is
		{					 // identical to a previous node - "check"
			if (check->position == node->position)
				removeNode(lst, check, prev);
			prev = check;
			check = check->next;
		}
	}
	printBoard(lst);
}

void removeNode(chessPosList* lst, chessPosCell* node, chessPosCell* prev)
{
	if (lst->tail == node)
		lst->tail = prev; // prev will be NULL if node is also head

	if (lst->head == node)
		lst->head = node->next;
	else prev->next = node->next;

	free(node);
}

void printBoard(chessPosList* lst)
{
    int** board = initBoard(lst);
    int i = 1, j, x, y;
	chessPosCell* posNode = lst->head;

	while (posNode != NULL) // fill up the board array by the order of lst
	{
		y = posNode->position[0] - 'A';
		x = posNode->position[1] - '1';
		board[y][x] = i;
		i++;
		posNode = posNode->next;
	}
	
	putchar(' ');
	for (i = 1; i <= COLUMN; ++i)
	{
		printf("%3d", i);
	}
	putchar('\n');
	for (i = 0; i < ROW; ++i)
	{
		printf("%c|", 'A' + i);
		for (j = 0; j < COLUMN; ++j)
		{
			if (board[i][j] != 0) printf("%.2d|", board[i][j]);
			else printf("  |");
		}
		putchar('\n');
	}

	for (i = 0; i < ROW; ++i)
		free(board[i]);
	free(board);
}


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