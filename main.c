/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:39:00 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/12 16:14:08 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void			exit_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

t_session		*setup_environment(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_session	*env;

	line = NULL;
	if (argc != 2)
		exit_error("usage: ./fdf source_file");
	if (!ft_strendsw(argv[1], ".fdf"))
		exit_error("error: not an .fdf file");
	env = ft_memalloc(sizeof(t_session));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "fdf");
	fd = open(argv[1], O_RDONLY);
	env->map = grab_input_parameters(fd, line);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	env->points = grab_points(fd, line, env->map);
	close(fd);
	env->image = new_image(env);
	mlx_key_hook(env->win, handle_keypress, env);
	free(line);
	return (env);
}

int			main(int argc, char **argv)
{
	t_session	*env;

	env = setup_environment(argc, argv);
	print_image(env);
	free(env->image->pixel_addr);
	mlx_loop(env->mlx);
	return (0);
}
