/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:47:16 by dlanzas           #+#    #+#             */
/*   Updated: 2022/10/27 17:32:30 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	c;

	c = 0;
	if (s)
	{
		while (c < ft_strlen(s))
		{
			write(fd, &s[c], sizeof(s[c]));
			c++;
		}
		write(fd, "\n", sizeof(char));
	}
	else
		c = 0;
}
