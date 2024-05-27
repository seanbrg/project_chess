#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "chess.h"

pathTree findAllPossibleKnightPaths(chessPos* startingPosition) {

	pathTree tree;
	chessPosArray*** validKnightMovesArr = validKnightMoves();

	tree.root = findAllPossibleKnightPathsHelper(startingPosition,tree.root, validKnightMovesArr);

	freePosArray(validKnightMovesArr);

}

treeNode* findAllPossibleKnightPathsHelper(chessPos* startingPosition,treeNode* node,const chessPosArray*** posArray) {
	int rowIndex = startingPosition[0] - 'A';
	int columnIndex = startingPosition[1] - '1';

	treeNode* root = createTreeNode(*startingPosition);

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

void freePosArray(chessPosArray*** posArray) {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COLUMN; ++j) {

			free(posArray[i][j]->positions);
			free(posArray[i][j]);
		}
		free(posArray[i]);
	}
	free(posArray);
}