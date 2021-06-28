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

#include "so_long.h"

int		main(int argc, char **argv)
{
	t_tree	tree;
	int		i;

	verify_file(argc, argv, &tree);
	init_struc(&tree);
	map_parsing(&tree);
	i = 0;
	while (tree.parsing.lab[i] != NULL)
	{
		printf("//%s\n", tree.parsing.lab[i]);
		i++;
	}
	return (0);
}
