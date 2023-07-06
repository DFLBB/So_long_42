/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:58:04 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/07/06 12:09:08 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free(t_vars *v)
{
	int	i;

	i = -1;
	while (++i < v->num_lines)
	{
		free(v->map[i]);
		free(v->checked_map[i]);
	}
	free(v->map);
	free(v->checked_map);
}

static void	sl_map(t_vars *v)
{
	int		count;
	int		i;
	int		i2;

	count = 0;
	i = 0;
	i2 = 0;
	v->map = malloc(v->num_lines * sizeof(char *));
	if (!v->map)
		(perror("Malloc"), exit(errno));
	while (count < v->num_lines)
	{
		v->map[count] = malloc((v->num_cols) * sizeof(char));
		if (!v->map[count])
			(perror("Malloc"), exit(errno));
		while (v->read_map[i] != '\n' && v->read_map[i] != '\0')
		{
			v->map[count][i2] = v->read_map[i];
			i2++;
			i++;
		}
		count++;
		i++;
		i2 = 0;
	}
}

static void	sl_read_map(t_vars *v, char *file)
{
	char	*line;
	char	*aux;

	v->fd = open (file, O_RDONLY);
	if (v->fd == -1)
		(perror("Open"), exit(errno));
	if (read(v->fd, 0, 1) == 0)
		sl_error(EMPTY);
	line = get_next_line(v->fd);
	v->num_cols = sl_strlen(line);
	v->read_map = ft_calloc(1, 1);
	v->num_lines = 0;
	while (line)
	{
		aux = v->read_map;
		v->read_map = ft_strjoin(v->read_map, line);
		(free(aux), aux = NULL);
		v->num_lines++;
		(free(line), line = NULL);
		line = get_next_line(v->fd);
		if (line && (sl_strlen(line) != v->num_cols))
			sl_error(MAP_NON_RECTANGULAR);
	}
	close(v->fd);
}

int	main(int argc, char **argv)
{
	t_vars	v;
	int		i;

	if (argc == 2)
	{
		i = -1;
		v.num_movs = 0;
		(sl_check_file(argv[1]), sl_read_map(&v, argv[1]));
		v.num_chars = sl_numchars(v.read_map);
		v.checked_map = malloc((v.num_lines) * sizeof(char *));
		if (!v.checked_map)
			(perror("Malloc"), exit(errno));
		while (++i < v.num_lines)
		{
			v.checked_map[i] = malloc((v.num_cols) * sizeof(char));
			if (!v.checked_map[i])
				(perror("Malloc"), exit(errno));
		}
		sl_map(&v);
		draw_map(&v);
	}
	else
		sl_error(ARGS);
	sl_free(&v);
	return (0);
}
