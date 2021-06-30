/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:18:33 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/30 18:10:36 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	divide_and_drawer(t_tree *tree)
{
	int		x;
	int		y;

	x = 0;
	while (tree->parsing.lab[x] != NULL)
	{
		y = 0;
		tree->draw.y = x * (tree->parsing.res_y / tree->image.map_x);
		tree->draw.y_max = (x + 1) * (tree->parsing.res_y / tree->image.map_x);
		while (tree->parsing.lab[x][y])
		{
			tree->draw.x = y * (tree->parsing.res_x / tree->image.map_y);
			tree->draw.x_max = (y + 1) * (tree->parsing.res_x / tree->image.map_y);
			if (tree->parsing.lab[x][y] == '1')
				draw_wall(tree);
			else if (tree->parsing.lab[x][y] == '0')
				draw_space(tree);
			else if (tree->parsing.lab[x][y] == 'C')
				draw_collectible(tree);
			else if (tree->parsing.lab[x][y] == 'E')
				draw_exit(tree);
			y++;
		}
		x++;
	}
	draw_player(tree);
}

void	draw_wall(t_tree *tree)
{
	int		x;
	int		y;

	x = tree->draw.x;
	while (x <= tree->draw.x_max)
	{
		tree->draw.tex_x = ((x - tree->draw.x) * 160) / (tree->draw.x_max - tree->draw.x);
		y = tree->draw.y;
		while (y <= tree->draw.y_max)
		{
			tree->draw.tex_y = ((y - tree->draw.y) * 160) / (tree->draw.y_max - tree->draw.y);
			tree->draw.color = tree->texture.tex_1[160 * tree->draw.tex_y + tree->draw.tex_x];
			my_mlx_pixel_put(&tree->image, x, y, tree->draw.color);
			y++;
		}
		x++;
	}
}

void	draw_space(t_tree *tree)
{
	int		x;
	int		y;

	x = tree->draw.x;
	while (x <= tree->draw.x_max)
	{
		tree->draw.tex_x = ((x - tree->draw.x) * 160) / (tree->draw.x_max - tree->draw.x);
		y = tree->draw.y;
		while (y <= tree->draw.y_max)
		{
			tree->draw.tex_y = ((y - tree->draw.y) * 160) / (tree->draw.y_max - tree->draw.y);
			tree->draw.color = tree->texture.tex_0[160 * tree->draw.tex_y + tree->draw.tex_x];
			my_mlx_pixel_put(&tree->image, x, y, tree->draw.color);
			y++;
		}
		x++;
	}

}

void	draw_collectible(t_tree *tree)
{
	int		x;
	int		y;

	x = tree->draw.x;
	while (x <= tree->draw.x_max)
	{
		y = tree->draw.y;
		tree->draw.tex_x = ((x - tree->draw.x) * 160) / (tree->draw.x_max - tree->draw.x);
		while (y <= tree->draw.y_max)
		{
			tree->draw.tex_y = ((y - tree->draw.y) * 160) / (tree->draw.y_max - tree->draw.y);
			tree->draw.color = tree->texture.tex_C[160 * tree->draw.tex_y + tree->draw.tex_x];
			my_mlx_pixel_put(&tree->image, x, y, tree->draw.color);
			y++;
		}
		x++;
	}
}

void	draw_exit(t_tree *tree)
{
	int		x;
	int		y;

	x = tree->draw.x;
	while (x <= tree->draw.x_max)
	{
		y = tree->draw.y;
		tree->draw.tex_x = ((x - tree->draw.x) * 160) / (tree->draw.x_max - tree->draw.x);
		while (y <= tree->draw.y_max)
		{
			tree->draw.tex_y = ((y - tree->draw.y) * 160) / (tree->draw.y_max - tree->draw.y);
			tree->draw.color = tree->texture.tex_E[160 * tree->draw.tex_y + tree->draw.tex_x];
			my_mlx_pixel_put(&tree->image, x, y, tree->draw.color);
			y++;
		}
		x++;
	}
}

void	draw_player(t_tree *tree)
{
	int		x;
	int		y;

	tree->draw.y = tree->image.play_x * (tree->parsing.res_y / tree->image.map_x);
	tree->draw.y_max = (tree->image.play_x + 1) * (tree->parsing.res_y / tree->image.map_x);
	tree->draw.x = tree->image.play_y * (tree->parsing.res_x / tree->image.map_y);
	tree->draw.x_max = (tree->image.play_y + 1) * (tree->parsing.res_x / tree->image.map_y);
	x = tree->draw.x;
	while (x <= tree->draw.x_max)
	{
		y = tree->draw.y;
		tree->draw.tex_x = ((x - tree->draw.x) * 792) / (tree->draw.x_max - tree->draw.x);
		while (y <= tree->draw.y_max)
		{
			tree->draw.tex_y = ((y - tree->draw.y) * 1008) / (tree->draw.y_max - tree->draw.y);
			tree->draw.color = tree->texture.tex_P[1008 * tree->draw.tex_y + tree->draw.tex_x];
			my_mlx_pixel_put(&tree->image, x, y, tree->draw.color);
			y++;
		}
		x++;
	}
}
