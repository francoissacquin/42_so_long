/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:46:28 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/28 11:51:44 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "./mlx_linux/mlx.h"

# define MLX_SYNC_IMAGE_WRITABLE		1
# define MLX_SYNC_WIN_FLUSH_CMD			2
# define MLX_SYNC_WIN_CMD_COMPLETED		3

typedef struct s_parsing_results
{
	char		*file_path;
	int			res_x;
	int			res_y;
	char		**lab;
	int			starting_x;
	int			starting_y;
	int			fd;
	int			coll_count;
	int			exit_count;
}				t_par_res;

typedef struct	s_tree
{
	t_par_res	parsing;
}				t_tree;

//init_utils :
void	verify_file(int arg_num, char **arg, t_tree *tree);
void	init_struc(t_tree *tree);

// map_parsing :
void	map_parsing(t_tree *tree);
void	map_parsing_plus(char *str, int *biggest_len, int *left_shift, t_tree *tree);
void	assign_map(int *tab, t_tree *tree);
void	assign_map_lines(int line, int line_len, int left_shift, t_tree *tree);
void	verify_labyrinth(int line_len, int line, t_tree *tree);

// parsing_utils united functions :
int		first_wall(char *str, int c);
int		last_wall(char *str, int c);
size_t	ft_strlen_array(char **array);
int		is_boundary_wall_alone(int x, int y, int *tab, t_tree *tree);
int		n_wall_check(int y, int len, t_tree *tree);
int		s_wall_check(int y, int len, int line, t_tree *tree);
int		is_char_not_inside_walls(int x, int y, t_tree *tree);
void	skip_lines(int start_line, int fd);
void	verify_lab_line(int x, int *starting_pos_count, int *tab, t_tree *tree);
char	*ft_strnstr(const char *str, const char *to_find, size_t length);
void	clear_parsing(char *str, t_tree *tree);

// get_next_line :
int		get_next_line(int fd, char **line);
int		finish_line(char *str, char **line);
char	*chad_buffer(char *str);
char	*read_line(char *str, int fd, int *read_len);

// get_next_line_utils :
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);

//error_central functions :
void	error_central_general(int index);
void	error_central_parsing(int index, t_tree *tree);
void	error_central_map_parsing(int index, char *str, t_tree *tree);
void	error_central_verify_map(int index, t_tree *tree);

//error_message functions :
void	error_message_parsing(int index);
void	error_message_map_parsing(int index, t_tree *tree);
void	error_message_verify_map(int index);

// closing utils functions :
void	free_struc_labyrinth(t_tree *tree);
char	**send_help(char const **split, int abs);

#endif
