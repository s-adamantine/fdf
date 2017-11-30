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

void 	pixel_to_image(int x, int y, int color, char *pixel_addr, t_session *env)
{
	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	pixel_addr[(x * (env->bpp / 8)) + (y * env->sline)] = color;
}

void	new_image(t_session *env)
{
	int		x;
	int		y;
	int		color = 0x0000FF00;
	void	*img;
	char	*pixel_addr;

	img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	pixel_addr = mlx_get_data_addr(img, &(env->bpp), &(env->sline), &(env->endian));
	// needs to be incremented by bits per pixels.
	x = 200;
	y = 300;
	while (x < 300)
		ft_memcpy(&pixel_addr[(x++ * 4) + (y * env->sline)], &color, (sizeof(size_t)));
	mlx_put_image_to_window(env->mlx, env->win, img, 0, 0);
	x = 200;
	y = 200;
	while (x < 300)
		mlx_pixel_put(env->mlx, env->win, x++, y, 0x0000FF00);
}
