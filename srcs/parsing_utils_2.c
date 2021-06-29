/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:42:02 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/28 11:57:04 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	skip_lines(int start_line, int fd)
{
	int		x;
	int		j;
	char	*str;

	x = 0;
	j = get_next_line(fd, &str);
	while ((j > 0) && x < (start_line - 1))
	{
		free(str);
		str = 0;
		x++;
		j = get_next_line(fd, &str);
	}
	free(str);
}

/*
** same thing here, we make a small int tab to host 2 variables into one for
** norm reasons
** tab[0] = line_len : maximum length line of the map. Is used as map width
** tab[1] = line : number of lines of the map. Is used as map height.
*/
void	verify_lab_line(int x, int *starting_pos_count, int *tab, t_tree *tree)
{
	int	y;

	y = 0;
	while (tree->parsing.lab[x][y])
	{
		if (tree->parsing.lab[x][y] == '1')
			if (is_boundary_wall_alone(x, y, tab, tree))
				error_central_verify_map(1, tree);
		if (tree->parsing.lab[x][y] == '0'
				|| ft_strrchr("PCE", tree->parsing.lab[x][y]))
		{
			if (x == 0 || x == tab[1] || y == 0 || y == tab[0])
				error_central_verify_map(2, tree);
			else if (is_char_not_inside_walls(x, y, tree))
				error_central_verify_map(3, tree);
		}
		if (ft_strrchr("P", tree->parsing.lab[x][y]))
		{
			(*starting_pos_count)++;
			tree->parsing.starting_x = x;
			tree->parsing.starting_y = y;
		}
		else if (ft_strrchr("C", tree->parsing.lab[x][y]))
			tree->parsing.coll_count++;
		else if (ft_strrchr("E", tree->parsing.lab[x][y]))
			tree->parsing.exit_count++;
		y++;
	}
}

char	*ft_strnstr(const char *str, const char *to_find, size_t length)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] && i < length)
	{
		j = 0;
		while (str[i + j] == to_find[j] && ((i + j) < length))
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char *)str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	clear_parsing(char *str, t_tree *tree)
{
	free(str);
	close(tree->parsing.fd);
	tree->parsing.fd = 0;
}
