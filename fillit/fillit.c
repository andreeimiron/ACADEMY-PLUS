/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:20:26 by anmiron           #+#    #+#             */
/*   Updated: 2017/02/23 19:49:13 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nr_linii(char **mat)
{
	int		nr;
	int		i;

	nr = 0;
	i = 0;
	while (mat[nr])
	{
		nr++;
	}
	return (nr);
}

char	**citire(int fd)
{
	int		a;
	char	*buf;
	char	**mat;

	buf = (char*)malloc(sizeof(char) * 10000);
	mat = (char**)malloc(sizeof(char*) * 1000);
	a = read(fd, buf, 10000);
	buf[a] = '\0';
	mat = ft_strsplit(buf, '\n');
	return (mat);
}

int		fillit(char *filename, t_map *map)
{
	int			fd;
	int			nr;
	char		**mat;
	t_tetris	*tetris;

	mat = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	mat = citire(fd);
	nr = nr_linii(mat);
	if (!verificare(mat, nr))
		return (0);
	tetris = salvare(mat, nr);
	*map = solve(tetris);
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <input file>\n");
		return (0);
	}
	if (!fillit(argv[1], &map))
	{
		ft_putstr("error\n");
		return (0);
	}
	afisare(map.map, map.size);
	return (0);
}
