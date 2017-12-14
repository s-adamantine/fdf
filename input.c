/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:10:11 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/20 16:10:12 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** accepts hexas in the format ",0xFFFFFF"
** rejects everything else.
*/

static int			valid_chars(char *z_value)
{
	int n;

	n = 0;
	while (*z_value && (ft_isdigit(*z_value) || *z_value == '-'))
		z_value++;
	if (*z_value)
	{
		if (*z_value == ',')
		{
			z_value++;
			return (ft_ishexa(z_value) ? 1 : 0);
		}
		else
			return (0);
	}
	return (1);
}

/*
** grabs variables about the map so that you can figure out how much to malloc.
** checks:
** 1. if the successive number of columns are the same as the first row's
** columns.
** 2. if the file only contains numbers and spaces
** 3. that you've got the same number of points in each line.
*/

t_map				*grab_input_parameters(int fd, char *line)
{
	int		rows;
	char	**split_points;
	t_map	*map;

	rows = 1;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (get_next_line(fd, &line) <= 0)
		exit_error("error: input file is either empty or does not exist");
	split_points = ft_strsplit(line, ' ');
	map->cols = ft_arrlen(split_points);
	ft_freedarray((void **)split_points);
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		rows++;
		split_points = ft_strsplit(line, ' ');
		if (ft_arrlen(split_points) != map->cols)
			exit_error("error: differing numbers of points per line in input");
		ft_freedarray((void **)split_points);
		free(line);
	}
	free(line);
	map->rows = rows;
	return (map);
}

t_point				***grab_points(int fd, char *line, t_map *map)
{
	int		i;
	int		j;
	char	**zvalues;
	t_point	***points;

	points = ft_memalloc(sizeof(t_point **) * (map->rows + 1));
	j = -1;
	while (get_next_line(fd, &line) > 0)
	{
		i = -1;
		zvalues = ft_strsplit(line, ' ');
		points[++j] = ft_memalloc(sizeof(t_point *) * (map->cols + 1));
		while (zvalues[++i])
		{
			points[j][i] = ft_memalloc(sizeof(t_point));
			points[j][i]->x = i * TILE_WIDTH;
			points[j][i]->y = j * TILE_HEIGHT;
			valid_chars(zvalues[i]) ? points[j][i]->z = ft_atoi(zvalues[i]) \
				* TILE_Z : exit_error("error: invalid characters");
		}
		ft_freedarray((void **)zvalues);
		free(line);
	}
	free(line);
	return (points);
}
