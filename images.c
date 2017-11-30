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

void 	print_image(t_session *env, t_map	*map)
{
	if (map)
		printf("");
	clear_image(env);
	// point_pairs(env, map, env->points);
	print_points(env, env->points); //the drawing portion
}

// void	image_set_pixel(t_session *env, int x, int y, int color)
// {
// 	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
// 		return ;
// 	pixel_addr + ((x + y * WIN_WIDTH) * env->bpp)) = color;
// }

void	new_image(t_session *env)
{
	int		i; //the current pixel incremented by bpps.
	int		x;
	void	*img;
	char	*pixel_addr;

	img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	pixel_addr = mlx_get_data_addr(img, &(env->bpp), &(env->sline), &(env->endian));
	// needs to be incremented by bits per pixels.
	x = 200;
	while (x < 300)
		mlx_pixel_put(env->mlx, env->win, x++, 200, 0x0000FF00);
	i = 0;
	while (i < 11)
		pixel_addr[i++ * (env->bpp / 8)] = mlx_get_color_value(env->mlx, 0x0000FF00);
	mlx_put_image_to_window(env->mlx, env->win, img, 300, 300);
}
