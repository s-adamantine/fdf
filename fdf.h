/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:41:14 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/17 15:47:50 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> //open
#include <stdlib.h> //malloc, free
#include <string.h> //strerror
#include <stdio.h> //for printf
#include <math.h>
#include "mlx.h"
#include "libft.h"

# define TILE_WIDTH 20
# define TILE_HEIGHT 20
# define ESC_KEY 53

typedef struct	s_session
{
	void		*mlx;
	void		*win;
}				t_session;
