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

/*
** up: translate -y : -1
** down: translate y: 1
** left: translate -x: -2
** right: translate +x: 2
*/
void		translate(t_session *env, int keypress)
{
	int     i;
	int     j;
	int		direction;

	j = 0;
	direction = (keypress == KEY_DOWN || keypress == KEY_RIGHT) ? 1 : -1;
	while (env->points[j])
	{
		i = 0;
		while (env->points[j][i])
		{
			if (keypress == KEY_LEFT || keypress == KEY_RIGHT)
				env->points[j][i]->x += TRANSLATION * direction;
			else
				env->points[j][i]->y += TRANSLATION * direction;
			i++;
		}
		j++;
	}
	poop_points(env, env->points);
}

void    rotate_x(t_point ***points, int direction)
{
    int     i;
    int     j;
    int		x;
    int		y;
    int		z;

    j = 0;
    while (points[j])
    {
        i = 0;
        while (points[j][i])
        {
            x = (double) points[j][i]->x;
            y = (double) points[j][i]->y;
            z = (double) points[j][i]->z;
			// should cast back to integer automatically hopefully after doing
			// the double additions/subtractions
            points[j][i]->x = x;
            points[j][i]->y = (y * cos(ALPHA * direction)) - (z * sin(ALPHA * direction));
            points[j][i]->z = (y * sin(ALPHA * direction)) + (z * cos(ALPHA * direction));
            i++;
        }
        j++;
    }
}

/*
** left: -1
** right: 1
*/
void    rotate_y(t_point ***points, int direction)
{
    int		i;
    int		j;
    int		x;
    int		y;
    int		z;

    j = 0;
    while (points[j])
    {
        i = 0;
        while (points[j][i])
        {
            x = points[j][i]->x;
            y = points[j][i]->y;
            z = points[j][i]->z;
            points[j][i]->x = (z * sin(BETA * direction)) + (x * cos(BETA * direction));
            points[j][i]->y = y;
            points[j][i]->z = (z * cos(BETA * direction)) - (x * sin(BETA * direction));
            i++;
        }
        j++;
    }
}

// void    rotate_z(t_point ***points, int keycode)
// {
//     int     i;
//     int     j;
//     int     x;
//     int     y;
//     int     z;
//
// }
