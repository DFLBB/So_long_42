/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:17:05 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/07/06 12:14:49 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# define PATH1 "./textures/wall.xpm"
# define PATH2 "./textures/floor.xpm"
# define PATH3 "./textures/box.xpm"
# define PATH4 "./textures/man_up.xpm"
# define PATH5 "./textures/door.xpm"
# define PATH6 "./textures/man_down.xpm"
# define PATH7 "./textures/man_left.xpm"
# define PATH8 "./textures/man_right.xpm"
# define PATH9 "./textures/open_door.xpm"

typedef struct s_vars {
	void	*mlx;
	void	*mw;
	void	*i1;
	void	*i2;
	void	*i3;
	void	*i4;
	void	*i5;
	void	*i6;
	void	*i7;
	void	*i8;
	void	*i9;
	int		fd;
	int		pos_x;
	int		pos_y;
	int		pos_door_x;
	int		pos_door_y;
	char	*read_map;
	char	**map;
	char	**checked_map;
	int		num_movs;
	int		num_box;
	int		num_lines;
	int		num_cols;
	int		num_chars;
	int		num_door;
	int		num_start;
	int		img_w;
	int		img_h;
}				t_vars;
enum e_errors{
	DOORORSTART,
	IMAGE,
	BOXES,
	MAP,
	MAP_NON_RECTANGULAR,
	OTHER,
	OPEN,
	EMPTY,
	ARGS,
	EXTENSION
};
void	sl_error(int num_error);
void	sl_check_file(char *file);
void	sl_move(int movement, t_vars *vars);
int		sl_numlines(char *aux);
int		sl_strlen(const char *s);
int		sl_numchars(char *aux);
int		my_close(t_vars *vars);
void	sl_move_up(t_vars *v);
void	sl_move_down(t_vars *v);
void	sl_move_left(t_vars *v);
void	sl_move_right(t_vars *v);
void	sl_print_move(t_vars *v);
void	sl_free(t_vars *v);
int		key_handler(int keycode, t_vars *vars);
void	check_closed(t_vars *v);
void	check_exit(int movement, t_vars *v);
int		check_map(t_vars *vars);
void	draw_map(t_vars *v);
int		so_long(int argc, char **argv);

#endif