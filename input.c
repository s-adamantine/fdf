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
**
*/

static t_input		*grab_input_variables()
{
	
}

/*
** grabs each point into a structure of points, checking if each line
** has the same number of points.
**
** the checking part still needs to be implemented.
** need to go and grab the first line!!
** also need to make sure if all the points are allocated to points (if statement after tokens)

** check if every line is the same after you've grabbed all the points
** t_point	*: each individual point (includes x, y, z)
** t_point	**: a line (string) of points.
** t_point	***: a double array of points.

** need to allocate memory for each point, each line, and the pointer that goes to the first.
*/

/*
** need to count how many
*/


static t_point		***grab_points(int fd, char **line)
{
	int		i;
	int		j;
	char	**tokens;
	t_point	***points;

	if (!(points = (t_point ***)malloc(sizeof(t_point **)))) //needs to be t_point ** * j
		return (NULL);
	j = 0;
	while (get_next_line(fd, line) > 0)
	{
		i = 0;
		tokens = ft_strsplit(*line, ' ');
		points[j] = (t_point **)malloc(sizeof(t_point *)); //needs to be t_point * *
		while (tokens[i])
		{
			points[j][i] = (t_point *)malloc(sizeof(t_point));
			points[j][i]->x = i;
			points[j][i]->y = j;
			points[j][i]->z = ft_atoi(tokens[i]);
			printf("points[%d][%d]->z: %d\n", j, i, points[j][i]->z);
			i++;
		}
		printf("points[%d][4]->z: %d\n", j, points[j][4]->z);
		j++;
	}
	// printf("points[3][5]->z: %d\n", (points[3][5])->z);
	return (points);
}

/*
** you really only want to read once though, right, instead of parsing through it
** a million fucking times w/ gnl.
** grab_input needs to malloc in points.
** parse through errors after you grabbed the points.
** i'm passing through 'points' WAY too much.
*/
t_point				***grab_input(int argc, char **argv)
{
	int			fd;
	char		**line;
	t_point		***points;

	fd = open(argv[1], O_RDONLY);
	if (!(line = ft_memalloc(sizeof(char **))))
		return (NULL);
	if (argc != 2)
		exit_error("usage: ./fdf source_file");
	points = grab_points(fd, line);
	close(fd);
	return (points);
}
