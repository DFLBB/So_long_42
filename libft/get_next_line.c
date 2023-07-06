/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:05:04 by dlanzas           #+#    #+#             */
/*   Updated: 2023/06/29 09:47:42 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_tab(char *line)
{
	int	a;

	if (line == NULL)
		return (0);
	if (line[0] == '\n')
		return (1);
	a = 0;
	while (line[a] != '\n' && line[a] != '\0')
		a++;
	if (line[a] != '\0')
		return (a + 1);
	return (0);
}

char	*gnl_extract(char *line, size_t c)
{
	char	*aux2;

	aux2 = malloc((c + 1) * sizeof(char));
	if (!aux2)
		return (NULL);
	aux2[c] = '\0';
	aux2 = gnl_strlcpy(aux2, line, 0, c);
	return (aux2);
}

char	*gnl_read_line(char *line, size_t fd)
{
	size_t	chars;
	char	*aux;
	int		c;

	chars = 1;
	if (!line)
		line = gnl_bzero(malloc(1), 1);
	c = 0;
	aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
	{
		(free(aux), aux = NULL);
		return (NULL);
	}
	while (chars > 0 && c == 0)
	{
		chars = read(fd, aux, BUFFER_SIZE);
		aux[chars] = '\0';
		if (chars > 0)
			line = gnl_strjoin(&line, &aux, chars);
		c = get_tab(line);
	}
	if (aux)
		(free(aux), aux = NULL);
	return (line);
}

char	*gnl_buffer(char **line, size_t c, size_t len)
{
	char	*end;

	if (c == 0)
	{
		end = malloc((len + 1) * sizeof(char));
		if (!end)
			return (NULL);
		end[len] = '\0';
		end = gnl_strlcpy(end, *line, 0, len + 1);
		(free(*line), *line = NULL);
		return (end);
	}
	end = gnl_extract(*line, c);
	return (end);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	size_t		c;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (line)
			(free(line), line = NULL);
		return (NULL);
	}
	line = gnl_read_line(line, fd);
	if (!line || *line == '\0')
	{
		(free(line), line = NULL);
		return (NULL);
	}
	c = get_tab(line);
	len = gnl_strlen(line);
	buffer = gnl_buffer(&line, c, len);
	if (c > 0)
		line = gnl_realloc(&line, len - c + 1, c);
	return (buffer);
}
