/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:10:11 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/20 16:10:12 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** THIS IS NOT DONE AT ALL - need to figure out how i want to handle the inputs
** so first I need to figure out how to draw sOMEthing.
*/

static void		exit_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

/*
** check if the file only contains numbers and spaces, that you've got the same
** number of points in each line.
*/

int	ft_arrlen(char **arr)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	if (!arr)
		return (0);
	while (arr[i++])
		len++;
	return (len);
}

/*
** poops out the 2d representation of how many points are input
*/
void	poop_points(t_session *env, t_point **points)
{
	int i;
	int	x;
	int y;
	int	poop;

	i = 0;
	x = 0;
	while (points[i++])
	{
		mlx_pixel_put(emv->mlx, env->win, x, y, 0x00FFFFFF);
		x += TILE_WIDTH;
	}
}

/*
** grabs each point into a structure of points, checking if each line
** has the same number of points.
**
** the checking part still needs to be implemented.
** need to go and grab the first line!!
** also need to make sure if all the points are allocated to points (if statement after tokens)
*/

t_point		**grab_points(int fd)
{
	int		i;
	int		j;
	char	**tokens;
	char	**line;
	t_point	*point;
	t_point	**points;

	if (!(line = ft_memalloc(sizeof(char **))))
		return (NULL);
	get_next_line(fd, line);
	tokens = ft_strsplit(*line, ' ');
	// needs to be as many points as there are tokens * lines
	// but this doesn't work if you can't
	if (!(points = ft_memalloc(sizeof(t_point *) * ft_arrlen(tokens))))
		return (NULL);
	j = 0; //can be 0 or 1 really.
	while (get_next_line(fd, line) > 0)
	{
		i = -1;
		tokens = ft_strsplit(*line, ' ');
		point = ft_memalloc(sizeof(t_point));
		while (tokens[++i])
		{
			point->x = i;
			point->y = j;
			point->z = ft_atoi(tokens[i]);
			// printf("x: %d, y: %d, z: %d\n", point->x, point->y, point->z);
			points[i] = point;
		}
		j++;
	}
	return (points);
}

/*
** you really only want to read once though, right, instead of parsing through it
** a million fucking times.
*/
void	handle_input(int argc, char **argv)
{
	int			fd;
	t_point	**points;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		exit_error("usage: ./fdf source_file");
	points = grab_points(fd);
	//this really shouldn't be here but
	poop_points(env, points);
	close(fd);
}
