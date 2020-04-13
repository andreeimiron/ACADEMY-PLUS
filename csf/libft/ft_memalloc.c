/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:43:58 by anmiron           #+#    #+#             */
/*   Updated: 2016/12/30 17:01:05 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*aux;

	aux = (void*)malloc(size);
	if (aux == NULL)
		return (NULL);
	aux = ft_memset(aux, 0, size);
	return (aux);
}
