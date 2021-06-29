#include "so_long.h"

void	divide_and_drawer(t_tree *tree)
{
	int		x;
	int		y;

	x = 0;
	tree->draw.x_max = -1;
	while (tree->parsing.lab[x] != NULL)
	{
		y = 0;
		tree->draw.y_max = -1;
		tree->draw.x = tree->draw.x_max + 1;
		tree->draw.x_max = tree->draw.x_max + (tree->parsing.res_y / tree->image.map_x);
		while (tree->parsing.lab[x][y])
		{
			tree->draw.y = tree->draw.y_max + 1;
			tree->draw.y_max = tree->draw.y_max + (tree->parsing.res_x / tree->image.map_y);
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
}

void	draw_wall(t_tree *tree)
{
	int		x;
	int		y;

	x = tree->draw.x;
	y = tree->draw.y;
	while (x <= tree->draw.x_max)
	{
		tree->draw.tex_x = ((x - tree->draw.x) * 100) / (tree->draw.x_max - tree->draw_x);
		while (y <= tree->draw.y_max)
		{
			tree->draw.tex_y = ((y - tree->draw.y) * 100) / (tree->draw.y_max - tree->draw_y);
			tree->draw.color = tex->texture.tex_1[64 * tree->draw.tex_y + tree->draw.tex_x];
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
	y = tree->draw.y;
	while (x <= tree->draw.x_max)
	{
		tree->draw.tex_x = ((x - tree->draw.x) * 100) / (tree->draw.x_max - tree->draw_x);
		while (y <= tree->draw.y_max)
		{
			tree->draw.tex_y = ((y - tree->draw.y) * 100) / (tree->draw.y_max - tree->draw_y);
			tree->draw.color = tex->texture.tex_0[64 * tree->draw.tex_y + tree->draw.tex_x];
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
	y = tree->draw.y;
	while (x <= tree->draw.x_max)
	{
		tree->draw.tex_x = ((x - tree->draw.x) * 100) / (tree->draw.x_max - tree->draw_x);
		while (y <= tree->draw.y_max)
		{
			tree->draw.tex_y = ((y - tree->draw.y) * 100) / (tree->draw.y_max - tree->draw_y);
			tree->draw.color = tex->texture.tex_C[64 * tree->draw.tex_y + tree->draw.tex_x];
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
	y = tree->draw.y;
	while (x <= tree->draw.x_max)
	{
		tree->draw.tex_x = ((x - tree->draw.x) * 100) / (tree->draw.x_max - tree->draw_x);
		while (y <= tree->draw.y_max)
		{
			tree->draw.tex_y = ((y - tree->draw.y) * 100) / (tree->draw.y_max - tree->draw_y);
			tree->draw.color = tex->texture.tex_E[64 * tree->draw.tex_y + tree->draw.tex_x];
			my_mlx_pixel_put(&tree->image, x, y, tree->draw.color);
			y++;
		}
		x++;
	}
}
