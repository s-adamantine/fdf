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
** create a new image.
** mlx_new_image takes in the mlx pointer, the width and the height of the image.
*/

void   new_image(t_session *env)
{
	int		imgtowindow;
	void	*img;
	char	*pixel_addr;

	img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	pixel_addr = mlx_get_data_addr(img, &(env->bpp), &(env->sline), &(env->endian));
	pixel_addr[0] = mlx_get_color_value(env->mlx, 0x0000FFFF);
	pixel_addr[1] = mlx_get_color_value(env->mlx, 0x0000FFFF);
	imgtowindow = mlx_put_image_to_window(env->mlx, env->win, img, 200, 200); //what the fuck does this return
}

int		destroy_screen(int keycode, t_session *env)
{
	printf("key event %d\n", keycode);
	if (keycode == ESC_KEY)
		mlx_destroy_window(env->mlx, env->win);
	return (1);
}

void	setup_environment(void)
{
	t_session	*env;

	env = ft_memalloc(sizeof(t_session));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_HEIGHT, W_WIDTH, "fdf");
	env->bpp = BPP;
	env->sline = W_WIDTH * BPP; //not sure about this though.
	env->endian = ENDIAN;
	mlx_key_hook(env->win, destroy_screen, env);
	new_image(env);
	mlx_loop(env->mlx);
}
