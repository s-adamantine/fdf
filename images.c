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
	void	*img;
	char	*img_string;

	img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT);
	img_string = mlx_get_data_addr(img, int *bits_per_pixel, int *size_line, 1);
	img_string = 
}
