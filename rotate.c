/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:20:48 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/28 18:20:49 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(t_session *env, int keycode)
{
	int		i;
	int		j;
	int		direction;

	j = 0;
	direction = (keycode == KEY_S || keycode == KEY_D) ? 1 : -1;
	while (env->points[j])
	{
		i = 0;
		while (env->points[j][i])
		{
			if (keycode == KEY_A || keycode == KEY_D)
				env->points[j][i]->x += TRANSLATION * direction;
			else
				env->points[j][i]->y += TRANSLATION * direction;
			i++;
		}
		j++;
	}
	print_image(env);
}

void	rotate_x(t_session *env, int keycode)
{
	int		i;
	int		j;
	double	y;
	double	z;
	int		direction;

	j = 0;
	direction = (keycode == KEY_UP) ? 1 : -1;
	while (env->points[j])
	{
		i = 0;
		while (env->points[j][i])
		{
			y = env->points[j][i]->y;
			z = env->points[j][i]->z;
			env->points[j][i]->y = (y * cos(ALPHA * direction)) - \
				(z * sin(ALPHA * direction));
			env->points[j][i]->z = (y * sin(ALPHA * direction)) + \
				(z * cos(ALPHA * direction));
			i++;
		}
		j++;
	}
	print_image(env);
}

void	rotate_y(t_session *env, int keycode)
{
	int		i;
	int		j;
	double	x;
	double	z;
	int		direction;

	j = 0;
	direction = (keycode == KEY_LEFT) ? 1 : -1;
	while (env->points[j])
	{
		i = 0;
		while (env->points[j][i])
		{
			x = env->points[j][i]->x;
			z = env->points[j][i]->z;
			env->points[j][i]->x = (z * sin(BETA * direction)) + \
				(x * cos(BETA * direction));
			env->points[j][i]->z = (z * cos(BETA * direction)) - \
				(x * sin(BETA * direction));
			i++;
		}
		j++;
	}
	print_image(env);
}

void	rotate_z(t_session *env, int keycode)
{
	int		i;
	int		j;
	double	x;
	double	y;
	int		direction;

	j = 0;
	direction = (keycode == KEY_FSLASH) ? 1 : -1;
	while (env->points[j])
	{
		i = 0;
		while (env->points[j][i])
		{
			x = env->points[j][i]->x;
			y = env->points[j][i]->y;
			env->points[j][i]->x = (x * cos(GAMMA * direction)) - \
				(y * sin(GAMMA * direction));
			env->points[j][i]->y = (x * sin(GAMMA * direction)) + \
				(y * cos(GAMMA * direction));
			i++;
		}
		j++;
	}
	print_image(env);
}
