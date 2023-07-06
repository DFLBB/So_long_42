/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:51:58 by dlanzas           #+#    #+#             */
/*   Updated: 2022/09/26 13:47:06 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;

	a = (char *)dst;
	if (dst == NULL && src == NULL)
		return (dst);
	if (src < dst)
	{
		while (len--)
		{
			*((char *)dst + len) = *((char *)src + len);
		}
	}
	else
	{
		while (len > 0)
		{
			*a = *(char *)src;
			a++;
			src++;
			len--;
		}
	}
	return (dst);
}
