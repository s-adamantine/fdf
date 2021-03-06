/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:41:14 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/12 16:16:17 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define MAX_INT 

# define W_HEIGHT 1200
# define W_WIDTH 1200
# define TILE_SIZE 20
# define TILECHANGE 1.2
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
# define KEY_PLUS 24
# define KEY_MINUS 27

# define DRAW_XOFFSET 100
# define DRAW_YOFFSET 100

# define LINE_COLOR 0x00FFFFFF

typedef struct	s_map
{
	int			rows;
	int			cols;
	int			x_l;
	int			x_r;
	int			y_t;
	int			y_b;
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
	int			tile_size;
	int			tile_z;
}				t_image;

typedef struct	s_screen
{
	int			w;
	int			h;
}				t_screen;

typedef struct	s_session
{
	void		*mlx;
	void		*win;
	int			endian;
	t_map		*map;
	t_screen	*screen;
	t_image		*image;
	t_point		***points;
}				t_session;

t_map			*grab_input_parameters(int fd, char *line);
void			exit_error(char *str);
void			print_image(t_session *env);
int				handle_keypress(int keycode, t_session *env);
void			connect_points(t_session *env, t_point *start, t_point *end);
void			print_lines(t_session *env, t_map *map, t_point ***points);
void			rotate_x(t_session *env, int keycode);
void			rotate_y(t_session *env, int keycode);
void			rotate_z(t_session *env, int keycode);
void			translate(t_session *env, int keycode);
void			scale(t_session *env, int keycode);
void			pixel_to_image(t_image *image, int x, int y, int color);
t_image			*new_image(t_session *env);
t_point			***grab_points(int fd, char *line, t_map *map);

#endif
