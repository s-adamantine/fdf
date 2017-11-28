/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:58:48 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/18 17:58:49 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** poops out the 2d representation of how many points are input
*/

/*
** why aren't they the same color :(
*/
// void	new_image(t_session *env)
// {
// 	int		i; //the current pixel incremented by bpps.
// 	int		x;
// 	void	*img;
// 	char	*pixel_addr;
//
// 	img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
// 	pixel_addr = mlx_get_data_addr(img, &(env->bpp), &(env->sline), &(env->endian));
// 	// needs to be incremented by bits per pixels.
// 	x = 200;
// 	while (x < 210)
// 		mlx_pixel_put(env->mlx, env->win, x++, 200, 0x00FFFF);
// 	i = 0;
// 	while (i < 11)
// 		pixel_addr[i++ * (env->bpp / 8)] = mlx_get_color_value(env->mlx, 0x0000FF);
// 	printf("%d\n", 0x00FFFF);
// 	printf("%d\n", mlx_get_color_value(env->mlx, 0x00FFFF));
// 	printf("hi");
// 	mlx_put_image_to_window(env->mlx, env->win, img, 200, 205);
// }
