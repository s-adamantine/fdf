/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:26:24 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/22 15:26:27 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** use bresenham's line algorithm to connect two different points together.
** y = m(x - xo) + yo
** bersenham_x assumes x as the driving axis (x is always incremented, y may or
** may not be.
** bersenham_y assumes y as the driving axis.
*/


static t_point		**calibrate_direction(t_point	**points)
{
	t_point	*temp;

	if (points[0]->x > points[1]->x)
	{
		temp = points[0];
		points[0] = points[1];
		points[1] = temp;
	}
	return (points);
}

// i think this overlaps the last pixel, if that matters?
static void			draw_vertical(t_session *env, t_point **points)
{
	while (points[0]->y != points[1]->y)
	{
		if (points[0]->y < points[1]->y)
			pixel_to_image(env->image, points[0]->x, (points[0]->y)++, 0x00FF0000);
		else if (points[0]->y > points[1]->y)
			pixel_to_image(env->image, points[0]->x, (points[0]->y)--, 0x00FF0000);
	}
}

static void			draw_horizontal(t_session *env, t_point **points)
{
	while (points[0]->x != points[1]->x)
	{
		if (points[0]->x < points[1]->x)
			pixel_to_image(env->image, (points[0]->x)++, points[0]->y, 0x000000FF);
		else if (points[0]->x > points[1]->x)
			pixel_to_image(env->image, (points[0]->x)--, points[0]->y, 0x000000FF);
	}
}

/*
** figure out how to change the driving axes
** going to connect it w/ point pairs
*/
void				connect_points(t_session *env, t_point **points)
{
	int 	x;
	int 	y;
	int 	deltax;
	int 	deltay;
	int		error;

	points = calibrate_direction(points);
	x = points[0]->x;
	y = points[0]->y;
	deltax = points[1]->x - points[0]->x;
	deltay = points[1]->y - points[0]->y;
	if (deltax == 0)
		return (draw_vertical(env, points));
	else if (deltay == 0)
		return (draw_horizontal(env, points));
	error = abs(deltay - deltax);
	while (x <= points[1]->x)
	{
		pixel_to_image(env->image, x, y, 0x00FF0000);
		while (error >= 0) //don't make error abs here.
		{
			deltay / deltax >= 0? y++: y--;
			error = error - abs(deltax);
		}
		x++;
		error = error + abs(deltay);
	}
}

/*
** god rename me please.
*/
void			draw_line(t_session *env, t_map *map, t_point ***points)
{
	int			i;
	int 		j;
	t_point		**pair;

	j = 0;
	pair = ft_memalloc(sizeof(t_point *) * 2);
	// connecting across the y axis
	while (j < map->rows - 1)
	{
		i = 0;
		while (i < map->cols)
		{
			pair[0] = points[j][i];
			pair[1] = points[j + 1][i];
			connect_points(env, pair);
			i++;
		}
		j++;
	}
	j = 0;
	// connecting across the y axis
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols - 1)
		{
			pair[0] = points[j][i];
			pair[1] = points[j][i + 1];
			connect_points(env, pair);
			i++;
		}
		j++;
	}
}
/*
** poops out the 2d representation of how many points are input
*/
void			print_points(t_image *image, t_point ***points)
{
	int		i;
	int		j;

	j = 0;
	while (points[j])
	{
		i = 0;
		while (points[j][i])
		{
			pixel_to_image(image, points[j][i]->x, points[j][i]->y, POINT_COLOR);
			i++;
		}
		j++;
	}
}
