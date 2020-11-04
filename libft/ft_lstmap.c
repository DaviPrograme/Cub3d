/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:50:01 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:23:00 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*aux_old;
	t_list	*aux_new;

	if (!lst)
		return (NULL);
	if (!(new_list = ft_lstnew((*f)(lst->content))))
		return (NULL);
	aux_new = new_list;
	aux_old = lst->next;
	while (1)
	{
		if (aux_old == NULL)
			break ;
		if (!(aux_new->next = ft_lstnew((*f)(aux_old->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		aux_new = aux_new->next;
		aux_old = aux_old->next;
	}
	return (new_list);
}
