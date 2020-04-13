/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:03:07 by anmiron           #+#    #+#             */
/*   Updated: 2017/01/13 20:00:42 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *p;
	t_list *aux;

	if (!lst || !f)
		return (NULL);
	aux = (*f)(lst);
	p = aux;
	while (lst->next)
	{
		lst = lst->next;
		aux->next = (*f)(lst);
		if (aux->next == NULL)
			return (NULL);
		aux = aux->next;
	}
	return (p);
}
