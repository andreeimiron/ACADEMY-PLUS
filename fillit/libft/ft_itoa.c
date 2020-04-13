/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:28:40 by anmiron           #+#    #+#             */
/*   Updated: 2017/01/13 19:10:12 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(long n, int sign)
{
	int	nr;

	nr = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		nr++;
		n /= 10;
	}
	if (sign == 1)
		return (nr + 1);
	return (nr);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		nr;
	int		sign;
	long	x;

	sign = 0;
	x = n;
	if (x < 0)
		sign = 1;
	if (x < 0)
		x = -x;
	nr = length(x, sign);
	if ((str = (char*)malloc((nr + 1) * sizeof(char))) == NULL)
		return (NULL);
	str[nr] = '\0';
	if (sign == 1)
		str[0] = '-';
	nr--;
	while (nr >= sign)
	{
		str[nr] = x % 10 + '0';
		x /= 10;
		nr--;
	}
	return (str);
}
