/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:05:25 by dlanzas           #+#    #+#             */
/*   Updated: 2022/10/10 17:16:09 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_number(const char *str, int neg)
{
	long int	num;

	num = 0;
	while (*str > 47 && *str < 58)
	{
		num = (num * 10) + (*str - 48);
		if (num > 2147483648 && neg == -1)
			return (0);
		if (num > 2147483647 && neg == 1)
			return (-1);
		str++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	size_t	num;
	int		neg;

	neg = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			neg *= -1;
		str++;
	}
	if (*str > 47 && *str < 58)
		num = ft_number(str, neg);
	else
		return (0);
	return (num * neg);
}
