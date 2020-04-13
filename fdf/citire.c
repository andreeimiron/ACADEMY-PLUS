/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   citire.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:36:04 by anmiron           #+#    #+#             */
/*   Updated: 2017/03/24 17:51:44 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nr_lines(int fd)
{
	int		nr;
	char	*line;

	nr = 0;
	while (get_next_line(fd, &line))
		nr++;
	close(fd);
	return (nr);
}

char	**read_mat(char **src, int lines, int fd, char *filename)
{
	int		i;
	int		nr;
	char	*line;
	char	**mat;

	mat = src;
	i = 0;
	fd = open(filename, O_RDONLY);
	mat = (char**)malloc(sizeof(char *) * lines + 1);
	while (get_next_line(fd, &line))
	{
		nr = nr_collumn(line);
		mat[i] = (char *)malloc(sizeof(char) * nr + 1);
		mat[i] = ft_strdup(line);
		i++;
	}
	close(fd);
	return (mat);
}

void	initializare(t_fdf *mat)
{
	mat->sin = 40;
	mat->cos = 30;
	mat->ox = 0;
	mat->oy = 0;
	mat->height = 0.15;
	mat->zoom = 0.75;
	mat->c = 0;
	mat->color = (int*)malloc(sizeof(int) * 11 + 1);
	mat->color[0] = 0xFFFFFF;
	mat->color[1] = 0X00FFFF;
	mat->color[2] = 0x00FF00;
	mat->color[3] = 0xFF00FF;
	mat->color[4] = 0xFFFF00;
	mat->color[5] = 0xFF0000;
	mat->color[6] = 0xFF69B4;
	mat->color[7] = 0x1E90FF;
	mat->color[8] = 0xCD853F;
	mat->color[9] = 0x7B68EE;
	mat->color[10] = 0x709080;
}

int		fdf(char *filename, t_fdf *mat)
{
	int			fd;

	mat->chr_mat = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	mat->line = nr_lines(fd);
	mat->chr_mat = read_mat(mat->chr_mat, mat->line, fd, filename);
	mat->collumn = nr_collumn(mat->chr_mat[0]);
	if (!validation(mat) || mat->line == 0 || mat->collumn == 0)
		return (0);
	mat->mat = char_to_int(mat->chr_mat, mat->collumn, mat->line);
	initializare(mat);
	desenare(mat);
	return (1);
}

int		main(int argc, char **argv)
{
	t_fdf	mat;

	if (argc < 2)
	{
		ft_putstr("usage: ./fdf [filename]\n");
		return (0);
	}
	if (!fdf(argv[1], &mat))
	{
		ft_putstr("Something went wrong. Check input file.\n");
		return (0);
	}
	return (0);
}
