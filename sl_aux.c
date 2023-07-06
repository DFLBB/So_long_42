/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:07:51 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/07/06 12:16:09 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_error(int num_error)
{
	enum e_errors	errors;

	errors = num_error;
	ft_putstr_fd("Error:\n", 1);
	if (errors == 0)
		ft_putstr_fd("Number of starting points / doors is not correct.\n", 1);
	if (errors == 1)
		ft_putstr_fd("The sprites are inaccesibles.\n", 1);
	if (errors == 2)
		ft_putstr_fd("The number of collectibles is not correct.\n", 1);
	if (errors == 3)
		ft_putstr_fd("There are no valid roads on the map.\n", 1);
	if (errors == 4)
		ft_putstr_fd("The map is non-rectangular.\n", 1);
	if (errors == 5)
		ft_putstr_fd("There are symbols not allowed on the map.\n", 1);
	if (errors == 6)
		ft_putstr_fd("The map is not enclosed/surrounded by walls.\n", 1);
	if (errors == 7)
		ft_putstr_fd("The map is empty.\n", 1);
	if (errors == 8)
		ft_putstr_fd("The argument must be one, and only one, map.\n", 1);
	if (errors == 9)
		ft_putstr_fd("The extension of the map is not correct.\n", 1);
	exit(1);
}

void	sl_check_file(char *file)
{
	char	*file_ext;

	file_ext = ft_strrchr(file, '.');
	if (!file_ext || ft_strncmp(file_ext, ".ber", ft_strlen(file)) != 0)
		sl_error(EXTENSION);
}

void	sl_print_move(t_vars *v)
{
	ft_putstr_fd("Movement number: ", 1);
	ft_putnbr_fd(v->num_movs, 1);
	write(1, "\n", 1);
}

void	check_exit(int movement, t_vars *v)
{
	if ((v->num_box == 0)
		&& ((movement == 1 && v->map[v->pos_y - 1][v->pos_x] == 'E')
		|| (movement == 2 && v->map[v->pos_y + 1][v->pos_x] == 'E') ||
		(movement == 3 && v->map[v->pos_y][v->pos_x - 1] == 'E') ||
		(movement == 4 && v->map[v->pos_y][v->pos_x + 1] == 'E')))
	{
		mlx_put_image_to_window(v->mlx, v->mw, v->i4,
			v->pos_x * 64, v->pos_y * 64);
		v->num_movs++;
		sl_print_move(v);
		ft_putstr_fd("So long, and thanks for all the fish!\n", 1);
		my_close(v);
	}
}

void	check_closed(t_vars *v)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < v->num_lines)
	{
		while (x < v->num_cols)
		{
			if ((y == 0 || y == v->num_lines - 1)
				&& v->checked_map[y][x] != '1')
				sl_error(OPEN);
			if ((x == 0 || x == v->num_cols - 1)
				&& v->checked_map[y][x] != '1')
				sl_error(OPEN);
			x++;
		}
		x = 0;
		y++;
	}
}
