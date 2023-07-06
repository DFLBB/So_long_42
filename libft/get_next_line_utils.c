/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:48:29 by dlanzas           #+#    #+#             */
/*   Updated: 2023/06/29 09:49:40 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char **s1, char **s2, size_t chars)
{
	char	*joins;
	size_t	c;
	size_t	a;
	size_t	lens1;

	lens1 = gnl_strlen(*s1);
	a = 0;
	c = -1;
	joins = malloc((lens1 + chars + 1) * sizeof(char));
	if (!joins)
		return (NULL);
	while ((*s1)[++c] != '\0' && c < lens1)
		joins[c] = (*s1)[c];
	while ((*s2)[a] != '\0' && a < chars)
		joins[c++] = (*s2)[a++];
	joins[c] = '\0';
	(free (*s1), *s1 = NULL);
	*s2 = gnl_bzero(*s2, chars);
	return (joins);
}

char	*gnl_bzero(char *s2, size_t chars)
{
	size_t	c;

	c = 0;
	while (c < chars)
	{
		s2[c] = '\0';
		c++;
	}
	return (s2);
}

char	*gnl_realloc(char **line, size_t size, size_t start)
{
	char	*aux_realloc;
	size_t	c;

	c = 0;
	aux_realloc = malloc(size * sizeof(char));
	if (!aux_realloc)
		return (NULL);
	while (c < size)
	{
		aux_realloc[c] = (*line)[start];
		c++;
		start++;
	}
	if (*line != NULL)
		(free (*line), *line = NULL);
	return (aux_realloc);
}

char	*gnl_strlcpy(char *dst, const char *src, size_t start, size_t end)
{
	size_t	c;

	c = 0;
	while (src[start] != '\0' && start < end)
	{
		dst[c] = src[start];
		c++;
		start++;
	}
	return (dst);
}

size_t	gnl_strlen(const char *s)
{
	size_t	c;

	c = 0;
	if (s == NULL)
		return (0);
	while (s[c] != '\0')
		c++;
	return (c);
}
