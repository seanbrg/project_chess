#pragma once
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

void display(chessPosList* lst);

chessPosArray*** validKnightMoves();

/*~~~~~~~~~~~~~~~~~~~~~~~~Helper Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
chessPosArray*** initPosArray();
void calculateValidMoves(chessPosArray* posArray, int rowIndex, int columnIndex);
bool isValidPosition(int row, int column);

void removeNode(chessPosList* lst, chessPosCell* node, chessPosCell* prev);
void printBoard(chessPosList* lst);
int** initBoard();