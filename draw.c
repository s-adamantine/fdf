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

static t_point		**calibrate_quadrants(t_point	**points)
{
	int		deltax;
	int		deltay;
	t_point	*temp;

	deltax = points[1]->x - points[0]->x;
	deltay = points[1]->y - points[0]->y;
	printf("deltay: %d, deltax: %d\n", deltay, deltax);
	if (deltax == 0 || deltay == 0)
		return (points);
	if (abs(deltax) > abs(deltay))
	{
		temp = ft_memalloc(sizeof(t_point *));
		temp->x = points[0]->x;
		points[0]->x = points[0]->y;
		points[0]->y = temp->x;
		temp->x = points[1]->x;
		points[1]->x = points[1]->y;
		points[1]->y = temp->x;
	}
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
			mlx_pixel_put(env->mlx, env->win, points[0]->x, (points[0]->y)++, 0x00FF0000);
		else if (points[0]->y > points[1]->y)
			mlx_pixel_put(env->mlx, env->win, points[0]->x, (points[0]->y)--, 0x00FF0000);
	}
}

static void			draw_horizontal(t_session *env, t_point **points)
{
	while (points[0]->x != points[1]->x)
	{
		if (points[0]->x < points[1]->x)
			mlx_pixel_put(env->mlx, env->win, (points[0]->x)++, points[0]->y, 0x00FF0000);
		else if (points[0]->x > points[1]->x)
			mlx_pixel_put(env->mlx, env->win, (points[0]->x)--, points[0]->y, 0x00FF0000);
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

	points = calibrate_quadrants(points);
	x = points[0]->x;
	y = points[0]->y;
	deltax = points[1]->x - points[0]->x;
	deltay = points[1]->y - points[0]->y;
	if (deltax == 0) //should really be deltay though, but calibrate quadrants fucked me up.
	{
		draw_vertical(env, points);
		return;
	}
	else if (deltay == 0)
	{
		draw_horizontal(env, points);
		return;
	}
	error = abs(deltay - deltax);
	while (x <= points[1]->x)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
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
** poops out the 2d representation of how many points are input
*/
void			poop_points(t_session *env, t_point ***points)
{
	int 	i;
	int 	j;
	int 	x;
	int 	y;
	t_point	**pair;

	j = 0;
	y = TOPY;
	pair = ft_memalloc(sizeof(t_point)); //if statement here?
	while (points[j++])
	{
		i = 0;
		x = TOPX;
		while (points[i++])
		{
			mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
			x += TILE_WIDTH;
		}
		y += TILE_HEIGHT;
	}
	//meed to grab poop pairs and connect them together.
}
