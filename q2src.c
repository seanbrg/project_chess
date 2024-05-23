#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chess.h"

void display(chessPosList* lst)
{
	chessPosCell* node = lst->head;
	chessPosCell* check;
	chessPosList res;
	bool repeat;

	res.head = res.tail = NULL;

	while (node != NULL)
	{
		check = lst->head;
		repeat = false;
		while (check != node) // check that its not a repeating node
		{
			if (check->position == node->position)
				repeat = true;
		}
		if (!repeat); // copy node to res
	}

	// print res
}