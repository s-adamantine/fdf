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
	printf("key event %d\n", keycode);
	if (keycode == KEY_ESC)
		mlx_destroy_window(env->mlx, env->win);
	// needs to be able to handle points by passing this in as a parameter.
    if (keycode == KEY_LEFT)
        rotate_x(env->points, -1);
    if (keycode == KEY_RIGHT)
        rotate_x(env->points, 1);
    if (keycode == KEY_UP)
        rotate_y(env->points, 1);
    if (keycode == KEY_DOWN)
        rotate_y(env->points, -1);
 	return (1);
}
