/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:45:25 by fsacquin          #+#    #+#             */
/*   Updated: 2021/07/04 15:13:21 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	verify_file(int arg_num, char **arg, t_tree *tree)
{
	int		i;
	int		j;

	i = 0;
	tree->parsing.file_path = 0;
	if (arg_num != 2)
		error_central_general(1);
	while (arg[1][i])
		i++;
	if (!(&arg[1][i - 4] == ft_strnstr((char const *)arg[1], ".ber", i)))
		error_central_general(2);
	tree->parsing.file_path = (char *)malloc(sizeof(char) * (i + 3));
	tree->parsing.file_path[0] = '.';
	tree->parsing.file_path[1] = '/';
	i = 0;
	j = 2;
	while (arg[1][i])
		tree->parsing.file_path[j++] = arg[1][i++];
	tree->parsing.file_path[j] = '\0';
}

void	init_struc(t_tree *tree)
{
	tree->parsing.res_x = 0;
	tree->parsing.res_y = 0;
	tree->parsing.lab = 0;
	tree->parsing.starting_x = 0;
	tree->parsing.starting_y = 0;
	tree->image.img = 0;
}

void	set_screen_resolution(t_tree *tree)
{
	if (tree->image.map_x < 20 && tree->image.map_y < 11)
	{
		tree->parsing.res_x = tree->image.map_y * 100;
		tree->parsing.res_y = tree->image.map_x * 100;
	}
	else
	{
		if (tree->image.map_x >= ((56 * tree->image.map_y) / 100))
		{
			tree->parsing.res_y = 1080;
			tree->parsing.res_x = tree->image.map_y * (1080 / tree->image.map_x);
		}
		else
		{
			tree->parsing.res_x = 1920;
			tree->parsing.res_y = tree->image.map_x * (1920 / tree->image.map_y);
		}
	}
}

void	init_vars(t_tree *tree)
{
	tree->vars.right = 0;
	tree->vars.left = 0;
	tree->vars.up = 0;
	tree->vars.down = 0;
	tree->image.play_x = tree->parsing.starting_x;
	tree->image.play_y = tree->parsing.starting_y;
	tree->parsing.lab[tree->image.play_x][tree->image.play_y] = '0';
	tree->image.move_count = 0;
	tree->image.img = 0;
	tree->parsing.v_gate = 1;
}
