#include "utilities.h"
#include "question3.h"
#include "listhelpers.h"

pathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
	pathTree tree;
	int** takenTable = initBoard();
	chessPosArray*** movesTable = validKnightMoves();

	tree.root = createTreeNode(startingPosition);
	findAllPossibleKnightPathsHelper(tree.root, takenTable, movesTable);

	return tree;
	freePosArray(movesTable);
}


void findAllPossibleKnightPathsHelper(treeNode* root, int** takenTable, chessPosArray*** movesTable)
{
	int i;
	int row = root->position[0] - 'A';
	int column = root->position[1] - '1';
	int nextRow, nextColumn;
	takenTable[row][column] = 1;

	treeNode* nextNode;
	treeNodeListCell* nextNodeCell;
	chessPos* nextPosition = movesTable[row][column]->positions;
	int nextPosSize = movesTable[row][column]->size;

	makeEmptyRootList(&(root->next_possible_positions));
	for (i = 0; i < nextPosSize; ++i)
	{
		nextRow = (nextPosition + i)[0] - 'A';
		nextColumn = (nextPosition + i)[1] - '1';

		if (takenTable[nextRow][nextColumn] == 0)
		{
			nextNode = createTreeNode(nextPosition + i);
			insertRootDataToEnd(&(root->next_possible_positions), nextNode);
		}
	}

	nextNodeCell = root->next_possible_positions.head;
	while (nextNodeCell != NULL)
	{
		findAllPossibleKnightPathsHelper(nextNodeCell->node, takenTable, movesTable);
		nextNodeCell = nextNodeCell->next;
	}
	takenTable[row][column] = 0;
}


treeNode* createTreeNode(chessPos position) {
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	CHECK_MALLOC(newNode);

	newNode->position[0] = position[0];
	newNode->position[1] = position[1];

	newNode->next_possible_positions.head = NULL;
	newNode->next_possible_positions.tail = NULL;

	return newNode;
}