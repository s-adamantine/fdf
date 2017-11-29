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
	printf("key event %d\n", keycode);
	if (keycode == KEY_ESC)
		mlx_destroy_window(env->mlx, env->win);
	// needs to be able to handle points by passing this in as a parameter.
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_UP || keycode == KEY_DOWN)
		translate(env, keycode);
 	return (1);
}
