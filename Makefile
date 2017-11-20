# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadamant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 17:46:32 by sadamant          #+#    #+#              #
#    Updated: 2017/11/18 17:46:33 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBNAME1 = libft.a
LIBNAME2 = libmlx.a

SRC = main.c
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -framework AppKit -framework OpenGL

LIB1 = -L./$(LIBDIR1) -lft
LIB2 = -L./$(LIBDIR2) -lmlx
LIBDIR1 = libft/
LIBDIR2 = minilibx_macos/

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(LIBDIR1)/$(LIBNAME1) $(LIBDIR2)/$(LIBNAME2) -I libft -I minilibx_macos/

clean:
	@$(MAKE) clean -C $(LIBDIR)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(LIBDIR1)/$(LIBNAME1)

re: fclean
	@make
