/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:39:00 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/17 16:06:53 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

t_session	*setup_environment(void)
{
	t_session	*env;

	env = ft_memalloc(sizeof(t_session));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_HEIGHT, W_WIDTH, "fdf");
	env->bpp = BPP;
	env->sline = W_WIDTH * BPP; //not sure about this though.
	env->endian = ENDIAN;
	mlx_key_hook(env->win, destroy_screen, env);
	// new_image(env);
	return (env);
}

t_point		**calibrate_quadrants(t_point	**points)
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
void	draw_vertical(t_session *env, t_point **points)
{
	while (points[0]->y != points[1]->y)
	{
		if (points[0]->y < points[1]->y)
			mlx_pixel_put(env->mlx, env->win, points[0]->x, (points[0]->y)++, 0x00FF0000);
		else if (points[0]->y > points[1]->y)
			mlx_pixel_put(env->mlx, env->win, points[0]->x, (points[0]->y)--, 0x00FF0000);
	}
}

void	draw_horizontal(t_session *env, t_point **points)
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
void		connect_points(t_session *env, t_point **points)
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
	printf("deltay is %d\n", deltay);
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
** delta y is bigger than delta x
*/
void	bersenham_points(t_session *env)
{
	t_point		**points;
	t_point		*point0;
	t_point		*point1;

	points = ft_memalloc(sizeof(t_point *)* 2);
	point0 = ft_memalloc(sizeof(t_point));
	point1 = ft_memalloc(sizeof(t_point));
	point0->x = 200;
	point0->y = 200;
	point1->x = 300; //150
	point1->y = 200; //75
	points[0] = point0;
	points[1] = point1;
	connect_points(env, points);
	mlx_pixel_put(env->mlx, env->win, points[0]->x, points[0]->y, 0x00FFFFFF);
	mlx_pixel_put(env->mlx, env->win, points[1]->x, points[1]->y, 0x0000FF00);
}

int	main(int argc, char **argv)
{
	t_session	*env;
	t_point		***points;

	env = setup_environment();
	points = handle_input(argc, argv); //might not be the best choice of function name - to change
	// poop_points(env, points); //the drawing portion
	bersenham_points(env);
	mlx_loop(env->mlx); //needs to be here!
	return (0);
}
