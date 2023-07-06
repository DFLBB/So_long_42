/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:28:43 by dlanzas           #+#    #+#             */
/*   Updated: 2022/10/07 17:40:14 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		c;
	int		a;

	c = 0;
	a = 0;
	while (s1[c] != '\0')
		c++;
	copy = malloc(c + 1);
	if (!copy)
		return (NULL);
	while (a < c)
	{
		copy[a] = s1[a];
		a++;
	}
	copy[a] = '\0';
	return (copy);
}
