#ifndef __CHESS_H
#define __CHESS_H

#include <stdbool.h>
#include <stdlib.h>

#define COLUMN 8
#define ROW 8

#define CHECK_MALLOC(pointer) if (pointer == NULL) { \
									printf("Memory allocation failed at function %s in %s", __func__, __FILE__); \
									exit(EXIT_FAILURE); } \

typedef char chessPos[2];

typedef struct _chessPosArray {
	unsigned int size;
	chessPos* positions;
} chessPosArray;

typedef struct _chessPosCell {
	chessPos position;
	struct _chessPosCell* next;
} chessPosCell;

typedef struct _chessPosList {
	chessPosCell* head;
	chessPosCell* tail;
} chessPosList;

typedef struct _treeNodeList {
	struct _treeNodeListCell* head;
	struct _treeNodeListCell* tail;
} treeNodeList;

typedef struct _treeNode {
	chessPos position;
	treeNodeList next_possible_positions;
} treeNode;

typedef struct _treeNodeListCell {
	treeNode* node;
	struct _treeNodeListCell* next;
} treeNodeListCell;

typedef struct _pathTree {
	treeNode* root;
} pathTree;

pathTree findAllPossibleKnightPaths(chessPos* startingPosition);


void display(chessPosList* lst);

chessPosArray*** validKnightMoves();

void freePosArray(chessPosArray*** posArray);

void removeNode(chessPosList* lst, chessPosCell* node, chessPosCell* prev);
void printBoard(chessPosList* lst);
int** initBoard();

#endif