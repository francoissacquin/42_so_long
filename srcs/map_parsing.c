/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:43:20 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/28 12:01:30 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
** You will find in the following function an int table with the corresponding
** variables :
** tab[0] = line : number of lines of the map
** tab[1] = line_len : length of the longest line of the map
** tab[2] = left_shift : minimum number of space present in front of a map line
** tab[3] = start_line : starting line number of the map in the .cub file
*/
void	map_parsing(t_tree *tree)
{
	int		i;
	int		tab[4];
	char	*str;

	tree->parsing.fd = open((char const *)tree->parsing.file_path, O_RDONLY);
	if (tree->parsing.fd == -1)
		error_central_parsing(1, tree);
	i = 0;
	tab[0] = 1;
	tab[1] = 0;
	tab[2] = 0;
	str = 0;
	i = get_next_line(tree->parsing.fd, &str);
	while (i > 0)
	{
		map_parsing_plus(str, &tab[1], &tab[2], tree);
		tab[0]++;
		free(str);
		i = get_next_line(tree->parsing.fd, &str);
	}
	free(str);
	close(tree->parsing.fd);
	tree->parsing.fd = 0;
	tab[3] = 0;
	assign_map(tab, tree);
}

void	map_parsing_plus(char *str, int *biggest_len,
		int *left_shift, t_tree *tree)
{
	int	i;
	int	count_1;

	i = 0;
	count_1 = 0;
	while (str[i])
	{
		if (!(ft_strrchr("01PCE\n", str[i])))
			error_central_map_parsing(1, str, tree);
		if (str[i] == '1')
			count_1++;
		i++;
	}
	if (count_1 != 0)
	{
		if (*biggest_len < (int)(ft_strlen(str)
			- (ft_strlen(str) - last_wall(str, '1'))))
			*biggest_len = (int)(ft_strlen(str)
					- (ft_strlen(str) - last_wall(str, '1')));
		if (*left_shift > first_wall(str, '1'))
			*left_shift = first_wall(str, '1');
	}
	else
		error_central_map_parsing(4, str, tree);
}

/*
** You will find in the following function an int table with the corresponding
** variables :
** tab[0] = line : number of lines of the map (can also be called map height)
** tab[1] = line_len : length of the longest line of the map
** tab[2] = left_shift : minimum number of space present in front of a map line
** tab[3] = start_line : starting line number of the map in the .cub file
*/
void	assign_map(int *tab, t_tree *tree)
{
	tree->parsing.fd = open((char const *)tree->parsing.file_path, O_RDONLY);
	if (tree->parsing.fd == -1)
		error_central_parsing(1, tree);
	tree->parsing.lab = (char **)malloc(sizeof(char *) * ((tab[0] + 1)));
	if (tree->parsing.lab == NULL)
		error_central_map_parsing(3, 0, tree);
	tree->parsing.lab[tab[0]] = NULL;
	tree->image.map_x = tab[0];
	tree->image.map_y = tab[1];
	assign_map_lines(tab[0], tab[1], tab[2], tree);
	verify_labyrinth(tab[1], tab[0], tree);
}

void	assign_map_lines(int line, int line_len, int left_shift, t_tree *tree)
{
	int		x;
	int		j;
	int		y;
	char	*str;

	str = 0;
	x = 0;
	while ((get_next_line(tree->parsing.fd, &str)) >= 0 && x < line)
	{
		tree->parsing.lab[x] = (char *)malloc(sizeof(char)
				* ((line_len - left_shift) + 2));
		y = 0;
		j = left_shift;
		while (str[j])
			tree->parsing.lab[x][y++] = str[j++];
		while (y < (line_len - left_shift + 1))
			tree->parsing.lab[x][y++] = ' ';
		tree->parsing.lab[x][line_len - left_shift + 1] = '\0';
		free(str);
		str = 0;
		x++;
	}
	clear_parsing(str, tree);
	tree->parsing.lab[x] = NULL;
}

/*
** Same thing here, we make a small int tab to host 2 variables into one for
** norm reasons
** tab[0] = line_len : maximum length line of the map. Is used as map width
** tab[1] = line : number of lines of the map. Is used as map height.
*/
void	verify_labyrinth(int line_len, int line, t_tree *tree)
{
	int		x;
	int		starting_pos_count;
	int		tab[2];

	starting_pos_count = 0;
	tree->parsing.coll_count = 0;
	tree->parsing.exit_count = 0;
	x = 0;
	tab[0] = line_len;
	tab[1] = line;
	while (tree->parsing.lab[x] != 0 && x < line)
	{
		verify_lab_line(x, &starting_pos_count, tab, tree);
		x++;
	}
	if (starting_pos_count != 1)
		error_central_verify_map(4, tree);
	if (tree->parsing.coll_count < 1)
		error_central_verify_map(7, tree);
	if (tree->parsing.exit_count != 1)
		error_central_verify_map(8, tree);
}
