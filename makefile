# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 16:23:53 by pepealkalin       #+#    #+#              #
#    Updated: 2023/01/07 16:07:39 by pepealkalin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out
MLX42 = MLX42/libmlx42.a -lglfw -L /opt/homebrew/Cellar/glfw/3.3.8/lib/

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRC = $(GNL) main.c read_map.c check_map_utils.c check_map.c \
		game_main.c draw_map.c gameplay.c

PRINTF = ft_printf/libftprintf.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft -s 
	@make -C ft_printf -s
	@make -s -C MLX42
	$(CC) $(CCFLAGS) $(SRC) $(LIBFT) $(PRINTF) $(MLX42) -o $(NAME)

clean:
	@make clean -C libft -s
	@make clean -C ft_printf -s
	@make clean -C MLX42 -s
	rm -rf *.o get_next_line/*.o

fclean:
	@make fclean -C libft -s
	@make fclean -C ft_printf -s
	@make fclean -s -C MLX42
	rm -rf *.o get_next_line/*.o $(NAME)

re: fclean all

.PHONY: all clean fclean re