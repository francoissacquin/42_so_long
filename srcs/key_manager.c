

#include "../so_long.h"

int	key_hook(int keycode, t_tree *tree)
{
	if (keycode == 65307)
		ft_close(tree);
	if (keycode == 97)
		go_right(tree);
	if (keycode == 119)
		go_up(tree);
	if (keycode == 100)
		go_left(tree);
	if (keycode == 115)
		go_down(tree);
	screen_manager(tree);
	return (0);
}
