#include "../so_long.h"

void	go_right(t_tree *tree)
{
	int		next_x;
	int		next_y;

	next_x = (int)tree->image.play_x;
	next_y = (int)(tree->image.play_y + 0.1);
	if (ft_strrchr("0CE", tree->parsing.lab[next_x][next_y]))
	{
		if (tree->parsing.lab[next_x][next_y] == 'C')
		{
			tree->parsing.lab[next_x][next_y] = '0';
			tree->parsing.coll--;
		}
		if (tree->parsing.lab[next_x][next_y] == 'E' && tree->parsing.coll_count == 0)
			victory_screen(tree);
		tree->image.play_y = tree->image.play_y + 0.1;
	}
}

void	go_up(t_tree *tree)
{
	int		next_x;
	int		next_y;

	next_x = (int)(tree->image.play_x - 0.1);
	next_y = (int)(tree->image.play_y);
	if (ft_strrchr("0CE", tree->parsing.lab[next_x][next_y]))
	{
		if (tree->parsing.lab[next_x][next_y] == 'C')
		{
			tree->parsing.lab[next_x][next_y] = '0';
			tree->parsing.coll--;
		}
		if (tree->parsing.lab[next_x][next_y] == 'E' && tree->parsing.coll_count == 0)
			victory_screen(tree);
		tree->image.play_x = tree->image.play_x - 0.1;
	}
}

void	go_left(t_tree *tree)
{
	int		next_x;
	int		next_y;

	next_x = (int)tree->image.play_x;
	next_y = (int)(tree->image.play_y - 0.1);
	if (ft_strrchr("0CE", tree->parsing.lab[next_x][next_y]))
	{
		if (tree->parsing.lab[next_x][next_y] == 'C')
		{
			tree->parsing.lab[next_x][next_y] = '0';
			tree->parsing.coll--;
		}
		if (tree->parsing.lab[next_x][next_y] == 'E' && tree->parsing.coll_count == 0)
			victory_screen(tree);
		tree->image.play_y = tree->image.play_y - 0.1;
	}
}

void	go_down(t_tree *tree)
{
	int		next_x;
	int		next_y;

	next_x = (int)(tree->image.play_x + 0.1);
	next_y = (int)(tree->image.play_y);
	if (ft_strrchr("0CE", tree->parsing.lab[next_x][next_y]))
	{
		if (tree->parsing.lab[next_x][next_y] == 'C')
		{
			tree->parsing.lab[next_x][next_y] = '0';
			tree->parsing.coll--;
		}
		if (tree->parsing.lab[next_x][next_y] == 'E' && tree->parsing.coll_count == 0)
			victory_screen(tree);
		tree->image.play_x = tree->image.play_x + 0.1;
	}
}
