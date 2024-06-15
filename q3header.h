#ifndef __Q3HEADER_H
#define __Q3HEADER_H

#include "utilities.h"

pathTree findAllPossibleKnightPaths(chessPos* startingPosition);

void findAllPossibleKnightPathsHelper(treeNode* root, int** takenTable, chessPosArray*** movesTable);

treeNode* createTreeNode(chessPos position);

#endif