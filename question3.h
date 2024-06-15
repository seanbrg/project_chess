#ifndef __QUESTION3_H
#define __QUESTION3_H

#include "utilities.h"

pathTree findAllPossibleKnightPaths(chessPos* startingPosition);

void findAllPossibleKnightPathsHelper(treeNode* root, int** takenTable, chessPosArray*** movesTable);

treeNode* createTreeNode(chessPos position);

#endif