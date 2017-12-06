/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:59:14 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/04 17:59:16 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		handle_mouse(int button, int x, int y, t_session *env)
{
	if (env)
		printf("");
	printf("x: %d, y: %d\n", x, y);
	printf("button: %d, x: %d, y: %d\n", button, x, y);
	return (1);
}
