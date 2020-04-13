/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:54:23 by anmiron           #+#    #+#             */
/*   Updated: 2016/12/30 15:55:21 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int l;
	int x;

	i = 0;
	l = 0;
	x = 0;
	while (to_find[l])
		l++;
	if (l == 0)
		return ((char *)str);
	while (str[i])
	{
		while (to_find[x] == str[i + x])
		{
			if (x == l - 1)
				return ((char *)(str + i));
			x++;
		}
		x = 0;
		i++;
	}
	return (0);
}
