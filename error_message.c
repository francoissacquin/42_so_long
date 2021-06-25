#include "so_long.h"

void	error_message_parsing(int index)
{
	if (index == 1)
		printf("Error\nincorrect open() or fd value\n");
}

void	error_message_map_parsing(int index, t_tree *tree)
{
	if (index == 1)
		printf("Error\n invalid character in labyrinth\n");
	else if (index == 3)
	{
		printf("Error\n failure of memory allocation\n");
		free_struc_labyrinth(tree);
	}
	else if (index == 4)
	{
		printf("Error\n several labyrinth detected\n");
		free_struc_labyrinth(tree);
	}
	else if (index == 5)
		printf("Error\nlabyrinth is missing from .ber file\n");
}

void	error_message_verify_map(int index)
{
	if (index == 1)
		printf("Error\ninvalid labyrinth, wall isolated from labyrinth\n");
	else if (index == 2)
		printf("Error\nzero or starting position on boundary of the labyrinth\n");
	else if (index == 3)
		printf("Error\ninvalid labyrinth, hole in the wall\n");
	else if (index == 4)
		printf("Error\nless than or more than one starting position\n");
	else if (index == 5)
		printf("Error\npart of the labyrinth is not reachable for the player\n");
	else if (index == 6)
		printf("Error\nmissing information in the .cub file\n");
}
