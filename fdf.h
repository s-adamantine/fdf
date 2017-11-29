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

# define W_HEIGHT 600
# define W_WIDTH 600
# define TILE_WIDTH 20
# define TILE_HEIGHT 20

# define TRANSLATION 10

# define BPP 24
# define BPB 8
# define ENDIAN 0
# define TOPX 100
# define TOPY 100
# define ALPHA 0
# define BETA 0
# define GAMMA 0

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct 	s_input
{
	int			rows;
	int			cols;
}				t_input;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_session
{
	void		*mlx;
	void		*win;
	int			bpp;
	int			sline;
	int			endian;
	t_point		***points;
}				t_session;

t_input			*grab_input_parameters(char **argv);
t_point			***handle_input(int argc, char **argv, t_session *env, t_input *input);
void			poop_points(t_session *env, t_point ***points);
int				ft_arrlen(char **arr);
int				handle_keypress(int keycode, t_session *env);
void			connect_points(t_session *env, t_point **points);
void			point_pairs(t_session *env, t_input *input, t_point ***points);
void	 		bersenham_points_test(t_session *env);
void 		   	rotate_x(t_point ***points, int direction);
void 		   	rotate_y(t_point ***points, int direction);
void			translate(t_session *env, int keypress);
// void 		   	rotate_z(t_point ***points, int direction);
