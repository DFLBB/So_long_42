/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:29:12 by dlanzas           #+#    #+#             */
/*   Updated: 2022/09/30 18:59:17 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	l;

	c = 0;
	l = 0;
	while (src[l] != '\0')
		l++;
	c = 0;
	if (dstsize > 0)
	{
		while (src[c] != '\0' && c < (dstsize - 1))
		{
			dst[c] = src[c];
			c++;
		}
		dst[c] = '\0';
	}
	return (l);
}
