#include "utilities.h"

int posRow(chessPos pos)
{
	return pos[0] - 'A';
}

int posCol(chessPos pos)
{
	return pos[1] - '1';
}

bool comparePos(chessPos A, chessPos B)
{
	return (A[0] == B[0] && A[1] == B[1]);
}

void makeEmptyPosList(chessPosList* lst)
{
	lst->head = lst->tail = NULL;
}

bool isEmptyPosList(chessPosList* lst)
{
	return (lst->head == NULL) ? true : false;
}

void removePosCell(chessPosList* lst, chessPosCell* node, chessPosCell* prev)
{
	if (lst->tail == node)
		lst->tail = prev; // prev will be NULL if node is also head

	if (lst->head == node)
		lst->head = node->next;
	else prev->next = node->next;

	free(node);
}

void removePosCellHead(chessPosList* lst)
{
	if (!isEmptyPosList(lst))
	{
		chessPosList* curr = lst->head;

		if (lst->head == lst->tail)
			lst->head = lst->tail = NULL;
		else
			lst->head = lst->head->next;

		free(curr);
	}
}

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

void insertPosDataToEnd(chessPosList* lst, chessPos data)
{
	chessPosCell* newTail;
	newTail = createNewPosCell(data, NULL);
	insertPosCellToEnd(lst, newTail);
}

void removeLastPosCell(chessPosList* lst)
{
	chessPosCell* node = lst->head, * prev = NULL;

	if (node != lst->tail)
	{
		prev = lst->head;
		while (prev->next != lst->tail)
			prev = prev->next;
	}
	removePosCell(lst, node, prev);
}