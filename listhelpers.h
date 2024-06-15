#ifndef __LISTHELPERS_H
#define __LISTHELPERS_H

#include "utilities.h"

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

#endif