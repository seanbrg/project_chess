#ifndef __QUESTIONS_H
#define __QUESTIONS_H

#include "common.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Question 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*				validKnightMoves()
* Description:	calculate all valid knight moves for each position on a chessboard
* Arguments:	none
* Return:		array containing the valid knight moves from each position on the chessboard
*/
chessPosArray*** validKnightMoves();


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
*				takenTable	- 2D array of ints representing positions that were already stepped on
*				movesTable	- 3D array of chessPos representing allowed moves from each position
* Return:		none (it calls itself recursively until the tree is filled up)
*/
void knightPathsHelper(treeNode* root, int** takenTable, chessPosArray*** movesTable);


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Question 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*				findKnightPathCoveringAllBoard()
* Description:	given a paths tree, find in it a path that covers the whole board and return
*				it as a list of positions in order of the path. this is done by creating the list
*				as well as a variable for remembering the list's current length, then calling the
*				helper function to recursively backtrack over the tree to find a path in the right
*				length, while building the list as it does so
*				if the helper function returned 'false' then such a path does not exist
* Arguments:	path_tree	- pointer to a tree of paths
* Return:		pointer to a newly created chessPosList, NULL if the path doesn't exist
*/
chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree);


/*				pathCoveringBoardHelper()
* Description:	a recursive function that explores a tree representing paths and records the current
*				path it has taken in it as a linked list - 'lst' - and also records the length of
*				lst by adding/subtracting 1 to 'len' every time a new cell is added/removed.
*				when 'len' == ROWS * COLS, meaning the path covers the whole board, the recursion
*				ends, otherwise it will continue into the children of the current root.
*				if after exploring all children the function still didn't return, then it means the
*				current path is not the right one, thus the function backtracks - it removes the
*				cell it added in that same iteration from 'lst', thus allowing 'lst' to only record the
*				correct path
* Arguments:	root	- pointer to a treeNode currently handled as the root
*				lst		- pointer to an external chessPosList for saving the path
*				len		- pointer to an external variable remembering the length of 'lst'
* Return:		true if the right path was found, false otherwise
*/
bool pathCoveringBoardHelper(treeNode* root, chessPosList* lst, int* len);



#endif