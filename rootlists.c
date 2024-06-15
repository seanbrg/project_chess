#include "utilities.h"

void makeEmptyRootList(treeNodeList* rootList)
{
	rootList->head = rootList->tail = NULL;
}


bool isEmptyRootList(treeNodeList* lst)
{
	return (lst->head == NULL) ? true : false;
}

treeNodeListCell* createNewRootCell(treeNode* data, treeNodeListCell* next)
{
	treeNodeListCell* res;
	res = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	CHECK_MALLOC(res);
	res->node = data;
	res->next = next;
	return res;
}

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

void insertRootDataToEnd(treeNodeList* lst, treeNode* data)
{
	treeNodeListCell* newTail;
	newTail = createNewRootCell(data, NULL);
	insertRootCellToEnd(lst, newTail);
}