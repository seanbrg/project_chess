#ifndef __UTILITIES_H
#define __UTILITIES_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define COLUMN 8
#define ROW 8
#define KNIGHT_MOVES 8

#define CHECK_MALLOC(pointer) if (pointer == NULL) { \
									printf("Memory allocation failed at function %s in %s", __func__, __FILE__); \
									exit(EXIT_FAILURE); } \

// position
typedef char chessPos[2];


// array of positions
typedef struct _chessPosArray {
	unsigned int size;
	chessPos* positions;
} chessPosArray;


// list of positions
typedef struct _chessPosCell {
	chessPos position;
	struct _chessPosCell* next;
} chessPosCell;

typedef struct _chessPosList {
	chessPosCell* head;
	chessPosCell* tail;
} chessPosList;

// tree of positions - the children are saved in lists of tree nodes
typedef struct _treeNodeList {
	struct _treeNodeListCell* head;
	struct _treeNodeListCell* tail;
} treeNodeList;

typedef struct _treeNode {
	chessPos position;
	treeNodeList next_possible_positions;
} treeNode;

typedef struct _pathTree {
	treeNode* root;
} pathTree;

typedef struct _treeNodeListCell {
	treeNode* node;
	struct _treeNodeListCell* next;
} treeNodeListCell;





#endif