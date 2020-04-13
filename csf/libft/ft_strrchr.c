/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:09:05 by anmiron           #+#    #+#             */
/*   Updated: 2016/12/30 16:40:08 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = ft_strlen(s);
	if (c == '\0')
	{
		p = (char*)&s[i];
		return (p);
	}
	while (i >= 0)
	{
		if (s[i] == c)
		{
			p = (char*)&s[i];
			return (p);
		}
		i--;
	}
	return (NULL);
}
