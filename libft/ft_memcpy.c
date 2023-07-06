/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:27:37 by dlanzas           #+#    #+#             */
/*   Updated: 2022/09/30 18:51:48 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	a;

	a = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	while (n > 0)
	{
		((char *)dst)[a] = *(char *)src;
		a++;
		src++;
		n--;
	}
	return (dst);
}
