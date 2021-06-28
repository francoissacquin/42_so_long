#include "so_long.h"

int	key_hook(int keycode, t_tree *tree)
{
	if (keycode == 65307)
		ft_close(tree);
	if (keycode == 97)
		tree->vars.right = 1;
	if (keycode == 119)
		tree->vars.up = 1;
	if (keycode == 100)
		tree->vars.left = 1;
	if (keycode == 115)
		tree->vars.down = 1;
	ft_translate_player(tree);
	screen_manager(tree);
	return (0);
}

int	key_release_hook(int keycode, t_tree *tree)
{
	if (keycode == 97 && tree->vars.right == 1)
		tree->vars.strafe_right = 0;
	if (keycode == 119 && tree->vars.up == 1)
		tree->vars.forward = 0;
	if (keycode == 100 && tree->vars.left == 1)
		tree->vars.left = 0;
	if (keycode == 115 && tree->vars.down == 1)
		tree->vars.down = 0;
	ft_translate_player(tree);
	screen_manager(tree);
	return (0);
}

void	ft_translate_player(t_tree *tree)
{
	if (tree->vars.right == 1)
		go_right(tree);
	if (tree->vars.up == 1)
		go_up(tree);
	if (tree->vars.left == 1)
		go_left(tree);
	if (tree->vars.down == 1)
		go_down(tree);
}
