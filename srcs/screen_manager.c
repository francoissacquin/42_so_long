#include "../so_long.h"

int	screen_manager(t_tree *tree)
{
	if (tree->image.img != 0)
		mlx_destroy_image(tree->vars.mlx, tree->image.img);
	tree->image.img = mlx_new_image(tree->vars.mlx,
			tree->parsing.res_x, tree->parsing.res_y);
	tree->image.addr = mlx_get_data_addr(tree->image.img,
			&tree->image.bits_per_pixel, &tree->image.line_length,
			&tree->image.endian);
	divide_and_drawer(tree);
	return (0);
}

int	screen_manager_2(t_tree *tree)
{
	mlx_put_image_to_window(tree->vars.mlx,
		tree->vars.win, tree->image.img, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	victory_screen(t_tree *tree)
{
	ft_close(tree);
}
