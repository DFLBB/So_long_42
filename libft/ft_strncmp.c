/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:29:40 by dlanzas           #+#    #+#             */
/*   Updated: 2022/09/26 18:07:40 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while ((s1[c] != '\0' || s2[c] != '\0') && c < n)
	{
		if ((unsigned int)s1[c] == (unsigned int)s2[c])
			c++;
		else
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
	}
	return (0);
}
