/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:45:34 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/28 11:45:37 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	extract_tex(void **img, int **xpm, char *path, t_tree *tree)
{
	int		tab[5];

	*img = mlx_xpm_file_to_image(tree->vars.mlx, path, &tab[0], &tab[1]);
	if (*img == NULL)
		error_central_tex(6, tree);
	*xpm = (int *)mlx_get_data_addr(*img, &tab[2], &tab[3], &tab[4]);
	if (*xpm == NULL)
		error_central_tex(8, tree);
}

void	conveyor_tex(t_tree *tree)
{
	tree->texture.img_P = 0;
	tree->texture.img_C = 0;
	tree->texture.img_E = 0;
	tree->texture.img_1 = 0;
	tree->texture.img_0 = 0;
	tree->texture.tex_P = 0;
	tree->texture.tex_C = 0;
	tree->texture.tex_E = 0;
	tree->texture.tex_1 = 0;
	tree->texture.tex_0 = 0;
	extract_tex(&tree->texture.img_P, &tree->texture.tex_P, "textures/eagle.xpm", tree);
	extract_tex(&tree->texture.img_C, &tree->texture.tex_C, "textures/mossy.xpm", tree);
	extract_tex(&tree->texture.img_E, &tree->texture.tex_E, "textures/purplestone.xpm", tree);
	extract_tex(&tree->texture.img_1, &tree->texture.tex_1, "textures/redbrick.xpm", tree);
	extract_tex(&tree->texture.img_0, &tree->texture.tex_0, "textures/wood.xpm", tree);
}

int		main(int argc, char **argv)
{
	t_tree	tree;
	int		i;

	verify_file(argc, argv, &tree);
	init_struc(&tree);
	map_parsing(&tree);
	set_screen_resolution(&tree);
	i = 0;
	while (tree.parsing.lab[i] != NULL)
	{
		printf("//%s\n", tree.parsing.lab[i]);
		i++;
	}
	tree.vars.mlx = mlx_init();
	conveyor_tex(&tree);
	tree.vars.win = mlx_new_window(tree.vars.mlx, tree.parsing.res_x, tree.parsing.res_y, "so_long");
	init_vars(&tree);
	screen_manager(&tree);
	mlx_hook(tree.vars.win, 2, 1L << 0, &key_hook, &tree);
	mlx_hook(tree.vars.win, 33, 0L, ft_close, &tree);
	mlx_loop_hook(tree.vars.mlx, &screen_manager_2, &tree);
	mlx_do_sync(tree.vars.mlx);
	mlx_loop(tree.vars.mlx);
}
