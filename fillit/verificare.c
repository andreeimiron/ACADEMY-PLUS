/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:06:36 by anmiron           #+#    #+#             */
/*   Updated: 2017/02/11 15:49:59 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nr_vecini(char **mat, int i, int j)
{
	int		s;

	s = 0;
	if (i - 5 * (i / 5) > 0 && mat[i - 1][j] == '#')
		s++;
	if (j > 0 && mat[i][j - 1] == '#')
		s++;
	if (i - 5 * (i / 5) < 3 && mat[i + 1][j] == '#')
		s++;
	if (j < 3 && mat[i][j + 1] == '#')
		s++;
	return (s);
}

int		verif_linie(char **mat, int i, int *v, int *piese)
{
	int		j;

	j = 0;
	if (i - 5 * (i / 5) == 0)
	{
		*v = 0;
		*piese = 0;
	}
	while (j < 4)
	{
		if (mat[i][j] != '.' && mat[i][j] != '#' && mat[i][j] != '\0')
			return (0);
		if (mat[i][j] == '#')
		{
			*v += nr_vecini(mat, i, j);
			*(piese) += 1;
		}
		j++;
	}
	return (1);
}

int		verificare(char **mat, int nr)
{
	int		i;
	int		v;
	int		piese;

	i = 0;
	if (nr > 129 || (nr % 10 != 4 && nr % 10 != 9))
		return (0);
	while (i < nr)
	{
		if (verif_linie(mat, i, &v, &piese) == 0)
			return (0);
		if (i - 5 * (i / 5) == 3 && ((v != 6 && v != 8) || piese != 4))
			return (0);
		if (i % 5 == 4)
		{
			if (ft_strlen(mat[i]) > 0)
				return (0);
			piese = 0;
			v = 0;
		}
		else if (ft_strlen(mat[i]) != 4)
			return (0);
		i++;
	}
	return (1);
}

void	afisare(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**umplere(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (char**)malloc(sizeof(char*) * size);
	while (i < size)
	{
		j = 0;
		map[i] = ft_strnew(size);
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
