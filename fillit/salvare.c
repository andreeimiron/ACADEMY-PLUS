/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salvare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:07:30 by anmiron           #+#    #+#             */
/*   Updated: 2017/02/24 18:20:51 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		*add_list(t_tetris **lst, char *coord, char letter)
{
	t_tetris	*new;
	t_tetris	*x;

	new = (t_tetris*)malloc(sizeof(*new));
	new->coord = (char*)malloc(sizeof(char) * 8);
	ft_memcpy(new->coord, coord, 8);
	new->letter = letter;
	new->next = NULL;
	x = *lst;
	if (letter == 'A')
		*lst = new;
	else
	{
		while (x->next)
			x = x->next;
		x->next = new;
	}
	return (x);
}

void			put_coord(char **mat, int i, int j, char **coord)
{
	mat[i][j] = '.';
	ft_strcat(*coord, ft_itoa(i - 5 * (i / 5)));
	ft_strcat(*coord, ft_itoa(j));
	if (i > 0 && mat[i - 1][j] == '#')
		put_coord(mat, i - 1, j, coord);
	if (j < 3 && mat[i][j + 1] == '#')
		put_coord(mat, i, j + 1, coord);
	if (i < 3 && mat[i + 1][j] == '#')
		put_coord(mat, i + 1, j, coord);
	if (j > 0 && mat[i][j - 1] == '#')
		put_coord(mat, i, j - 1, coord);
}

char			*move(char *src)
{
	int		i;
	char	*str;
	char	x;
	char	y;

	str = src;
	i = 0;
	x = '4';
	y = '4';
	while (i < 8)
	{
		if (str[i] < x)
			x = str[i];
		if (str[i + 1] < y)
			y = str[i + 1];
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		str[i] -= (x - '0');
		str[i + 1] -= (y - '0');
		i += 2;
	}
	return (str);
}

t_tetris		*salvare(char **mat, int nr)
{
	int			i;
	int			j;
	char		*coord;
	t_tetris	*tetris;

	i = -1;
	coord = (char *)malloc(sizeof(char) * 8);
	while (++i < nr)
	{
		if (i % 5 != 4)
		{
			j = -1;
			while (++j < 4)
			{
				if (mat[i][j] == '#')
					put_coord(mat, i, j, &coord);
			}
		}
		if (i % 5 == 3)
		{
			add_list(&tetris, move(coord), (i / 5) + 'A');
			ft_strclr(coord);
		}
	}
	return (tetris);
}
