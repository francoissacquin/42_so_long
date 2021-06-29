/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:44:34 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/28 12:01:31 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		printf("Error\nmissing information in the .ber file\n");
	else if (index == 7)
		printf("Error\nnumber of map collectibles less than one\n");
	else if (index == 8)
		printf("Error\nless than or more than one exit\n");
}

void	error_message_tex(int index)
{
	if (index == 1)
		printf("Error\nwrong texture format, not an XPM file\n");
	else if (index == 2)
		printf("Error\nno static char  * decalaration found in XPM file\n");
	else if (index == 3)
		printf("Error\nerror with color keys in XPM file\n");
	else if (index == 4)
		printf("Error\ninvalid color value in texture\n");
	else if (index == 5)
		printf("Error\nkey without corresponding color in xpm file\n");
	else if (index == 6)
		printf("Error\nunable to open texture (maybe wrong texture path)\n");
	else if (index == 7)
		printf("Error\ntransition from image to texture failed\n");
	else if (index == 8)
		printf("Error\nfailed to tranform texture *img to *xpm pointer\n");
}
