/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:41:14 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/17 15:47:50 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> //open
#include <stdlib.h> //malloc, free
#include <string.h> //strerror
#include <stdio.h> //for printf
#include <unistd.h> //for close, write
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "get_next_line.h"

# define W_HEIGHT 400
# define W_WIDTH 400
# define TILE_WIDTH 20
# define TILE_HEIGHT 20
# define ESC_KEY 53
# define BPP 24
# define BPB 8
# define ENDIAN 0

typedef struct	s_session
{
	void		*mlx;
	void		*win;
	int			bpp;
	int			sline;
	int			endian;
}				t_session;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

void			handle_input(int argc, char **argv);
void 			setup_environment(void);
int				ft_arrlen(char **arr);
