/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:30:14 by sadamant          #+#    #+#             */
/*   Updated: 2018/01/25 14:30:19 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_session *env, int keycode)
{
	int		i;
	int		j;
	double	scaling;

	j = 0;
	scaling = (keycode == KEY_PLUS) ? TILECHANGE : 1/TILECHANGE;
	while (env->points[j])
	{
		i = 0;
		while (env->points[j][i])
		{
				env->points[j][i]->x *= scaling;
				env->points[j][i]->y *= scaling;
				env->points[j][i]->z *= scaling;
			i++;
		}
		j++;
	}
}
