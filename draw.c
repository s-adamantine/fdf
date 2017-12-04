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
