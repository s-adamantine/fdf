/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:39:00 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/12 16:14:08 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

t_session	*setup_environment(void)
{
	t_session	*env;

	env = ft_memalloc(sizeof(t_session));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "fdf");
	mlx_key_hook(env->win, handle_keypress, env);
	return (env);
}

int			main(int argc, char **argv)
{
	t_session	*env;

	env = setup_environment();
	env->map = grab_input_parameters(argv);
	env->points = handle_input(argc, argv, env->map);
	env->image = new_image(env);
	print_image(env);
	mlx_loop(env->mlx);
	return (0);
}
