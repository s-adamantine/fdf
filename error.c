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

/*
** current error: not getting the file descriptor??
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

int	**atoi_arr(char **arr)
{
	int i;
	int	**result;

	i = 0;
	result = ft_memalloc(ft_arrlen(arr));
	printf("%d\n", ft_atoi(arr[i]));
	// while (arr[i])
	// {
	// 	*result++ = ft_atoi(arr[i]);
	// 	i++;
	// }
	return (result);
}

/*
** checks if each line has the right number of points.
** then grabs those points and puts them into a structure of points.
** needs to convert the array of characters to an array of integers.
*/

void 	grab_points(int fd)
{
	int		n; //the number of points in each line.
	char	**points;
	char	**line;

	line = ft_memalloc(sizeof(char **));
	get_next_line(fd, line);
	points = ft_strsplit(*line, ' ');
	n = ft_arrlen(points);
	// while (get_next_line(fd, line) > 0)
	// {
	// 	chpoints = ft_strsplit(*line, ' ');
	// 	if (n != ft_arrlen(points))
	// 		exit_error("error: lines contain different numbers of entries");
	// }
}

void	handle_input(int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		exit_error("usage: ./fdf source_file");
	grab_points(fd);
	close(fd);
}
