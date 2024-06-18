#include "utilities.h"


void main()
{
	chessPos* position;
	pathTree tree;
	chessPosList* list;

	char* input;
	input = (char*)malloc(LINE * sizeof(char));
	CHECK_MALLOC(input);

	printf("Insert position: ");
	fgets(input, LINE, stdin);
	position = checkInput(input);
	if (position == NULL)
	{
		printf("Invalid input");
		free(input);
		exit(EXIT_FAILURE);
	}
	
	tree = findAllPossibleKnightPaths(position);
	list = findKnightPathCoveringAllBoard(&tree);
	if (list == NULL)
		printf("No path found");
	else
		display(list);

	// free all
	free(position);
	free(input);
}