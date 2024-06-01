#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "chess.h"

chessPosArray*** movesTable;

pathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
	pathTree tree;
	chessPosList ancestors;
	
	makeEmptyPosList(&ancestors);

	movesTable = validKnightMoves();
	tree.root = createTreeNode(startingPosition);
	tree.root = findAllPossibleKnightPathsHelper(tree.root, &tree, &ancestors);
	freePosArray(movesTable);
}

treeNode* findAllPossibleKnightPathsHelper(treeNode* root, chessPosList* ancestors)
{
	int row = root->position[0] - 'A';
	int column = root->position[1] - '1';

	chessPos currentPos = { row , column };
	insertPosDataToStart(ancestors, currentPos);
	
	makeEmptyRootList(&(root->next_possible_positions));

	// iterate over movesTable[row][column] - every position that doesnt appear in ancestors
	// becomes a new child in root->next possible positions

	// then call recursion for every child in root->next possible positions

	removePosCellFromStart(ancestors);
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