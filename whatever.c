// /*
// ** use bresenham's line algorithm to connect two different points together.
// ** y = m(x - xo) + yo
// ** bersenham_x assumes x as the driving axis (x is always incremented, y may or
// ** may not be.
// ** bersenham_y assumes y as the driving axis.
// */
//
//
static t_point		**calibrate_direction(t_point	**points)
{
	t_point	*temp;

	if (points[0]->x > points[1]->x)
	{
		temp = points[0];
		points[0] = points[1];
		points[1] = temp;
	}
	return (points);
}

/*
** figure out how to change the driving axes
** going to connect it w/ point pairs
*/
void				connect_points(t_session *env, t_point **points)
{
	int 	x;
	int 	y;
	int 	deltax;
	int 	deltay;
	int		error;

	points = calibrate_direction(points);
	x = points[0]->x;
	y = points[0]->y;
	deltax = points[1]->x - points[0]->x;
	deltay = points[1]->y - points[0]->y;
	if (deltax == 0)
		return (draw_vertical(env, points));
	else if (deltay == 0)
		return (draw_horizontal(env, points));
	error = abs(deltay - deltax);
	while (x <= points[1]->x)
	{
		pixel_to_image(env, x, y, 0x00FF0000);
		while (error >= 0) //don't make error abs here.
		{
			deltay / deltax >= 0? y++: y--;
			error = error - abs(deltax);
		}
		x++;
		error = error + abs(deltay);
	}
}

void			point_pairs(t_session *env, t_map *map, t_point ***points)
{
	int		i;
	int 	j;
	t_point	**pair;

	j = 0;
	pair = ft_memalloc(sizeof(t_point *) * 2);
	while (j < map->rows - 1)
	{
		i = 0;
		while (i < map->cols)
		{
			pair[0] = points[j][i];
			pair[1] = points[j + 1][i];
			connect_points(env, pair);
			i++;
		}
		j++;
	}
	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols - 1)
		{
			pair[0] = points[j][i];
			pair[1] = points[j][i + 1];
			connect_points(env, pair);
			i++;
		}
		j++;
	}
}
