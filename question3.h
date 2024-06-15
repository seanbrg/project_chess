#ifndef __QUESTION3_H
#define __QUESTION3_H

#include "utilities.h"

pathTree findAllPossibleKnightPaths(chessPos* startingPosition);

void knightPathsHelper(treeNode* root, int** takenTable, chessPosArray*** movesTable);

#endif