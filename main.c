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

/*
** figure out how to change the driving axes
*/
void		connect_points(t_session *env, t_point *point0, t_point *point1)
{
	int 	x;
	int 	y;
	int 	deltax;
	int 	deltay;
	int		error;

	x = point0->x;
	y = point0->y;
	deltax = point1->x - point0->x;
	deltay = point1->y - point0->y; //why is this in the right case though
	error = deltay - deltax;
	while (x <= point1->x)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
		if (error >= 0)
		{
			y = y + 1;
			error = error - deltax;
		}
		x++;
		error = error + deltay;
	}
}

//doesn't work when error is 1?

void	bersenham_points(t_session *env)
{
	t_point		*point0;
	t_point		*point1;

	point0 = ft_memalloc(sizeof(t_point));
	point1 = ft_memalloc(sizeof(t_point));
	point0->x = 140;
	point0->y = 200;
	point1->x = 280;
	point1->y = 275;
	mlx_pixel_put(env->mlx, env->win, point0->x, point0->y, 0x00FFFFFF);
	connect_points(env, point0, point1);
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
