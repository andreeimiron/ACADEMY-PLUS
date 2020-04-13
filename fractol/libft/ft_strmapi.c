/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:20:16 by anmiron           #+#    #+#             */
/*   Updated: 2017/01/13 18:22:24 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;
	int				len;

	i = 0;
	if (s && f)
	{
		len = ft_strlen((char *)s);
		p = (char *)malloc(len + 1);
		if (p == NULL)
			return (NULL);
		while (s[i])
		{
			p[i] = f(i, s[i]);
			i++;
		}
		p[i] = 0;
		return (p);
	}
	return (NULL);
}
