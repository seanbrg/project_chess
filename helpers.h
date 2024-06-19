#ifndef __HELPERS_H
#define __HELPERS_H

#include "common.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~ Support (for Mainfile and various functions) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*				checkInput()
* Description:	check if user input is valid (of valid length and describing a position on the board)
* Arguments:	string - a string of user input which should be a position
* Return:		chessPos (two-char array) of the position if input valid (dynamically allocated)
*				NULL if input invalid
*/
chessPos* checkInput(char* string);


/*				freeTree()
* Description:	free all allocated memory in a tree, using recursions
* Arguments:	tr - pointer to a tree to free
* Return:		none
*/
void freeTree(pathTree* tr);


/*				freePosList()
* Description:	free all allocated memory in a positions list
* Argument:		lst - pointer to a positions list to free
* Return:		none
*/
void freePosList(chessPosList* lst);



/*				freePosArray()
* Description:	free the allocated memory of the chessPosArray
* Arguments:	posArray - a 3D array of chessPosArray (struct containing chessPos array and its size)
* Return:		none
*/
void freePosArray(chessPosArray*** posArray);

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



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Pos, Pos Lists Helpers ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*				isValidPosition()
* Description:	checks if a given position on a chessboard is valid
*				(if it falls within the bounds of the chessboard)
* Arguments:	row		- row index of the position to check
*				column	- column index of the position to check
* Return:		true/false
*/
bool isValidPosition(int row, int column);


/*				posRow()
* Description:	translate a chessPos to the (int) value of its row
* Arguments:	pos	 - a chessPos (array of 2 chars describing a position)
* Return:		the int value that pos's row would have on the board
*/
int posRow(chessPos pos);


/*				posCol()
* Description:	translate a chessPos to the (int) value of its column
* Arguments:	pos	 - a chessPos (array of 2 chars describing a position)
* Return:		the int value that pos's column would have on the board
*/
int posCol(chessPos pos);


/*				comparePos()
* Description:	check if two given positions are identical
* Arguments:	A, B - two positions on the board
* Return:		true if A == B, false if not
*/
bool comparePos(chessPos A, chessPos B);


/*				initPosArray()
* Description:	initializes a 3D array representing the board, with each position in the board
*				being itself an array of chessPos, used to store the allowed moves from each
*				position in the board
* Arguments:	none
* Return:		initialized 3D array of chessPos
*/
chessPosArray*** initPosArray();


/*				createNewPosCell()
* Description:	create a new cell for a positions list
* Arguments:	data, next - the two fields to save in the new cell
* Return:		pointer to a new (dynamically allocated) chessPosCell
*/
chessPosCell* createNewPosCell(chessPos data, chessPosCell* next);


/*				makeEmptyPosList()
* Description:	turn a positions list into an an empty one by forgetting its head and tail
* Arguments:	lst - pointer to a positions list
* Return:		none
*/
void makeEmptyPosList(chessPosList* lst);


/*				isEmptyPosList()
* Description:	check if lst is an empty positions list (has no head)
* Arguments:	lst - pointer to a positions list
* Return:		true if lst is empty, false otherwise
*/
bool isEmptyPosList(chessPosList* lst);


/*				insertPosCellToEnd()
* Description:	insert a given cell to the end of a positions list
* Arguments:	lst	 - pointer to a positions list
*				node - pointer to a positions list cell to insert
* Return:		none
*/
void insertPosCellToEnd(chessPosList* lst, chessPosCell* node);


/*				insertPosDataToEnd()
* Description:	insert a given chess position as a new cell to the end of a positions list
* Arguments:	lst	 - pointer to a positions list
*				data - chessPos to insert as a new cell to the end of lst
* Return:		none
*/
void insertPosDataToEnd(chessPosList* lst, chessPos data);


/*				removePosCell()
* Description:	remove a given cell from a positions list by linking the cell before it to the cell
*				after it, then freeing its dynamically allocated memory
* Arguments:	lst	 - pointer to a positions list
*				node - pointer to a cell to remove
*				prev - pointer to the cell that comes before node in lst (or NULL if node is first)
* Return:		none
*/
void removePosCell(chessPosList* lst, chessPosCell* node, chessPosCell* prev);



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Trees, Root Lists Helpers ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*				createTreeNode()
* Description:	create a new tree node for a position in the board
* Arguments:	position - a chessPos to save in the new node
* Return:		pointer to a new (dynamically allocated) treeNode
*/
treeNode* createTreeNode(chessPos position);


/*				createNewRootCell()
* Description:	create a new cell for a roots list
* Arguments:	data, next - the two fields to save in the new cell
* Return:		pointer to a new (dynamically allocated) treeNodeListCell
*/
treeNodeListCell* createNewRootCell(treeNode* data, treeNodeListCell* next);


/*				makeEmptyRootList()
* Description:	turn a roots list into an an empty one by forgetting its head and tail
* Arguments:	lst - pointer to a roots list
* Return:		none
*/
void makeEmptyRootList(treeNodeList* lst);


/*				isEmptyRoowList()
* Description:	check if lst is an empty roots list (has no head)
* Arguments:	lst - pointer to a roots list
* Return:		true if lst is empty, false otherwise
*/
bool isEmptyRootList(treeNodeList* lst);


/*				insertRootCellToEnd()
* Description:	insert a given cell to the end of a roots list
* Arguments:	lst	 - pointer to a roots list
*				node - pointer to a roots list cell to insert
* Return:		none
*/
void insertRootCellToEnd(treeNodeList* lst, treeNodeListCell* node);


/*				insertRootDataToEnd()
* Description:	insert a given tree node as a new cell to the end of a roots list
* Arguments:	lst	 - pointer to a roots list
*				data - pointer to a tree node to insert as a new cell to the end of lst
* Return:		none
*/
void insertRootDataToEnd(treeNodeList* lst, treeNode* data);


#endif