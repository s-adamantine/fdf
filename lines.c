/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:28:32 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/01 15:28:33 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_vertical(t_session *env, t_point *start, t_point *end)
{
	int		y;

	y = start->y;
	while (y != (int)end->y)
	{
		pixel_to_image(env->image, start->x, y, LINE_COLOR);
		y < end->y ? y++ : y--;
	}
}

static void		draw_horizontal(t_session *env, t_point *start, t_point *end)
{
	int		x;

	x = start->x;
	while (x != (int)end->x)
	{
		pixel_to_image(env->image, x, start->y, LINE_COLOR);
		x < end->x ? x++ : x--;
	}
}

static void		draw_drivingx(t_image *image, t_point *start, int deltax, \
	int deltay)
{
	int i;
	int x;
	int y;
	int	error;

	i = 0;
	x = start->x;
	y = start->y;
	error = abs(deltax / 2);
	while (i++ <= abs(deltax))
	{
		deltax > 0 ? x++ : x--;
		error = error + abs(deltay);
		if (error >= abs(deltax))
		{
			error = error - abs(deltax);
			deltay > 0 ? y++ : y--;
		}
		pixel_to_image(image, x, y, LINE_COLOR);
	}
}

static void		draw_drivingy(t_image *image, t_point *start, int deltax, \
	int deltay)
{
	int		i;
	int		x;
	int		y;
	int		error;

	i = 0;
	x = start->x;
	y = start->y;
	error = abs(deltay / 2);
	while (i++ <= abs(deltay))
	{
		deltay > 0 ? y++ : y--;
		error = error + abs(deltax);
		if (error >= abs(deltay))
		{
			error = error - abs(deltay);
			deltax > 0 ? x++ : x--;
		}
		pixel_to_image(image, x, y, LINE_COLOR);
	}
}

void			connect_points(t_session *env, t_point *start, t_point *end)
{
	int		x;
	int		y;
	int		deltax;
	int		deltay;

	x = start->x;
	y = start->y;
	deltax = end->x - start->x;
	deltay = end->y - start->y;
	if (deltax == 0)
		return (draw_vertical(env, start, end));
	if (deltay == 0)
		return (draw_horizontal(env, start, end));
	if (abs(deltax) >= abs(deltay))
		return (draw_drivingx(env->image, start, deltax, deltay));
	if (abs(deltay) > abs(deltax))
		return (draw_drivingy(env->image, start, deltax, deltay));
}
