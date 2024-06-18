#include "utilities.h"

// make a tree for all possible knight paths across the board from startingPosition
pathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
	pathTree tree;
	int** takenTable = initBoard(); // empty board of ints from q2
	// board of all valid moves from each point, from q1
	chessPosArray*** movesTable = validKnightMoves(); 
										
	tree.root = createTreeNode(*startingPosition);
	knightPathsHelper(tree.root, takenTable, movesTable);

	freeBoard(takenTable);
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
	chessPos* nextPositions = movesTable[curRow][curCol]->positions;
	int nextPosSize = movesTable[curRow][curCol]->size;

	makeEmptyRootList(&(root->next_possible_positions));
	for (i = 0; i < nextPosSize; ++i) // iterate on the possible moves
	{
		int nextRow = posRow(nextPositions[i]);
		int nextCol = posCol(nextPositions[i]);
		// make a new tree node if the next move's position is not taken
		if (takenTable[nextRow][nextCol] == 0)
		{
			treeNode* nextNode = createTreeNode(nextPositions[i]);

			//printf("(%c %c) -> (%c %c)\n", root->position[0], root->position[1], nextPositions[i][0], nextPositions[i][1]);
			
			insertRootDataToEnd(&(root->next_possible_positions), nextNode);
			knightPathsHelper(root->next_possible_positions.tail->node, takenTable, movesTable);
		}
	}
	takenTable[curRow][curCol] = 0; // mark current position as untaken (for other paths)
}