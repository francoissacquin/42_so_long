/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:39:59 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/25 15:51:57 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_struc_labyrinth(t_tree *tree)
{
	int		i;

	if (tree->parsing.lab != 0)
	{
		i = ft_strlen_array(tree->parsing.lab) + 1;
		tree->parsing.lab = send_help((char const **)tree->parsing.lab, i);
		tree->parsing.lab = 0;
	}
}

char	**send_help(char const **split, int abs)
{
	while (abs > 0)
	{
		abs--;
		free((void *)split[abs]);
	}
	free((void *)split);
	return (NULL);
}

int	ft_close(t_tree *tree)
{
	if (tree->image.img != 0)
		mlx_destroy_image(tree->vars.mlx, tree->image.img);
	mlx_destroy_image(tree->vars.mlx, tree->texture.img_P);
	mlx_destroy_image(tree->vars.mlx, tree->texture.img_C);
	mlx_destroy_image(tree->vars.mlx, tree->texture.img_E);
	mlx_destroy_image(tree->vars.mlx, tree->texture.img_1);
	mlx_destroy_image(tree->vars.mlx, tree->texture.img_0);
	mlx_destroy_image(tree->vars.mlx, tree->texture.img_V);
	mlx_destroy_window(tree->vars.mlx, tree->vars.win);
	mlx_destroy_display(tree->vars.mlx);
	mlx_loop_end(&tree->vars);
	free(tree->vars.mlx);
	free_struc_labyrinth(tree);
	free(tree->parsing.file_path);
	exit(EXIT_SUCCESS);
	return (0);
}
