#include "common.h"


// create a new tree node
treeNode* createTreeNode(chessPos position) {
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	CHECK_MALLOC(newNode);

	newNode->position[0] = position[0];
	newNode->position[1] = position[1];

	newNode->next_possible_positions.head = NULL;
	newNode->next_possible_positions.tail = NULL;

	return newNode;
}


// create new cell for a list of treeNodesS
treeNodeListCell* createNewRootCell(treeNode* data, treeNodeListCell* next)
{
	treeNodeListCell* res;
	res = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	CHECK_MALLOC(res);
	res->node = data;
	res->next = next;
	return res;
}


// make empty roots list
void makeEmptyRootList(treeNodeList* rootList)
{
	rootList->head = rootList->tail = NULL;
}


// check if a roots list is empty
bool isEmptyRootList(treeNodeList* lst)
{
	return (lst->head == NULL) ? true : false;
}


// insert cell to the end of a roots list
void insertRootCellToEnd(treeNodeList* lst, treeNodeListCell* node)
{
	if (isEmptyRootList(lst) == true)
	{
		node->next = NULL;
		lst->head = lst->tail = node;
	}
	else
	{
		lst->tail->next = node;
		node->next = NULL;
		lst->tail = node;
	}
}


// insert data (pointer to a treeNode) as a new cell to the end of a roots list
void insertRootDataToEnd(treeNodeList* lst, treeNode* data)
{
	treeNodeListCell* newTail;
	newTail = createNewRootCell(data, NULL);
	insertRootCellToEnd(lst, newTail);
}