/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:02:11 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/28 19:02:16 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		handle_keypress(int keycode, t_session *env)
{
	t_point	***points;

	points = env->points;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		rotate_x(env, keycode);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate_y(env, keycode);
	if (keycode == KEY_APOSTROPHE || keycode == KEY_FSLASH)
		rotate_z(env, keycode);
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || \
		keycode == KEY_D)
		translate(env, keycode);
	print_image(env);
	return (1);
}
