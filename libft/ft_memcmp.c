/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:27:23 by dlanzas           #+#    #+#             */
/*   Updated: 2022/09/26 16:41:27 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*p;
	char	*r;

	p = (char *)s1;
	r = (char *)s2;
	while (n-- > 0)
	{
		if ((unsigned char)*p == (unsigned char)*r)
		{
			p++;
			r++;
		}
		else
			return ((unsigned char)*p - (unsigned char)*r);
	}
	return (0);
}
