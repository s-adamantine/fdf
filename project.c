/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:47:01 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/10 19:47:05 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** want to project a temporary version of points.
*/

void	project_pinhole(t_point ***points)
{
	int i;
	int j;

	j = 0;
	while (points[j])
	{
		i = 0;
		while (points[j][i])
		{
			points[j][i]->x = points[j][i]->x + (CTEP * points[j][i]->z);
			points[j][i]->y = points[j][i]->y + ((CTEP / 2) * points[j][i]->z);
			i++;
		}
		j++;
	}	
}

void	project_parallel(t_point ***points)
{
	int i;
	int j;

	j = 0;
	while (points[j])
	{
		i = 0;
		while (points[j][i])
		{
			points[j][i]->x = points[j][i]->x + (CTEP * points[j][i]->z);
			points[j][i]->y = points[j][i]->y + ((CTEP / 2) * points[j][i]->z);
			i++;
		}
		j++;
	}
}

// void	project(char *projection, t_point ***points)
// {
// 	if (ft_strcmp(projection, "parallel")
// 		project_parallel(points);
// }
