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

void 	clear_image(t_session *env, t_image *image)
{
	ft_bzero(image->pixel_addr, env->sline * W_HEIGHT);
}

void 	print_image(t_session *env)
{
	clear_image(env, env->image);
	// point_pairs(env, map, env->points);
	print_points(env, env->image, env->points); //the drawing portion
	mlx_put_image_to_window(env->mlx, env->win, env->image->init, IMG_LEFT, IMG_TOP);
}

void 	pixel_to_image(t_session *env, char *pixel_addr, int x, int y, int color)
{
	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	ft_memcpy(&pixel_addr[(x++ * env->bpp/8) + (y * env->sline)], &color, (sizeof(size_t)));
}

t_image	*new_image(t_session *env)
{
	t_image	*image;

	image = ft_memalloc(sizeof(t_image));
	image->init = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	image->pixel_addr = mlx_get_data_addr(image->init, &(env->bpp), &(env->sline), &(env->endian));
	return (image);
}
