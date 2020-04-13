/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:25:39 by anmiron           #+#    #+#             */
/*   Updated: 2017/01/13 19:20:52 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	str = ft_strdup(str);
	if (str == NULL)
		return (NULL);
	i = ft_strlen(str) - 1;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && i >= 0)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}
