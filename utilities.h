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

void makeEmptyRootList(treeNodeList* lst);

treeNodeListCell* createNewRootCell(treeNode* data, treeNodeListCell* next);

bool isEmptyRootList(treeNodeList* lst);

void insertRootCellToEnd(treeNodeList* lst, treeNodeListCell* node);

void insertRootDataToEnd(treeNodeList* lst, treeNode* data);

void freePosArray(chessPosArray*** posArray);

bool isValidPosition(int row, int column);

void makeEmptyPosList(chessPosList* lst);

void removePosCellFromEnd(chessPosList* lst, chessPosCell* node, chessPosCell* prev);

void removePosCellFromStart(chessPosList* lst);

chessPosCell* createNewPosCell(chessPos data, chessPosCell* next);

bool isEmptyPosList(chessPosList* lst);

void insertPosCellToStart(chessPosList* lst, chessPosCell* node);

void insertPosDataToStart(chessPosList* lst, chessPos data);






/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name: validKnightMoves

Description: calculate all valid knight moves for each position on a chessboard
Arguments: none
Return: array the contains the valid knight moves for the corresponding position on the chessboard
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
chessPosArray*** validKnightMoves();


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name: initPosArray

Description: initializes the array
Arguments: none
Return: initialized array
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
chessPosArray*** initPosArray();


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name:isValidPosition

Description: checks if a given position on a chessboard is valid(if it falls within the bounds of the chessboard)

Arguments: row - row index of the position to check
		   column - column index of the position to check
Return: true if the position is within the bounds of the  chessboard, otherwise returns false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool isValidPosition(int row, int column);


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name:calculateValidMoves

Description: calculates all valid knight moves from a given position on a chessboard ans stores in the posArray
Arguments: posArray - pointer to a chessPosArray where the valid moves will be stored
		   rowIndex - row index of the current position of the knight
		   columnIndex - column index of the current position of the knight
Return:void
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void calculateValidMoves(chessPosArray* posArray, int rowIndex, int columnIndex);



void display(chessPosList* lst);

void printBoard(chessPosList* lst);

int** initBoard();


pathTree findAllPossibleKnightPaths(chessPos* startingPosition);

void findAllPossibleKnightPathsHelper(treeNode* root, int** takenTable, chessPosArray*** movesTable);

treeNode* createTreeNode(chessPos position);


#endif