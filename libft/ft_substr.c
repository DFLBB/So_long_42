/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:48:06 by dlanzas           #+#    #+#             */
/*   Updated: 2022/10/10 17:35:00 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		c;
	size_t	l;

	if (!s)
		return (NULL);
	l = len;
	if (len > (size_t)ft_strlen(s))
		l = ft_strlen(s);
	c = 0;
	if (start >= (unsigned int)(ft_strlen(s)))
		return (ft_strdup(""));
	subs = malloc(sizeof(char) * (l + 1));
	if (!subs)
		return (NULL);
	while (len > 0 && s[c + start] != '\0')
	{
		subs[c] = s[c + start];
		c++;
		len--;
	}
	subs[c] = '\0';
	return (subs);
}
