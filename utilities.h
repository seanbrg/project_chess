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



/*
                                                                                   .--.
                                                                                   `.  \
                                                                                     \  \
                                                                                      .  \
                                                                                      :   .
                                                                                      |    .
                                                                                      |    :
                                                                                      |    |
                                      ..._  ___                                       |    |
                                     `."".`''''""--..___                              |    |
                                     ,-\  \             ""-...__         _____________/    |
                                     / ` " '                    `""""""""                  .
                                     \                                                      L
                                     (>                                                      \
                                    /                                                         \
                                    \_    ___..---.                                            L
                                      `--'         '.                                           \
                                                     .                                           \_
                                                    _/`.                                           `.._
                                                 .'     -.                                             `.
                                                /     __.-Y     /''''''-...___,...--------.._            |
   ,-"""-.                                     /   _."    |    /                ' .      \   '---..._    |
  /\     /\                                   /   /      /    /                _,. '    ,/           |   |
 |  |   |  |                                  \_,'     _.'   /              /''     _,-'            _|   |
  \/     \/                                           '     /               `-----''               /     |
   '-...-'                                            `...-'                                       `...-'                       
*/


// position
typedef char chessPos[2];


// array of positions
typedef struct _chessPosArray {
	unsigned int size;
	chessPos* positions;
} chessPosArray;


// cell in a list of positions
typedef struct _chessPosCell {
	chessPos position;
	struct _chessPosCell* next;
} chessPosCell;

// list of positions
typedef struct _chessPosList {
	chessPosCell* head;
	chessPosCell* tail;
} chessPosList;

// list of tree nodes
typedef struct _treeNodeList {
	struct _treeNodeListCell* head;
	struct _treeNodeListCell* tail;
} treeNodeList;

// tree node (has a list of tree nodes as its children)
typedef struct _treeNode {
	chessPos position;
	treeNodeList next_possible_positions;
} treeNode;

// tree
typedef struct _pathTree {
	treeNode* root;
} pathTree;

// cell in a list of tree nodes
typedef struct _treeNodeListCell {
	treeNode* node;
	struct _treeNodeListCell* next;
} treeNodeListCell;

#include "misc.h"
#include "questions.h"

#endif