NAME = so_long

CC = gcc

CFLAGS = -lXext -lX11 -lm -Werror -Wextra -Wall -g3

HEADER = ./so_long.h

SRCS = ./main.c\
 ./init_utils.c\
 ./error_central.c\
 ./error_message.c\
 ./get_next_line.c\
 ./get_next_line_utils.c\
 ./map_parsing.c\
 ./parsing_utils.c\
 ./parsing_utils_2.c\
 ./wall_checks.c\
 ./closing_utils.c

OBJS = $(SRCS:.c=.o)

all			: $(NAME)

$(MLX_FILE)	:
				make --no-print-directory -C mlx_linux all

valgrind	: all
				valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/default.ber

$(NAME)		: $(MLX_FILE) $(OBJS)
				gcc -o $(NAME) $(SRCS) $(MLX_FILE) $(CFLAGS) -I./

clean		:
				rm -rf $(OBJS)

fclean		: clean
				rm -rf $(NAME)

libclean	:
				make --no-print-directory -C mlx_linux clean

re			: clean all

.PHONY: re clean fclean all
