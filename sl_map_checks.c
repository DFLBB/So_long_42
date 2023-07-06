/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:15:04 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/07/06 12:13:14 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_elements(t_vars *v)
{
	int	xpos;
	int	ypos;

	ypos = -1;
	while (++ypos < v->num_lines)
	{
		xpos = -1;
		while (++xpos < v->num_cols)
		{
			if (v->map[ypos][xpos] == 'C')
				v->num_box++;
			else if (v->map[ypos][xpos] == 'P')
			{
				v->pos_x = xpos;
				v->pos_y = ypos;
				v->num_start++;
			}
			else if (v->map[ypos][xpos] == 'E')
			{
				v->pos_door_x = xpos;
				v->pos_door_y = ypos;
				v->num_door++;
			}
		}
	}
}

static void	check_objects(t_vars *v)
{
	int	i;

	i = 0;
	check_elements(v);
	if (v->num_door != 1)
		sl_error(DOORORSTART);
	if (v->num_start != 1)
		sl_error(DOORORSTART);
	if (v->num_box < 1)
		sl_error(BOXES);
	while (v->read_map[i])
	{
		if (v->read_map[i] != '1' && v->read_map[i] != '0'
			&& v->read_map[i] != 'P' && v->read_map[i] != 'E'
			&& v->read_map[i] != 'C' && v->read_map[i] != '\n')
			sl_error(OTHER);
		i++;
	}
}

static void	find_road(t_vars *v, int x, int y)
{
	if (y >= 0 && y < v->num_lines && x >= 0 && x < v->num_cols
		&& v->checked_map[y][x] != 'F' && v->checked_map[y][x] != '1')
		v->checked_map[y][x] = 'F';
	if (y + 1 >= 0 && y + 1 < v->num_lines && x >= 0 && x < v->num_cols
		&& v->checked_map[y + 1][x] != 'F' && v->checked_map[y + 1][x] != '1')
		find_road(v, x, y + 1);
	if (y - 1 >= 0 && y - 1 < v->num_lines && x >= 0 && x < v->num_cols
		&& v->checked_map[y - 1][x] != 'F' && v->checked_map[y - 1][x] != '1')
		find_road(v, x, y - 1);
	if (y >= 0 && y < v->num_lines && x + 1 >= 0 && x + 1 < v->num_cols
		&& v->checked_map[y][x + 1] != 'F' && v->checked_map[y][x + 1] != '1')
		find_road(v, x + 1, y);
	if (y >= 0 && y < v->num_lines && x - 1 >= 0 && x - 1 < v->num_cols
		&& v->checked_map[y][x - 1] != 'F' && v->checked_map[y][x - 1] != '1')
		find_road(v, x - 1, y);
}

static int	check_road(t_vars *v)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < v->num_lines)
	{
		while (x < v->num_cols)
		{
			if (v->checked_map[y][x] != 'F' && v->checked_map[y][x] != '1'
				&& v->checked_map[y][x] != '0')
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	check_closed(v);
	return (0);
}

int	check_map(t_vars *v)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	x = 0;
	y = 0;
	check_objects(v);
	while (y < v->num_lines)
	{
		while (x < v->num_cols)
		{
			v->checked_map[y][x] = v->map[y][x];
			x++;
		}
		y++;
		x = 0;
	}
	find_road(v, v->pos_x, v->pos_y);
	return (check_road(v));
}
