/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:28:58 by dlanzas           #+#    #+#             */
/*   Updated: 2022/11/10 16:49:26 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	src_s;
	size_t	dest_s;

	if (!dst && dstsize == 0)
		return (0);
	c = 0;
	src_s = ft_strlen(src);
	dest_s = ft_strlen(dst);
	if (dstsize < dest_s)
		return (src_s + dstsize);
	while (*dst != '\0')
		dst++;
	while ((*src != '\0') && (c < dstsize - dest_s - 1) && (dstsize > dest_s))
	{
		*dst = *(char *)src;
		dst++;
		src++;
		c++;
	}
	*dst = '\0';
	return (src_s + dest_s);
}
