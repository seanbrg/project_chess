#include "utilities.h"

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

bool pathCoveringBoardHelper(treeNode* root, chessPosList* lst, int* len)
{
	chessPosCell* prev = lst->tail;
	insertPosDataToEnd(lst, root->position);
	++(*len);
	chessPosCell* tail = lst->tail;

	if (*len == ROWS * COLS) return true;
	else
	{
		treeNodeListCell* nextMove = root->next_possible_positions.head;
		while (nextMove != NULL)
		{
			if (pathCoveringBoardHelper(nextMove->node, lst, len)) return true;
			nextMove = nextMove->next;
		}
	}

	removePosCell(lst, tail, prev);
	--(*len);
	return false;
}