#ifndef __QUESTIONS_H
#define __QUESTIONS_H

#include "utilities.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Question 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*				validKnightMoves()
* Description:	calculate all valid knight moves for each position on a chessboard
* Arguments:	none
* Return:		array containing the valid knight moves from each position on the chessboard
*/
chessPosArray*** validKnightMoves();


/*				initPosArray()
* Description:	initializes a 3D array representing the board, with each position in the board
*				being itself an array of chessPos, used to store the allowed moves from each
*				position in the board
* Arguments:	none
* Return:		initialized 3D array of chessPos
*/
chessPosArray*** initPosArray();


/*				isValidPosition()
* Description:	checks if a given position on a chessboard is valid
*				(if it falls within the bounds of the chessboard)
* Arguments:	row		- row index of the position to check
*				column	- column index of the position to check
* Return:		true/false
*/
bool isValidPosition(int row, int column);


/*				calculateValidMoves()
* Description:	calculates all valid knight moves from a given position on the board
*				and stores them in posArray
* Arguments:	posArray - pointer to a chessPosArray where the valid moves will be stored
*				rowIndex - row index of the current position of the knight
*				columnIndex - column index of the current position of the knight
* Return:		none
*/
void calculateValidMoves(chessPosArray* posArray, int rowIndex, int columnIndex);



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Question 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*				display()
* Description:	remove duplicates from a chessPosList so that it can be printed on the board
*				with every position in lst appearing on it just once
* Arguments:	lst		- pointer to a chessPosList which has various previously calculated moves
* Return:		none
*/
void display(chessPosList* lst);


/*				printBoard()
* Description:	a function called inside display() to do the actual printing of the board
* Arguments:	lst		- pointer to a chessPosList that display() cleaned up
* Return:		none
*/
void printBoard(chessPosList* lst);


/*				initBoard()
* Description:	initialize a 2D array of ints full of 0s to act as an empty board
* Arguments:	none
* Return:		initialized 2D array 
*/
int** initBoard();


/*				freeBoard()
* Description:	free the 2D board of ints
* Arguments:	board - 2D board of ints to free
* Return:		none
*/
void freeBoard(int** board);



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Question 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*				findAllPossibleKnightPaths()
* Description:	make a tree for all possible knight paths across the board starting from a single
*				position, such that a path will not step on the same position in the board twice
* Arguments:	startingPosition - pointer to a chessPos from which the paths will be calculated
* Return:		a path tree of all possible paths
*/
pathTree findAllPossibleKnightPaths(chessPos* startingPosition);


/*				knightPathsHelper()
* Description:	helper for making the path tree recursively, by "remembering" during each path
*				which positions in the board were already stepped on (marked on takenTable with 1s)
*				and generating for each treeNode, representing a position, all of its allowed moves
*				based on these two tables as more nodes. the children of each node are saved into
*				a list in the node itself.
* Arguments:	root		- pointer to a treeNode currently acting as the root
*				takenTable	- 2D array of ints representing position that were already stepped on
*				movesTable	- 3D array of chessPos representing allowed moves from each position
* Return:		none (it calls itself recursively until the tree is filled up)
*/
void knightPathsHelper(treeNode* root, int** takenTable, chessPosArray*** movesTable);



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Question 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#endif