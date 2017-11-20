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

int	destroy_screen(int keycode, t_session *env)
{
	printf("key event %d\n", keycode);
	if (keycode == ESC_KEY)
		mlx_destroy_window(env->mlx, env->win);
	return (0);
}

int	main(void)
{
	t_session	*env;

	env = ft_memalloc(sizeof(t_session));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_HEIGHT, W_WIDTH, "fdf");
	mlx_pixel_put(env->mlx, env->win, 200, 200, 0x00FFFFFF);
	mlx_key_hook(env->win, destroy_screen, env);
	mlx_loop(env->mlx);
	return (0);
}
