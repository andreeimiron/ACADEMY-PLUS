/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:59:59 by anmiron           #+#    #+#             */
/*   Updated: 2016/12/30 15:42:29 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			p = (char*)&s[i];
			return (p);
		}
		i++;
	}
	if (c == s[i])
	{
		p = (char*)&s[i];
		return (p);
	}
	return (NULL);
}
