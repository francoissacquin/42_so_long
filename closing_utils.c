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

#include "so_long.h"

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
		free((void*)split[abs]);
	}
	free((void*)split);
	return (NULL);
}
