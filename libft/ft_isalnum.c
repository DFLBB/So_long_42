/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:04:11 by dlanzas           #+#    #+#             */
/*   Updated: 2022/09/26 13:17:43 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int n)
{
	int	res;

	res = ft_isdigit(n);
	if (res == 1)
		return (1);
	res = ft_isalpha(n);
	if (res == 1)
		return (1);
	return (0);
}
