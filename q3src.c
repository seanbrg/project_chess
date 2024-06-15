#include "utilities.h"


// make a tree for all possible knight paths across the board
pathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
	pathTree tree;
	int** takenTable = initBoard(); // empty board of ints from q2
	// board of all valid moves from each point, from q1
	chessPosArray*** movesTable = validKnightMoves(); 
										
	tree.root = createTreeNode(startingPosition);
	knightPathsHelper(tree.root, takenTable, movesTable);

	freePosArray(movesTable);
	return tree;
}


// helper for making this tree recursively
void knightPathsHelper(treeNode* root, int** takenTable, chessPosArray*** movesTable)
{
	int i;
	int curRow = posRow(root->position);
	int curCol = posCol(root->position);
	takenTable[curRow][curCol] = 1; // mark current position as taken

	// check possible moves from current position
	chessPos* nextPosition = movesTable[curRow][curCol]->positions;
	int nextPosSize = movesTable[curRow][curCol]->size;

	makeEmptyRootList(&(root->next_possible_positions));
	for (i = 0; i < nextPosSize; ++i) // iterate on the possible moves
	{
		int nextRow = posRow(nextPosition + i);
		int nextCol = posCol(nextPosition + i);
		// make a new tree node if the next move's position is not taken
		if (takenTable[nextRow][nextCol] == 0)
		{
			treeNode* nextNode = createTreeNode(nextPosition + i);
			insertRootDataToEnd(&(root->next_possible_positions), nextNode);
		}
	}
	// call recursion upon every tree node that was previously created
	treeNodeListCell* nextNodeCell = root->next_possible_positions.head;
	while (nextNodeCell != NULL)
	{
		knightPathsHelper(nextNodeCell->node, takenTable, movesTable);
		nextNodeCell = nextNodeCell->next;
	}
	takenTable[curRow][curCol] = 0; // mark current position as untaken (for other paths)
}