#include "../so_long.h"

void	go_right(t_tree *tree)
{
	if (ft_strrchr("0CE", tree->parsing.lab[tree->image.play_x][tree->image.play_y + 1]))
	{
		if (tree->parsing.lab[tree->image.play_x][tree->image.play_y + 1] == 'C')
		{
			tree->parsing.lab[tree->image.play_x][tree->image.play_y + 1] = '0';
			tree->parsing.coll--;
		}
		if (tree->parsing.lab[tree->image.play_x][tree->image.play_y + 1] == 'E' && tree->parsing.coll_count == 0)
			victory_screen(tree);
		tree->image.play_y = tree->image.play_y + 1;
	}
}

void	go_up(t_tree *tree)
{
	if (ft_strrchr("0CE", tree->parsing.lab[tree->image.play_x - 1][tree->image.play_y]))
	{
		if (tree->parsing.lab[tree->image.play_x - 1][tree->image.play_y] == 'C')
		{
			tree->parsing.lab[tree->image.play_x - 1][tree->image.play_y] = '0';
			tree->parsing.coll--;
		}
		if (tree->parsing.lab[tree->image.play_x - 1][tree->image.play_y] == 'E' && tree->parsing.coll_count == 0)
			victory_screen(tree);
		tree->image.play_x = tree->image.play_x - 1;
	}
}

void	go_left(t_tree *tree)
{
	if (ft_strrchr("0CE", tree->parsing.lab[tree->image.play_x][tree->image.play_y - 1]))
	{
		if (tree->parsing.lab[tree->image.play_x][tree->image.play_y - 1] == 'C')
		{
			tree->parsing.lab[tree->image.play_x][tree->image.play_y - 1] = '0';
			tree->parsing.coll--;
		}
		if (tree->parsing.lab[tree->image.play_x][tree->image.play_y - 1] == 'E' && tree->parsing.coll_count == 0)
			victory_screen(tree);
		tree->image.play_y = tree->image.play_y - 1;
	}
}

void	go_down(t_tree *tree)
{
	if (ft_strrchr("0CE", tree->parsing.lab[tree->image.play_x + 1][tree->image.play_y]))
	{
		if (tree->parsing.lab[tree->image.play_x + 1][tree->image.play_y] == 'C')
		{
			tree->parsing.lab[tree->image.play_x + 1][tree->image.play_y] = '0';
			tree->parsing.coll--;
		}
		if (tree->parsing.lab[tree->image.play_x + 1][tree->image.play_y] == 'E' && tree->parsing.coll_count == 0)
			victory_screen(tree);
		tree->image.play_x = tree->image.play_x + 1;
	}
}
