
#include "so_long.h"

void	verify_file(int arg_num, char **arg, t_tree *tree)
{
	int		i;
	int		j;

	i = 0;
	if (arg_num != 2)
		error_central_general(1);
	while (arg[1][i])
		i++;
	if (!(&arg[1][i - 4] == ft_strnstr((char const *)arg[1], ".ber", i)))
		error_central_general(2);
	tree->parsing.file_path = (char *)malloc(sizeof(char) * (i + 3));
	tree->parsing.file_path[0] = '.';
	tree->parsing.file_path[1] = '/';
	i = 0;
	j = 2;
	while (arg[1][i])
		tree->parsing.file_path[j++] = arg[1][i++];
	tree->parsing.file_path[j] = '\0';
}

void	init_struc(t_tree *tree)
{
	tree->parsing.res_x = 0;
	tree->parsing.res_y = 0;
	tree->parsing.lab = 0;
	tree->parsing.starting_x = 0;
	tree->parsing.starting_y = 0;
}
