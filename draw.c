/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:26:24 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/23 17:26:26 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <limits.h>

static void		grab_minmax(t_map *map, t_point ***points)
{
	int		i;
	int		j;

	j = 0;
	map->x_l = INT_MAX;
	map->x_r = INT_MIN;
	map->y_t = INT_MAX;
	map->y_b = INT_MIN;
	while (points[j])
	{
		i = 0;
		while (points[j][i])
		{
			map->x_l = (points[j][i]->x < map->x_l) ? points[j][i]->x : map->x_l;
			map->x_r = (points[j][i]->x > map->x_r) ? points[j][i]->x : map->x_r;
			map->y_t = (points[j][i]->y < map->y_t) ? points[j][i]->y : map->y_t;
			map->y_b = (points[j][i]->y > map->y_b) ? points[j][i]->y : map->y_b;
			i++;
		}
		j++;
	}
}

static void		center(t_session *env)
{
	int		i;
	int		j;
	int		xl;
	int		yt;
	int		dx;
	int		dy;
	int		x_offset;
	int		y_offset;

	dx = 0;
	dy = 0;
	grab_minmax(env->map, env->points);
	xl = (env->screen->w / 2) - ((env->map->x_r - env->map->x_l) / 2);
	yt = (env->screen->h / 2) - ((env->map->y_b - env->map->y_t) / 2);
	x_offset = xl - env->map->x_l;
	y_offset = yt - env->map->y_t;
	j = 0;
	while (env->points[j])
	{
		i = 0;
		while (env->points[j][i])
		{
			env->points[j][i]->x += (xl - env->map->x_l);
			env->points[j][i]->y += (yt - env->map->y_t);
			i++;
		}
		j++;
	}
}

void			print_lines(t_session *env, t_map *map, t_point ***points)
{
	int	i;
	int	j;

	center(env);
	j = -1;
	while (++j < map->rows - 1)
	{
		i = -1;
		while (++i < map->cols)
			connect_points(env, points[j][i], points[j + 1][i]);
	}
	j = -1;
	while (++j < map->rows)
	{
		i = -1;
		while (++i < map->cols - 1)
			connect_points(env, points[j][i], points[j][i + 1]);
	}
}
