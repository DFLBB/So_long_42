/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:49:57 by dlanzas           #+#    #+#             */
/*   Updated: 2022/11/10 16:22:13 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	c;
	int	a;

	a = 0;
	if (*needle == '\0' || needle == haystack)
		return ((char *)haystack);
	if ((!haystack && len == 0) || (ft_strlen(needle) > ft_strlen(haystack)))
		return (NULL);
	while (haystack[a] != '\0' && len > 0)
	{
		c = 0;
		if (needle[c] == haystack[a] && len > 0)
		{
			a++;
			len--;
			while (needle[++c] != '\0' && needle[c] == haystack[a] && len-- > 0)
				a++;
			if (needle[c] == '\0' && (int)len >= 0)
				return ((char *)&haystack[a - c]);
		}
		len = len + c - 1;
		a = a - c + 1;
	}
	return (NULL);
}
