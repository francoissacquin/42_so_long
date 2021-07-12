/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_drawer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:43:21 by fsacquin          #+#    #+#             */
/*   Updated: 2021/07/12 15:43:30 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_player(t_tree *tree)
{
	int		x;
	int		y;

	draw_player_calc(tree);
	x = tree->draw.x;
	while (x <= tree->draw.x_max)
	{
		y = tree->draw.y;
		tree->draw.tex_x = ((x - tree->draw.x) * 792)
			/ (tree->draw.x_max - tree->draw.x);
		while (y < tree->draw.y_max)
		{
			tree->draw.tex_y = ((y - tree->draw.y) * 1008)
				/ (tree->draw.y_max - tree->draw.y);
			tree->draw.color = tree->texture.tex_P[792 * tree->draw.tex_y
				+ tree->draw.tex_x];
			if (tree->draw.color >= 0)
				my_mlx_pixel_put(&tree->image, x, y, tree->draw.color);
			y++;
		}
		x++;
	}
}

void	draw_player_calc(t_tree *tree)
{
	tree->draw.y = tree->image.play_x * (tree->parsing.res_y
			/ tree->image.map_x);
	tree->draw.y_max = (tree->image.play_x + 1) * (tree->parsing.res_y
			/ tree->image.map_x);
	tree->draw.x = tree->image.play_y * (tree->parsing.res_x
			/ tree->image.map_y);
	tree->draw.x_max = (tree->image.play_y + 1) * (tree->parsing.res_x
			/ tree->image.map_y);
}
