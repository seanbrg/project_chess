#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chess.h"

void display(chessPosList* lst)
{
	chessPosCell* node = lst->head;
	chessPosCell* check;
	chessPosList posLst;
	bool repeat;

	posLst.head = posLst.tail = NULL; // empty list
	while (node != NULL)
	{
		check = lst->head;
		repeat = false;
		while (check != node) // find out if this node's position is identical
		{					 // to a previous node (tracked by "repeat")
			if (check->position == node->position) 
				repeat = true;
			check = check->next;
		}
		if (!repeat)   // if the node is not being repeated move it to posLst
			insertNodeToEndList(&posLst, node);
	}              
	*lst = posLst;    // because we ruined original lst's order, we turn it into posLst
	printBoard(&posLst);
}

void insertNodeToEndList(chessPosList* lst, chessPosCell* node)
{
	if (lst->head == NULL)
		lst->head = lst->tail = node;
	else
	{
		lst->tail->next = node;
		lst->tail = node;
	}
	node->next = NULL;
}

void printBoard(chessPosList* lst)
{

}