/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:00:35 by dlanzas           #+#    #+#             */
/*   Updated: 2022/10/27 18:18:42 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", sizeof(char));
	else
	{
		if (n == -2147483648)
		{
			write(fd, "-", sizeof(char));
			write(fd, "2", sizeof(char));
			n = 147483648;
		}
		if (n < 0)
		{
			write(fd, "-", sizeof(char));
			n = -n;
		}
		if (n <= 9)
			ft_putchar_fd(n + '0', fd);
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(((n % 10) + '0'), fd);
		}
	}
}
