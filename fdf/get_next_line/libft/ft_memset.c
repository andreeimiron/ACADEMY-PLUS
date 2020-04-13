/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:18:18 by anmiron           #+#    #+#             */
/*   Updated: 2016/12/29 18:31:00 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	size_t			l;
	unsigned char	*str;

	i = 0;
	l = len;
	str = b;
	while (i < l)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
