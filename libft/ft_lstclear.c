/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:50:48 by dlanzas           #+#    #+#             */
/*   Updated: 2022/11/10 16:56:33 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*last;

	if (lst && del)
	{
		while ((*lst) != NULL)
		{
			last = (*lst)-> next;
			ft_lstdelone((*lst), del);
			*lst = last;
		}
	}
}
