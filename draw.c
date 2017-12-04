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

// static void		calibrate_direction(t_point **start, t_point **end)
// {
// 	t_point	**temp;
//
// 	if (start->y > end->y)
// 	{
// 		*temp = start;
// 		start = end;
// 		end = temp;
// 	}
// 	printf("end of calibrate direction, start->y: %d, end->y: %d\n", start->y, end->y);
// }

// i think this overlaps the last pixel, if that matters?
static void			draw_vertical(t_session *env, t_point *start, t_point *end)
{
	int		y;

	y = start->y;
	while (y != end->y)
	{
		pixel_to_image(env->image, start->x, y, LINE_COLOR);
		y < end->y ? y++ : y--;
	}
}

static void			draw_horizontal(t_session *env, t_point *start, t_point *end)
{
	int		x;

	x = start->x;
	while (x != end->x)
	{
		pixel_to_image(env->image, x, start->y, LINE_COLOR);
		x < end->x ? x++ : x--;
	}
}

static void			draw_drivingx(t_image *image, t_point *start, t_point *end, int deltax, int deltay)
{
	int i;
	int x;
	int y;
	int	error;

	if (end)
		printf("");
	i = 0;
	x = start->x;
	y = start->y;
	error = abs(deltax / 2);
	while (i++ <= abs(deltax))
	{
		deltax > 0? x++ : x--;
		error = error + abs(deltay);
		if (error >= abs(deltax))
		{
			error = error - abs(deltax);
			deltay > 0? y++: y--;
		}
		pixel_to_image(image, x, y, LINE_COLOR);
	}
}

static void 		draw_drivingy(t_image *image, t_point *start, t_point *end, int deltax, int deltay)
{
	int		i;
	int 	x;
	int		y;
	int 	error;

	if (end)
		printf("");
	i = 0;
	x = start->x;
	y = start->y;
	error = abs(deltay / 2);
	while (i++ <= abs(deltay))
	{
		deltay > 0? y++ : y--;
		error = error + abs(deltax);
		if (error >= abs(deltay))
		{
			error = error - abs(deltay);
			deltax > 0 ? x++ : x--;
		}
		pixel_to_image(image, x, y, LINE_COLOR);
	}
}

void				connect_points(t_session *env, t_point *start, t_point *end)
{
	int		x;
	int		y;
	int 	deltax;
	int 	deltay;

	x = start->x;
	y = start->y;
	deltax = end->x - start->x;
	deltay = end->y - start->y;
	printf("deltax: %d, deltay: %d\n", deltax, deltay);
	if (deltax == 0)
		return (draw_vertical(env, start, end));
	if (deltay == 0)
		return (draw_horizontal(env, start, end));
	if (abs(deltax) >= abs(deltay))
		return (draw_drivingx(env->image, start, end, deltax, deltay));
	if (abs(deltay) > abs(deltax))
		return (draw_drivingy(env->image, start, end, deltax, deltay));
}

void			print_lines(t_session *env, t_map *map, t_point ***points)
{
	int			i;
	int 		j;

	j = 0;
	// connecting across the y axis
	while (j < map->rows - 1)
	{
		i = 0;
		while (i < map->cols)
		{
			connect_points(env, points[j][i], points[j + 1][i]);
			i++;
		}
		j++;
	}
	// connecting across the y axis
	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols - 1)
		{
			connect_points(env, points[j][i], points[j][i + 1]);
			i++;
		}
		j++;
	}
}

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
			if (points[j][i]->z > 0)
				pixel_to_image(image, points[j][i]->x, points[j][i]->y, POINT_COLOR);
			else
				pixel_to_image(image, points[j][i]->x, points[j][i]->y, 0x00FFFFFF);
			i++;
		}
		j++;
	}
}
