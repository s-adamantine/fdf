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
LIBNAME1 = libft.a #why do I have this here
LIBNAME2 = libmlx.a #or this

SRC = main.c get_next_line.c input.c images.c draw.c keypress.c rotate.c
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -framework AppKit -framework OpenGL

LIB1 = -L./$(LIBDIR1) -lft
LIB2 = -L./$(LIBDIR2) -lmlx
LIBDIR1 = libft/
LIBDIR2 = minilibx_macos/

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBDIR1)
	@$(MAKE) -C $(LIBDIR2)
	#match libft's makefile w/ the one for fillit
	$(CC) $(FLAGS) $(SRC) $(LIB1) $(LIB2) -I libft -I minilibx_macos/ -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBDIR1)
	@$(MAKE) clean -C $(LIBDIR2)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(LIBDIR1)/$(LIBNAME1)

re: fclean all
