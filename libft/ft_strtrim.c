/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:04:02 by dlanzas           #+#    #+#             */
/*   Updated: 2022/11/16 13:20:27 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_clean(void)
{
	char	*trim;

	trim = malloc(sizeof(char) * 1);
	if (!trim)
		return (NULL);
	trim[0] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1);
	if (*s1 == '\0')
		return (ft_clean());
	while (s1[first] != '\0' && ft_strchr(set, s1[first]))
		first++;
	if (first >= last)
		return (ft_clean());
	while (last > first && ft_strchr(set, s1[last]))
		last--;
	trim = ft_substr(s1, first, last - first + 1);
	if (!trim)
		return (NULL);
	trim[last - first + 1] = '\0';
	return (trim);
}
