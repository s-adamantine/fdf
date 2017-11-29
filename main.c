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
	printf("env->bpp: %d\n", env->bpp);
	printf("bytesp: %d\n", BYTESPP);
	env->sline = W_WIDTH * BYTESPP;
	env->endian = ENDIAN;
	mlx_key_hook(env->win, handle_keypress, env);
	return (env);
}

int	main(int argc, char **argv)
{
	t_session	*env;
	t_input		*input;

	env = setup_environment();
	// bersenham_points_test(env);
	input = grab_input_parameters(argv);
	env->points = handle_input(argc, argv, env, input);
	print_image(env, input);
	mlx_key_hook(env->win, handle_keypress, env);
	mlx_loop(env->mlx); //needs to be here!
	return (0);
}
