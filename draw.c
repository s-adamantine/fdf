/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:26:24 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/22 15:26:27 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** use bresenham's line algorithm to connect two different points together.
*/


/*
** poops out the 2d representation of how many points are input
*/
void	poop_points(t_session *env, t_point **points)
{
	int i;
	int	x;
	int y;
	int	poop;

	i = 0;
	x = 0;
	while (points[i++])
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
		x += TILE_WIDTH;
	}
}
