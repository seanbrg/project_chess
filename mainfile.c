#include "common.h"


void main()
{
	chessPos* position;
	pathTree allPathsTree;
	chessPosList* pathList;

	char* input;
	input = (char*)malloc(LINE * sizeof(char));
	CHECK_MALLOC(input);

	// get input and check it
	printf("Insert position: ");
	fgets(input, LINE, stdin);
	position = checkInput(input);
	if (position == NULL)
	{
		printf("Invalid input");
		free(input);
		exit(EXIT_FAILURE);
	}
	
	// calculate paths
	allPathsTree = findAllPossibleKnightPaths(position);
	pathList = findKnightPathCoveringAllBoard(&allPathsTree);
	if (pathList == NULL)
		printf("No path found");
	else
		display(pathList);

	freeTree(&allPathsTree);
	freePosList(pathList);
	free(position);
	free(input);
}