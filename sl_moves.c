/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:13:28 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/06/29 20:28:45 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_move_up(t_vars *v)
{
	if (v->map[v->pos_y - 1][v->pos_x] && v->map[v->pos_y - 1][v->pos_x] != '1')
	{
		if (v->map[v->pos_y][v->pos_x] != 'E')
			mlx_put_image_to_window(v->mlx, v->mw,
				v->i2, v->pos_x * 64, v->pos_y * 64);
		else
			mlx_put_image_to_window(v->mlx, v->mw,
				v->i5, v->pos_x * 64, v->pos_y * 64);
		v->pos_y = v->pos_y - 1;
		v->num_movs++;
		mlx_put_image_to_window(v->mlx, v->mw,
			v->i4, v->pos_x * 64, v->pos_y * 64);
	}
}

void	sl_move_down(t_vars *v)
{
	if (v->map[v->pos_y + 1][v->pos_x] && v->map[v->pos_y + 1][v->pos_x] != '1')
	{
		if (v->map[v->pos_y][v->pos_x] != 'E')
			mlx_put_image_to_window(v->mlx, v->mw,
				v->i2, v->pos_x * 64, v->pos_y * 64);
		else
			mlx_put_image_to_window(v->mlx, v->mw,
				v->i5, v->pos_x * 64, v->pos_y * 64);
		v->pos_y = v->pos_y + 1;
		v->num_movs++;
		mlx_put_image_to_window(v->mlx, v->mw,
			v->i6, v->pos_x * 64, v->pos_y * 64);
	}
}

void	sl_move_left(t_vars *v)
{
	if (v->map[v->pos_y][v->pos_x - 1] && v->map[v->pos_y][v->pos_x - 1] != '1')
	{
		if (v->map[v->pos_y][v->pos_x] != 'E')
			mlx_put_image_to_window(v->mlx, v->mw,
				v->i2, v->pos_x * 64, v->pos_y * 64);
		else
			mlx_put_image_to_window(v->mlx, v->mw,
				v->i5, v->pos_x * 64, v->pos_y * 64);
		v->pos_x = v->pos_x - 1;
		v->num_movs++;
		mlx_put_image_to_window(v->mlx, v->mw,
			v->i7, v->pos_x * 64, v->pos_y * 64);
	}
}

void	sl_move_right(t_vars *v)
{
	if (v->map[v->pos_y][v->pos_x + 1] && v->map[v->pos_y][v->pos_x + 1] != '1')
	{
		if (v->map[v->pos_y][v->pos_x] != 'E')
			mlx_put_image_to_window(v->mlx, v->mw,
				v->i2, v->pos_x * 64, v->pos_y * 64);
		else
			mlx_put_image_to_window(v->mlx, v->mw,
				v->i5, v->pos_x * 64, v->pos_y * 64);
		v->pos_x = v->pos_x + 1;
		v->num_movs++;
		mlx_put_image_to_window(v->mlx, v->mw,
			v->i8, v->pos_x * 64, v->pos_y * 64);
	}
}

void	sl_move(int movement, t_vars *v)
{
	int	movs_ant;

	check_exit(movement, v);
	movs_ant = v->num_movs;
	if (movement == 1)
		sl_move_up(v);
	else if (movement == 2)
		sl_move_down(v);
	else if (movement == 3)
		sl_move_left(v);
	else if (movement == 4)
		sl_move_right(v);
	if (movs_ant != v->num_movs)
		sl_print_move(v);
	if (v->map[v->pos_y][v->pos_x] == 'C')
	{
		v->num_box--;
		v->map[v->pos_y][v->pos_x] = '0';
	}
	if (v->num_box == 0)
		mlx_put_image_to_window(v->mlx, v->mw,
			v->i9, v->pos_door_x * 64, v->pos_door_y * 64);
}
