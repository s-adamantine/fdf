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

static void			exit_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

/*
** grabs variables about the map so that you can figure out how much to malloc.
** also checks if the successive number of columns are the same as the first
** row's columns.
**
** check if the file only contains numbers and spaces, that you've got the same
** number of points in each line.
*/

t_map				*grab_input_parameters(char **argv)
{
	int		fd;
	int		rows;
	char	**line;
	t_map	*map;

	rows = 1;
	fd = open(argv[1], O_RDONLY);
	if (!(map = (t_map *)malloc(sizeof(t_map))) || \
		!(line = ft_memalloc(sizeof(char **))))
		return (NULL);
	if (get_next_line(fd, line) <= 0)
		exit_error("error: input file is either empty or does not exist");
	map->cols = ft_arrlen(ft_strsplit(*line, ' '));
	while (get_next_line(fd, line) > 0)
	{
		rows++;
		if (ft_arrlen(ft_strsplit(*line, ' ')) != map->cols)
			exit_error("error: differing numbers of points per line in input file");
	}
	map->rows = rows;
	close(fd);
	return (map);
}

/*
** need to check for invalid characters here.
*/

static t_point		***grab_points(int fd, char **line, t_map *map)
{
	int		i;
	int		j;
	char	**zvalues;
	t_point	***points;

	if (!(points = ft_memalloc(sizeof(t_point **) * (map->rows + 1))))
		return (NULL);
	j = 0;
	while (get_next_line(fd, line) > 0)
	{
		i = 0;
		zvalues = ft_strsplit(*line, ' ');
		points[j] = ft_memalloc(sizeof(t_point *) * (map->cols + 1));
		while (zvalues[i])
		{
			points[j][i] = ft_memalloc(sizeof(t_point));
			points[j][i]->x = i * TILE_WIDTH;
			points[j][i]->y = j * TILE_HEIGHT;
			points[j][i]->z = ft_atoi(zvalues[i]) * TILE_Z;
			while (*zvalues[i])
				if (!ft_isdigit(*zvalues[i]++))
					exit_error("error: input file contains invalid characters");
			i++;
		}
		j++;
	}
	return (points);
}

/*
** please change my name
*/

t_point				***handle_input(int argc, char **argv, t_map *map)
{
	int			fd;
	char		**line;
	t_point		***points;

	if (!(line = ft_memalloc(sizeof(char **))))
		return (NULL);
	if (argc != 2)
		exit_error("usage: ./fdf source_file");
	if (!ft_strendsw(argv[1], ".fdf"))
		exit_error("error: not an .fdf file");
	fd = open(argv[1], O_RDONLY);
	points = grab_points(fd, line, map);
	close(fd);
	return (points);
}
