
#include "so_long.h"

int		main(int argc, char **argv)
{
	t_tree	tree;
	int		i;
	int		fd;
	char	*str;

	verify_file(argc, argv, &tree);
	init_struc(&tree);
	map_parsing(&tree);
	i = 0;
	fd = open((char const *)tree.parsing.file_path, O_RDONLY);
	i = get_next_line(fd, &str);
	while (i > 0)
	{
		printf("//%s\n", str);
		free(str);
		i = get_next_line(fd, &str);
	}
	free(str);
	close(fd);
	return (0);
}
