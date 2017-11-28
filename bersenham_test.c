/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bersenham_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:01:24 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/28 18:01:26 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	bersenham_connect_points(t_session *env, t_point **points)
{
	mlx_pixel_put(env->mlx, env->win, points[0]->x, points[0]->y, 0x00FFFFFF);
	mlx_pixel_put(env->mlx, env->win, points[1]->x, points[1]->y, 0x00FFFFFF);
	printf("before connect points: points[0]->x:%d, ->y: %d, points[1]->x: %d, ->y:%d\n", points[0]->x, points[0]->y, points[1]->x, points[1]->y);
	connect_points(env, points);
	printf("after connect points: points[0]->x:%d, ->y: %d, points[1]->x: %d, ->y:%d\n", points[0]->x, points[0]->y, points[1]->x, points[1]->y);
	mlx_pixel_put(env->mlx, env->win, points[0]->x, points[0]->y, 0x0000FF00);
	mlx_pixel_put(env->mlx, env->win, points[1]->x, points[1]->y, 0x0000FF00);
}

void	   bersenham_points_test(t_session *env)
{
	t_point		**points;
	t_point		*point0;
	t_point		*point1;

	points = ft_memalloc(sizeof(t_point *)* 2);
	point0 = ft_memalloc(sizeof(t_point));
	point1 = ft_memalloc(sizeof(t_point));

	//dx > dy (y increments always, driving axis is y).
	//1 - top left to bottom right
	point0->x = 50;
	point0->y = 50;
	point1->x = 225;
	point1->y = 100;
	points[0] = point0;
	points[1] = point1;
	bersenham_connect_points(env, points);

	//2 - bottom right to top left
	point0->x = 250;
	point0->y = 50;
	point1->x = 425;
	point1->y = 100;
	points[1] = point0;
	points[0] = point1;
	bersenham_connect_points(env, points);

	//3 - top right to bottom left
	point0->x = 250;
	point0->y = 150;
	point1->x = 50;
	point1->y = 200;
	points[0] = point0;
	points[1] = point1;
	bersenham_connect_points(env, points);

	// 4 - bottom left to top right
	point0->x = 350;
	point0->y = 200;
	point1->x = 525;
	point1->y = 150;
	points[0] = point0;
	points[1] = point1;
	bersenham_connect_points(env, points);

	// //dx == dy
	// point0->x = 50;
	// point0->y = 150;
	// point1->x = 100;
	// point1->y = 200;
	// points[0] = point0;
	// points[1] = point1;
	// bersenham_connect_points(env, points);

	//dy > dx (x increments always, driving axis is x).
	//first direction - top left to bottom right
	point0->x = 300;
	point0->y = 300;
	point1->x = 350;
	point1->y = 475;
	points[0] = point0;
	points[1] = point1;
	bersenham_connect_points(env, points);

	//second direction - bottom right to top left
	point0->x = 400;
	point0->y = 300;
	point1->x = 450;
	point1->y = 475;
	points[1] = point0;
	points[0] = point1;
	bersenham_connect_points(env, points);

	//third direction - top right to bottom left
	point0->x = 200;
	point0->y = 300;
	point1->x = 150;
	point1->y = 475;
	points[1] = point0;
	points[0] = point1;
	bersenham_connect_points(env, points);

	//fourth direction - bottom left to top right
	point0->x = 100;
	point0->y = 300;
	point1->x = 50;
	point1->y = 475;
	points[0] = point0;
	points[1] = point1;
	bersenham_connect_points(env, points);

	//vertical line - first direction
	point0->x = 550;
	point0->y = 300;
	point1->x = 550;
	point1->y = 475;
	points[0] = point0;
	points[1] = point1;
	bersenham_connect_points(env, points);

	//vertical line - second direction
	point0->x = 500;
	point0->y = 300;
	point1->x = 500;
	point1->y = 475;
	points[1] = point0;
	points[0] = point1;
	bersenham_connect_points(env, points);

	//horizontal line - second direction
	point0->x = 550;
	point0->y = 550;
	point1->x = 350;
	point1->y = 550;
	points[0] = point0;
	points[1] = point1;
	bersenham_connect_points(env, points);

	//horizontal line - second direction
	point0->x = 300;
	point0->y = 550;
	point1->x = 100;
	point1->y = 550;
	points[1] = point0;
	points[0] = point1;
	bersenham_connect_points(env, points);
}
