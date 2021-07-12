/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:18:13 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/30 15:18:15 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	go_right(t_tree *tree)
{
	if (ft_strrchr("0CE", tree->parsing.lab[tree->image.play_x]
			[tree->image.play_y - 1]))
	{
		if (tree->parsing.lab[tree->image.play_x]
			[tree->image.play_y - 1] == 'C')
		{
			tree->parsing.lab[tree->image.play_x]
			[tree->image.play_y - 1] = '0';
			tree->parsing.coll_count--;
		}
		if (tree->parsing.lab[tree->image.play_x]
			[tree->image.play_y - 1] == 'E' && tree->parsing.coll_count == 0)
		{
			victory_screen(tree);
			mlx_put_image_to_window(tree->vars.mlx, tree->vars.win,
				tree->image.img, 0, 0);
			return ;
		}
		tree->image.play_y = tree->image.play_y - 1;
		tree->image.move_count++;
		printf("move count = %i\n", tree->image.move_count);
	}
}

void	go_up(t_tree *tree)
{
	if (ft_strrchr("0CE", tree->parsing.lab[tree->image.play_x - 1]
			[tree->image.play_y]))
	{
		if (tree->parsing.lab[tree->image.play_x - 1]
			[tree->image.play_y] == 'C')
		{
			tree->parsing.lab[tree->image.play_x - 1]
			[tree->image.play_y] = '0';
			tree->parsing.coll_count--;
		}
		if (tree->parsing.lab[tree->image.play_x - 1]
			[tree->image.play_y] == 'E' && tree->parsing.coll_count == 0)
		{
			victory_screen(tree);
			mlx_put_image_to_window(tree->vars.mlx, tree->vars.win,
				tree->image.img, 0, 0);
			return ;
		}
		tree->image.play_x = tree->image.play_x - 1;
		tree->image.move_count++;
		printf("move count = %i\n", tree->image.move_count);
	}
}

void	go_left(t_tree *tree)
{
	if (ft_strrchr("0CE", tree->parsing.lab[tree->image.play_x]
			[tree->image.play_y + 1]))
	{
		if (tree->parsing.lab[tree->image.play_x]
			[tree->image.play_y + 1] == 'C')
		{
			tree->parsing.lab[tree->image.play_x]
			[tree->image.play_y + 1] = '0';
			tree->parsing.coll_count--;
		}
		if (tree->parsing.lab[tree->image.play_x]
			[tree->image.play_y + 1] == 'E' && tree->parsing.coll_count == 0)
		{
			victory_screen(tree);
			mlx_put_image_to_window(tree->vars.mlx, tree->vars.win,
				tree->image.img, 0, 0);
			return ;
		}
		tree->image.play_y = tree->image.play_y + 1;
		tree->image.move_count++;
		printf("move count = %i\n", tree->image.move_count);
	}
}

void	go_down(t_tree *tree)
{
	if (ft_strrchr("0CE", tree->parsing.lab[tree->image.play_x + 1]
			[tree->image.play_y]))
	{
		if (tree->parsing.lab[tree->image.play_x + 1]
			[tree->image.play_y] == 'C')
		{
			tree->parsing.lab[tree->image.play_x + 1]
			[tree->image.play_y] = '0';
			tree->parsing.coll_count--;
		}
		if (tree->parsing.lab[tree->image.play_x + 1]
			[tree->image.play_y] == 'E' && tree->parsing.coll_count == 0)
		{
			victory_screen(tree);
			mlx_put_image_to_window(tree->vars.mlx, tree->vars.win,
				tree->image.img, 0, 0);
			return ;
		}
		tree->image.play_x = tree->image.play_x + 1;
		tree->image.move_count++;
		printf("move count = %i\n", tree->image.move_count);
	}
}
