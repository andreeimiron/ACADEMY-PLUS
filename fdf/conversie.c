/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validare.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:00:59 by anmiron           #+#    #+#             */
/*   Updated: 2017/03/23 17:14:55 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nr_collumn(const char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (count);
}

t_point	**char_to_int(char **src, int collumn, int lines)
{
	int		i;
	int		j;
	t_point	**mat;
	char	**str;

	i = 0;
	mat = (t_point**)malloc(sizeof(t_point*) * lines * 3);
	while (i < lines)
	{
		j = 0;
		str = ft_strsplit(src[i], ' ');
		mat[i] = (t_point*)malloc(sizeof(t_point) * collumn + 1);
		while (j < collumn)
		{
			mat[i][j].x = i;
			mat[i][j].y = j;
			mat[i][j].z = ft_atoi(str[j]);
			j++;
		}
		i++;
	}
	return (mat);
}

int		validation(t_fdf *mat)
{
	int		i;

	i = 0;
	while (i < mat->line)
	{
		if (mat->collumn != nr_collumn(mat->chr_mat[i]))
			return (0);
		i++;
	}
	return (1);
}

void	init_dpoints_1(t_dpoints *dp, t_fdf *mat, int i, int j)
{
	dp->x0 = mat->mat[i][j].x;
	dp->y0 = mat->mat[i][j].y;
	dp->x1 = mat->mat[i][j + 1].x;
	dp->y1 = mat->mat[i][j + 1].y;
}

void	init_dpoints_2(t_dpoints *dp, t_fdf *mat, int i, int j)
{
	dp->x0 = mat->mat[i][j].x;
	dp->y0 = mat->mat[i][j].y;
	dp->x1 = mat->mat[i + 1][j].x;
	dp->y1 = mat->mat[i + 1][j].y;
}
