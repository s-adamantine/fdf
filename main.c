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

int	main(int argc, char **argv)
{
	t_session	*env;
	t_point		***points;

	env = setup_environment();
	points = handle_input(argc, argv); //might not be the best choice of function name - to change
	// poop_points(env, points); //the drawing portion
	mlx_loop(env->mlx); //needs to be here!
	return (0);
}
