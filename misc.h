#ifndef __MISC_H
#define __MISC_H

#include "utilities.h"

int posRow(chessPos pos);

int posCol(chessPos pos);

bool comparePos(chessPos A, chessPos B);

void makeEmptyRootList(treeNodeList* lst);

treeNode* createTreeNode(chessPos position);

treeNodeListCell* createNewRootCell(treeNode* data, treeNodeListCell* next);

bool isEmptyRootList(treeNodeList* lst);

void insertRootCellToEnd(treeNodeList* lst, treeNodeListCell* node);

void insertRootDataToEnd(treeNodeList* lst, treeNode* data);

void freePosArray(chessPosArray*** posArray);

bool isValidPosition(int row, int column);

void makeEmptyPosList(chessPosList* lst);

void removePosCell(chessPosList* lst, chessPosCell* node, chessPosCell* prev);

void removePosCellHead(chessPosList* lst);

chessPosCell* createNewPosCell(chessPos data, chessPosCell* next);

bool isEmptyPosList(chessPosList* lst);

void insertPosCellToStart(chessPosList* lst, chessPosCell* node);

void insertPosDataToStart(chessPosList* lst, chessPos data);

#endif