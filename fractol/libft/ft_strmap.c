/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:19:27 by anmiron           #+#    #+#             */
/*   Updated: 2017/01/13 17:48:14 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	int		i;
	int		len;

	i = 0;
	if (s && f)
	{
		len = ft_strlen((char *)s);
		p = (char *)malloc(len * sizeof(*p) + 1);
		if (p == NULL)
			return (NULL);
		while (s[i])
		{
			p[i] = f(s[i]);
			i++;
		}
		p[i] = 0;
		return (p);
	}
	return (NULL);
}
