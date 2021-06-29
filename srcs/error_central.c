/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_central.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:44:20 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/28 11:44:24 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_central_general(int index)
{
	if (index == 1)
		printf("Error\nwrong number of argument files given with exec\n");
	else if (index == 2)
		printf("Error\nconfiguration does not end with .ber\n");
	else if (index == 3)
		printf("Error\n in open() of config.ber\n");
	exit(EXIT_SUCCESS);
}

void	error_central_parsing(int index, t_tree *tree)
{
	error_message_parsing(index);
	close(tree->parsing.fd);
	exit(EXIT_SUCCESS);
}

void	error_central_map_parsing(int index, char *str, t_tree *tree)
{
	error_message_map_parsing(index, tree);
	if (str != 0)
		free(str);
	if (tree->parsing.fd != 0)
	{
		while ((get_next_line(tree->parsing.fd, &str)) > 0)
		{
			free(str);
			str = 0;
		}
	}
	if (str != 0)
		free(str);
	if (tree->parsing.fd != 0)
		close(tree->parsing.fd);
	exit(EXIT_SUCCESS);
}

void	error_central_verify_map(int index, t_tree *tree)
{
	char	*str;

	str = 0;
	error_message_verify_map(index);
	if (tree->parsing.fd != 0)
	{
		while ((get_next_line(tree->parsing.fd, &str)) > 0)
		{
			free(str);
			str = 0;
		}
		free(str);
		str = 0;
	}
	free_struc_labyrinth(tree);
	exit(EXIT_SUCCESS);
}
