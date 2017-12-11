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

#ifndef FDF_H
# define FDF_H

# include <fcntl.h> //open
# include <stdlib.h> //malloc, free
# include <stdio.h> //for printf
# include <unistd.h> //for close, write
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define W_HEIGHT 600
# define W_WIDTH 600
# define TILE_WIDTH 20
# define TILE_HEIGHT 20
# define TILE_Z 5

# define TRANSLATION 30

# define TOPX 100
# define TOPY 100
# define ALPHA 0.4
# define BETA 0.4
# define GAMMA 0.2

# define IMG_LEFT 0
# define IMG_TOP 0

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_APOSTROPHE 39
# define KEY_FSLASH 44

# define DRAW_XOFFSET 100
# define DRAW_YOFFSET 100

# define POINT_COLOR 0x0000FF00
# define LINE_COLOR 0x00FFFFFF

typedef struct	s_map
{
	int			rows;
	int			cols;
}				t_map;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_image
{
	int			bpp;
	int			sline;
	void		*init;
	char		*pixel_addr;
}				t_image;

typedef struct	s_session
{
	void		*mlx;
	void		*win;
	int			endian;
	t_map		*map;
	t_image		*image;
	t_point		***points;
}				t_session;

t_map			*grab_input_parameters(char **argv);
t_point			***handle_input(int argc, char **argv, t_map *map);
void			print_points(t_image *image, t_point ***points);
void			print_image(t_session *env);
int				ft_arrlen(char **arr);
int				handle_keypress(int keycode, t_session *env);
void			connect_points(t_session *env, t_point *start, t_point *end);
void			print_lines(t_session *env, t_map *map, t_point ***points);
void			bersenham_points_test(t_session *env);
void			rotate_x(t_session *env, int keycode);
void			rotate_y(t_session *env, int keycode);
void			rotate_z(t_session *env, int keycode);
void			translate(t_session *env, int keycode);
void			pixel_to_image(t_image *image, int x, int y, int color);
int				handle_mouse(int button, int x, int y, t_session *env);
t_image			*new_image(t_session *env);
void			clear_image(t_image *image);

#endif
