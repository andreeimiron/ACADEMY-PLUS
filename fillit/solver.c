/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:59:14 by anmiron           #+#    #+#             */
/*   Updated: 2017/01/27 18:51:24 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		size(t_tetris *tetris)
{
	int		i;
	int		s;

	i = 0;
	s = 1;
	while (tetris)
	{
		i++;
		tetris = tetris->next;
	}
	while (s * s < i * 4)
		s++;
	return (s);
}

void	creare(t_map map, t_tetris *t, char p)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 8)
	{
		x = map.i + (t->coord[i] - '0');
		y = map.j + (t->coord[i + 1] - '0');
		map.map[x][y] = p;
		i += 2;
	}
}

int		verif_creare(t_map map, t_tetris *t)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 8)
	{
		x = map.i + (t->coord[i] - '0');
		y = map.j + (t->coord[i + 1] - '0');
		if (x >= map.size || y >= map.size || x < 0 || y < 0 ||
				ft_isalpha(map.map[x][y]))
			return (0);
		i += 2;
	}
	creare(map, t, t->letter);
	return (1);
}

int		solve_map(t_map map, t_tetris *tetris)
{
	if (tetris == NULL)
		return (1);
	map.i = 0;
	while (map.i < map.size)
	{
		map.j = 0;
		while (map.j < map.size)
		{
			if (verif_creare(map, tetris))
			{
				if (solve_map(map, tetris->next))
					return (1);
				else
					creare(map, tetris, '.');
			}
			map.j++;
		}
		map.i++;
	}
	return (0);
}

t_map	solve(t_tetris *tetris)
{
	t_map	map;

	map.size = size(tetris);
	map.map = umplere(map.size);
	while (!solve_map(map, tetris))
	{
		map.size++;
		map.map = umplere(map.size);
	}
	return (map);
}
