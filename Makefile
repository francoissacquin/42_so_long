# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 11:45:48 by fsacquin          #+#    #+#              #
#    Updated: 2021/06/29 11:53:17 by fsacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -lXext -lX11 -lm -Werror -Wextra -Wall -g3

HEADER = ./so_long.h

SRCS = ./srcs/main.c\
 ./srcs/init_utils.c\
 ./srcs/error_central.c\
 ./srcs/error_message.c\
 ./srcs/get_next_line.c\
 ./srcs/get_next_line_utils.c\
 ./srcs/map_parsing.c\
 ./srcs/parsing_utils.c\
 ./srcs/parsing_utils_2.c\
 ./srcs/wall_checks.c\
 ./srcs/closing_utils.c\
 ./srcs/screen_manager.c\
 ./srcs/key_manager.c\
 ./srcs/key_movement.c\
 ./srcs/map_drawer.c

OBJS = $(SRCS:.c=.o)

all			: $(NAME)

$(MLX_FILE)	:
				make --no-print-directory -C mlx_linux all

valgrind	: all
				valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/default.ber

$(NAME)		: $(OBJS)
				make --no-print-directory -C mlx_linux all
				gcc -o $(NAME) $(SRCS) ./mlx_linux/libmlx_Linux.a $(CFLAGS) -I./

clean		:
				rm -rf $(OBJS)

fclean		: clean
				rm -rf $(NAME)

libclean	:
				make --no-print-directory -C mlx_linux clean

re			: clean all

.PHONY: re clean fclean all
