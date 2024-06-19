#include "common.h"


// find in a path tree a path that covers the whole board
chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree)
{
	int len = 0;
	chessPosList *lst;
	lst = (chessPosList*)malloc(sizeof(chessPosList));
	CHECK_MALLOC(lst);
	makeEmptyPosList(lst);

	if (pathCoveringBoardHelper(path_tree->root, lst, &len)) return lst;
	else return NULL;
}


// helper for finding the path recursively
bool pathCoveringBoardHelper(treeNode* root, chessPosList* lst, int* len)
{
	chessPosCell* prev = lst->tail; // add current position to end of lst (and save it)
	insertPosDataToEnd(lst, root->position);
	++(*len);
	chessPosCell* tail = lst->tail;

	if (*len == ROWS * COLS)		// check if length of path is the whole board
		return true;
	else
	{
		treeNodeListCell* nextMove = root->next_possible_positions.head;
		while (nextMove != NULL)
		{
			if (pathCoveringBoardHelper(nextMove->node, lst, len)) return true;
			nextMove = nextMove->next;
		}
	}

	removePosCell(lst, tail, prev); // backtrack - remove current position from lst
	--(*len);
	return false;
}