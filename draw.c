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

// static void	bersenham_x(t_point *point0, t_point *point1)
// {
// 	int min_x;
// 	int	max_x;
// 	int error;
//
// 	if (point1->x <= point0->x)
// 	{
// 		min_x = point1->x;
// 		max_x = point0->x;
// 	}
// 	else
// 	{
// 		min_x = point0->x;
// 		max_x = point1->x;
// 	}
// 	while (min_x <= max_x)
// 	{
// 		deltay = abs(point1->y - point0->y);
// 		deltax = abs(point1->x - point0->x);
// 		error = deltay - deltax; //deltay is always greater than deltax w/ driving axis x;
// 		if (error >= 0)
// 		{
// 			y = y + 1;
// 			error = error - deltax;
// 		}
// 		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
// 		min_x++;
// 	}
// }
//

// void		connect_points(t_session *env, t_point *point0, t_point *point1)
// {
// 	int 	y;
// 	int 	x;
// 	int 	deltax;
// 	int 	deltay;
// 	int 	error;
// 	double	deltaerr; //test this though.
//
// 	deltax = point1->x - point0->x;
// 	deltay = point1->y - point0->y; //why is this in the right case though
// 	printf("deltax: %d\n", deltax);
// 	printf("deltay: %d\n", deltay);
// 	deltaerr = abs(deltax / deltay);
// 	printf("deltaerr: %f\n", deltaerr);
// 	error = 0;
// 	y = point1->y;
// 	x = point1->x;
// 	while (x <= point0->x)
// 	{
// 		printf("x is %d and y is %d\n", x, y);
// 		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
// 		error = error + deltaerr;
// 		printf("error is %d\n", error);
// 		while (error >= 0.5)
// 		{
// 			printf("y before is: %d\n", y);
// 			y++;
// 			error = error - 1;
// 		}
// 		x++;
// 	}
// }

/*
** bersenham using doubles (for the m)
*/

// void		connect_points(t_session *env, t_point *point0, t_point *point1)
// {
// 	int 	y;
// 	int 	x;
// 	int 	deltax;
// 	int 	deltay;
// 	double	m;
// 	// int 	error;
// 	// double	deltaerr; //test this though.
//
// 	deltax = point1->x - point0->x;
// 	deltay = point1->y - point0->y; //why is this in the right case though
// 	m = deltay/deltax;
// 	printf("deltax: %d\n", deltax);
// 	printf("deltay: %d\n", deltay);
// 	// deltaerr = abs(deltax / deltay);
// 	// printf("deltaerr: %f\n", deltaerr);
// 	// error = 0;
// 	y = point1->y;
// 	x = point1->x;
// 	while (x <= point0->x)
// 	{
// 		printf("x is %d and y is %d\n", x, y);
// 		y = (m * (x - point0->x)) + point0->y;
// 		printf("m is %f\n", m);
// 		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
// 		// error = error + deltaerr;
// 		x++;
// 	}z																				x
// }





/*
** poops out the 2d representation of how many points are input
*/
// void	poop_points(t_session *env, t_point ***points)
// {
// 	int i;
// 	int j;
// 	int x;
// 	int y;
//
// 	j = 0;
// 	y = TOPY;
// 	while (points[j++])
// 	{
// 		i = 0;
// 		x = TOPX;
// 		while (points[i++])
// 		{
// 			mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
// 			x += TILE_WIDTH;
// 		}
// 		y += TILE_HEIGHT;
// 	}
// }
