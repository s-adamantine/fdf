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
	env->bpp = BITSPP;
	env->sline = W_WIDTH * BYTESPP;
	env->endian = ENDIAN;
	mlx_key_hook(env->win, handle_keypress, env);
	return (env);
}

int	main(int argc, char **argv)
{
	t_session	*env;
	t_map		*map;

	if (argc)
		printf("");
	env = setup_environment();
	// bersenham_points_test(env);
	map = grab_input_parameters(argv);
	env->points = handle_input(argc, argv, map);
	print_image(env, map);
	// new_image(env);
	mlx_key_hook(env->win, handle_keypress, env);
	mlx_loop(env->mlx); //needs to be here!
	return (0);
}
