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
** put into libft
*/

int	ft_arrlen(char **arr)
{
	int len;

	len = 0;
	if (!arr)
		return (0);
	while (arr[len])
		len++;
	return (len);
}

/*
** grabs variables about the map so that you can figure out how much to malloc.
** also checks if the successive number of columns are the same as the first
** row's columns.

** check if the file only contains numbers and spaces, that you've got the same
** number of points in each line.
*/

t_input				*grab_input_parameters(char **argv)
{
	int		fd;
	int		rows;
	int		cols;
	char	**line;
	t_input	*input;

	cols = 0;
	rows = 1; //I shouldn't have to initialize this to 1 - should be 0? check gnl output.
	fd = open(argv[1], O_RDONLY);
	if (!(input = (t_input *)malloc(sizeof(t_input))) || !(line = ft_memalloc(sizeof(char **))))
		return (NULL);
	if (get_next_line(fd, line) <= 0)
		exit_error("error: input file is either empty or does not exist.");
	input->cols = ft_arrlen(ft_strsplit(*line, ' '));
	while (get_next_line(fd, line) > 0)
	{
		rows++;
		cols = ft_arrlen(ft_strsplit(*line, ' '));
		if (cols != input->cols)
			exit_error("error: differing numbers of points per line in input file.");
	}
	input->rows = rows;
	close(fd);
	return (input);
}

/*
** need to check for invalid characters here.
*/
static t_point		***grab_points(int fd, char **line, t_input *input)
{
	int		i;
	int		j;
	char	**zvalues;
	t_point	***points;

	if (!(points = ft_memalloc(sizeof(t_point **) * (input->rows + 1))))
		return (NULL);
	j = 0;
	while (get_next_line(fd, line) > 0)
	{
		i = 0;
		zvalues = ft_strsplit(*line, ' ');
		points[j] = ft_memalloc(sizeof(t_point *)* (input->cols + 1));
		while (zvalues[i])
		{
			points[j][i] = ft_memalloc(sizeof(t_point));
			points[j][i]->x = i * TILE_WIDTH;
			points[j][i]->y = j * TILE_HEIGHT;
			points[j][i]->z = ft_atoi(zvalues[i]);
			i++;
		}
		j++;
	}
	return (points);
}

/*
** please change my name
*/
t_point				***handle_input(int argc, char **argv, t_input *input)
{
	int			fd;
	char		**line;
	t_point		***points;

	if (!(line = ft_memalloc(sizeof(char **))))
		return (NULL);
	if (argc != 2)
		exit_error("usage: ./fdf source_file");
	fd = open(argv[1], O_RDONLY);
	points = grab_points(fd, line, input);
	close(fd);
	return (points);
}
