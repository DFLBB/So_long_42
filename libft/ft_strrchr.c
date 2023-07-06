/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:30:09 by dlanzas           #+#    #+#             */
/*   Updated: 2022/09/26 17:09:09 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		l;

	l = ft_strlen((char *)s);
	p = (char *)s;
	while (l >= 0)
	{
		if (p[l] == (char)c)
			return (p + l);
		l--;
	}
	return (NULL);
}
