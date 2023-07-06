/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:19:34 by dlanzas           #+#    #+#             */
/*   Updated: 2022/11/16 16:38:33 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number(char *str, char to_find)
{
	int	a;
	int	y;

	a = 0;
	y = 0;
	while (*str != '\0')
	{
		if (*str == to_find && y == 1)
			y = 0;
		else if (*str != to_find && y == 0)
		{
			a++;
			y = 1;
		}
		str++;
	}
	return (a);
}

static int	ft_long(char *s, char c)
{
	int		l;
	int		y;

	y = 0;
	l = 0;
	if (*s == c)
		y = 1;
	while (*s == c && *s != '\0')
		s++;
	while ((*s != c || (*s == c && y == 1)) && *s != '\0')
	{
		if (*s != c)
		{
			y = 0;
			s++;
		}
		else
			s++;
		l++;
	}
	return (l);
}

static void	*ft_free(char **substr, int num)
{
	while (num > 0)
	{
		free(substr[num]);
		substr[num] = NULL;
		num--;
	}
	free(substr);
	substr = NULL;
	return (NULL);
}

static char	**ft_array(char const *s, char c, int num, char **substr)
{
	int		a;
	int		a2;

	a = 0;
	a2 = 0;
	while (a < num)
	{
		substr[a] = malloc((ft_long((char *)s, c) + 1) * sizeof(char));
		if (!substr[a])
			return (ft_free(substr, a));
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
		{
			substr[a][a2] = *s;
			a2++;
			s++;
		}
		substr[a++][a2] = '\0';
		a2 = 0;
	}
	substr[a] = NULL;
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		num;

	if (!s)
		return (NULL);
	num = ft_number((char *)s, c);
	split = malloc((num + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_array((char *)s, c, num, split);
	return (split);
}
