/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:21:39 by dlanzas           #+#    #+#             */
/*   Updated: 2022/10/07 18:58:04 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joins;
	int		c;

	c = 0;
	if (!s1 || !s2)
		return (NULL);
	joins = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joins)
		return (0);
	while (*s1 != '\0')
	{
		joins[c] = *s1;
		c++;
		s1++;
	}
	while (*s2 != '\0')
	{
		joins[c] = *s2;
		c++;
		s2++;
	}
	if ((*s1 == '\0' && *s2 == '\0'))
		joins[c] = *s1;
	return (joins);
}
