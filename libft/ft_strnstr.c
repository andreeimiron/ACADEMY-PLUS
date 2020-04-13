/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:43:07 by anmiron           #+#    #+#             */
/*   Updated: 2017/01/10 15:05:21 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t l)
{
	size_t i;
	size_t x;

	i = 0;
	if (*to_find == 0)
		return ((char *)str);
	while (str[i] && i < l)
	{
		x = 0;
		while (to_find[x] == str[i + x] && i + x < l)
		{
			if (to_find[x + 1] == '\0')
				return ((char *)(str + i));
			x++;
		}
		i++;
	}
	return (NULL);
}
