# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:31:17 by luisfern          #+#    #+#              #
#    Updated: 2022/11/18 10:15:59 by luisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = so_long\
		map map2\
		moves moves2 \
		render render2\
		../get_next_line/get_next_line\
		../get_next_line/get_next_line_utils\


PRINTF = ../ft_printf/libftprintf.a
PRINTF_PATH = ../ft_printf

LIBFT = ../libft/libft.a
LIBFT_PATH = ../libft


CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I. -fsanitize=address
LINKS = -L../minilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz


all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(SRC:=.o)
	$(CC) $(CFLAGS) $(SRC:=.o) $(LIBFT) $(PRINTF) $(LINKS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I usr/include -Imlx_linux  -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

$(PRINTF):
	make -C $(PRINTF_PATH)

clean:
	$(RM) $(NAME) $(SRC:=.o)

fclean: clean
	$(RM) $(LIBFT) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re