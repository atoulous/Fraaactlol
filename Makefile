# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/17 21:56:41 by atoulous          #+#    #+#              #
#    Updated: 2016/07/01 14:54:52 by atoulous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = Sources/fractol.c Sources/lunchfract.c Sources/events.c \
	  Sources/mandelbrot.c Sources/julia.c Sources/buddhabrot.c \
	  Sources/ricobrot.c Sources/burningship.c Sources/sierpinski.c

OBJ = $(SRC:.c=.o)

CF = gcc -Wall -Werror -Wextra

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

$(NAME): $(OBJ)
	@echo
	@echo "@@@@@  @@@@     @@@    @@@   @@@@@   @   @@@   @    "
	@echo "@      @   @   @   @  @   @    @    @   @   @  @    "
	@echo "@@@@   @@@@    @@@@@  @        @        @   @  @    "
	@echo "@      @   @   @   @  @   @    @        @   @  @   @"
	@echo "@      @   @   @   @   @@@     @         @@@   @@@@@"
	@echo
	@make -C Libs/libft
	@make -C Libs/minilibx_macos
	@$(CF) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
#   @echo "\033[32m[OK]\033[0m"#
	@echo fractol well compiled

all: $(NAME)

%.o: %.c
	@$(CF) -o $@ -c $<

clean:
	@make clean -C Libs/libft
	@make clean -C Libs/minilibx_macos
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C Libs/libft
	@rm -f $(NAME)

re: fclean all
