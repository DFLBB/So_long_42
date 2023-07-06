/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:01:51 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/07/06 12:10:53 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_initial_images(t_vars *v)
{
	int		cx;
	int		cy;

	cy = -1;
	while (++cy < v->num_lines)
	{
		cx = -1;
		while (++cx < v->num_cols)
		{
			if (v->map[cy][cx] == '1')
				mlx_put_image_to_window(v->mlx, v->mw, v->i1, cx * 64, cy * 64);
			else if (v->map[cy][cx] == 'C')
				mlx_put_image_to_window(v->mlx, v->mw, v->i3, cx * 64, cy * 64);
			else if (v->map[cy][cx] == 'P')
			{
				v->pos_x = cx;
				v->pos_y = cy;
				mlx_put_image_to_window(v->mlx, v->mw, v->i4, cx * 64, cy * 64);
			}
			else if (v->map[cy][cx] == 'E')
				mlx_put_image_to_window(v->mlx, v->mw, v->i5, cx * 64, cy * 64);
			else
				mlx_put_image_to_window(v->mlx, v->mw, v->i2, cx * 64, cy * 64);
		}
	}
}

static void	sl_check_sprites(t_vars *v)
{
	if (v->i1 == NULL)
		sl_error(IMAGE);
	if (v->i2 == NULL)
		sl_error(IMAGE);
	if (v->i3 == NULL)
		sl_error(IMAGE);
	if (v->i4 == NULL)
		sl_error(IMAGE);
	if (v->i5 == NULL)
		sl_error(IMAGE);
	if (v->i6 == NULL)
		sl_error(IMAGE);
	if (v->i7 == NULL)
		sl_error(IMAGE);
	if (v->i8 == NULL)
		sl_error(IMAGE);
	if (v->i9 == NULL)
		sl_error(IMAGE);
}

static void	draw_images(t_vars *v)
{
	v->img_w = 64;
	v->img_h = 64;
	v->mlx = mlx_init();
	v->mw = mlx_new_window(v->mlx,
			64 * v->num_cols, 64 * v->num_lines, "Sokoban tribute");
	v->i1 = mlx_xpm_file_to_image(v->mlx, PATH1, &v->img_w, &v->img_h);
	v->i2 = mlx_xpm_file_to_image(v->mlx, PATH2, &v->img_w, &v->img_h);
	v->i3 = mlx_xpm_file_to_image(v->mlx, PATH3, &v->img_w, &v->img_h);
	v->i4 = mlx_xpm_file_to_image(v->mlx, PATH4, &v->img_w, &v->img_h);
	v->i5 = mlx_xpm_file_to_image(v->mlx, PATH5, &v->img_w, &v->img_h);
	v->i6 = mlx_xpm_file_to_image(v->mlx, PATH6, &v->img_w, &v->img_h);
	v->i7 = mlx_xpm_file_to_image(v->mlx, PATH7, &v->img_w, &v->img_h);
	v->i8 = mlx_xpm_file_to_image(v->mlx, PATH8, &v->img_w, &v->img_h);
	v->i9 = mlx_xpm_file_to_image(v->mlx, PATH9, &v->img_w, &v->img_h);
	sl_check_sprites(v);
}

void	draw_map(t_vars *v)
{
	v->num_box = 0;
	v->num_door = 0;
	v->num_start = 0;
	if (check_map(v) != 0)
		sl_error(MAP);
	draw_images(v);
	sl_initial_images(v);
	mlx_hook(v->mw, 17, 0L, my_close, v);
	mlx_hook(v->mw, 2, 1L << 0, key_handler, v);
	mlx_loop(v->mlx);
}
