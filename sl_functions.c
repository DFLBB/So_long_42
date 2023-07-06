/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:35:47 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/07/05 17:56:51 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0' && s[c] != '\n')
		c++;
	return (c);
}

int	sl_numchars(char *aux)
{
	int	numchars;

	numchars = 0;
	if (aux == NULL)
		return (0);
	while (aux[numchars] != '\0')
		numchars++;
	return (numchars);
}

int	my_close(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->mw);
	sl_free(v);
	exit (0);
}

int	key_handler(int keycode, t_vars *v)
{
	if (keycode == 53)
		my_close(v);
	else if (keycode == 13 || keycode == 126)
		sl_move(1, v);
	else if (keycode == 1 || keycode == 125)
		sl_move(2, v);
	else if (keycode == 0 || keycode == 123)
		sl_move(3, v);
	else if (keycode == 2 || keycode == 124)
		sl_move(4, v);
	return (0);
}
