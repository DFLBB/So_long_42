/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:29:50 by dlanzas           #+#    #+#             */
/*   Updated: 2022/11/16 14:12:34 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digits(int n)
{
	int	c;

	if (n == 0)
		return (1);
	c = 0;
	if (n < 0)
		c = 1;
	while (n != 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_change(char *num, int d)
{
	char	a;
	int		c;

	if (num[0] != 45)
		c = 0;
	else
	{
		c = 1;
		d++;
	}
	while (c <= d / 2)
	{
		a = num[c];
		num[c] = num[d - c];
		num[d - c] = a;
		c++;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		a;
	int		d;
	int		c;

	d = ft_digits(n);
	num = ft_calloc(sizeof(char), (d + 1));
	if (!num)
		return (NULL);
	c = -1;
	a = 0;
	if (n < 0)
	{
		num[0] = '-';
		c++;
	}
	while (d > ++c)
	{
		a = n % 10;
		if (a < 0)
			a = -a;
		n /= 10;
		num[c] = (char)a + '0';
	}
	return (ft_change(num, d - 1));
}
