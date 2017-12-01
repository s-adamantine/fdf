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

// static t_point		**calibrate_direction(t_point *start, t_point *end)
// {
// 	t_point	*temp;
//
// 	if (start->x > end->x)
// 	{
// 		temp = start;
// 		start = end;
// 		end = temp;
// 	}
// 	return (points);
// }

// i think this overlaps the last pixel, if that matters?
static void			draw_vertical(t_session *env, t_point *start, t_point *end)
{
	int		y;

	y = start->y;
	while (y != end->y)
	{
		pixel_to_image(env->image, start->x, y, 0x00FF0000);
		y < end->y ? y++ : y--;
	}
}

static void			draw_horizontal(t_session *env, t_point *start, t_point *end)
{
	int		x;

	x = start->x;
	while (x != end->x)
	{
		pixel_to_image(env->image, x, start->y, 0x00FF0000);
		x < end->x ? x++ : x--;
	}
}

void				connect_points(t_session *env, t_point *start, t_point *end)
{
	int 	deltax;
	int 	deltay;
	// int		error;

	// points = calibrate_direction(points);
	deltax = end->x - start->x;
	deltay = end->y - start->y;
	if (deltax == 0)
		return (draw_vertical(env, start, end));
	else if (deltay == 0)
		return (draw_horizontal(env, start, end));
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
		printf("j is %d\n", j);
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
