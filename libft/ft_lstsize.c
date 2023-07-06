/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:44:54 by dlanzas           #+#    #+#             */
/*   Updated: 2022/10/28 16:58:45 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*actual;
	int		c;

	c = 0;
	actual = lst;
	while (actual != NULL)
	{
		c++;
		actual = actual -> next;
	}
	return (c);
}
