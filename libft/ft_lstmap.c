/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas <dlanzas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:48:22 by dlanzas           #+#    #+#             */
/*   Updated: 2022/11/07 16:23:15 by dlanzas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*aux;

	res = NULL;
	if (lst && del && f)
	{
		while (lst != NULL)
		{
			aux = ft_lstnew(f(lst -> content));
			if ((aux -> content) == NULL)
			{
				ft_lstdelone(lst, del);
				return (NULL);
			}
			ft_lstadd_back(&res, aux);
			lst = lst->next;
		}
		return (res);
	}
	return (NULL);
}
