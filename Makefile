# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 15:06:43 by ihuang            #+#    #+#              #
#    Updated: 2019/01/07 04:18:41 by ihuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRCS = main.c math_helpers.c get_color.c image.c make_line.c key_press.c \
	   render.c make_map.c free_all.c mouse_press.c update_vector_colors.c
OBJS = main.o math_helpers.o get_color.o image.o make_line.o key_press.o \
	   render.o make_map.o free_all.o mouse_press.o update_vector_colors.o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@echo "Compiling libmlx.a ..."
	@make -C minilibx_macos/ re
	@echo "Done."
	gcc $(FLAGS) -c $(SRCS)
	gcc -o $(NAME) $(OBJS) libft/libft.a -L ./minilibx_macos -lmlx \
		-framework OpenGL -framework AppKit

clean:
	@echo "Cleaning libft .o ..."
	@make -C libft/ clean
	@echo "Cleaning OBJS ..."
	@/bin/rm -f $(OBJS)
	@echo "Done."

fclean: clean
	@make -C libft/ fclean
	@echo "Cleaning $(NAME)"
	@/bin/rm -f $(NAME)
	@echo "Done."

re: fclean all

again:
	gcc $(FLAGS)  -c $(SRCS)
	gcc -o $(NAME) $(OBJS) libft/libft.a -L ./minilibx_macos -lmlx \
		-framework OpenGL -framework AppKit
	./$(NAME) ./maps/42.fdf
