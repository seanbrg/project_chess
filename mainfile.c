#include "chess.h"
#include <stdio.h>

void main() {
	chessPosList lst;
	lst.head = lst.tail = NULL;
	printBoard(&lst);
}