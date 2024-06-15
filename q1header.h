#ifndef __Q1HEADER_H
#define __Q1HEADER_H

#include "utilities.h"

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

#endif