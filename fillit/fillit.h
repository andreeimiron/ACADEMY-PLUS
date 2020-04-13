/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:28:05 by anmiron           #+#    #+#             */
/*   Updated: 2017/02/20 18:04:05 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"
# define BUFF_SIZE 10000

typedef struct		s_tetris
{
	char			*coord;
	char			letter;
	struct s_tetris	*next;
}					t_tetris;

typedef struct		s_map
{
	int				i;
	int				j;
	int				size;
	char			**map;
}					t_map;

int					nr_linii(char **mat);
int					size(t_tetris *tetris);
int					fillit(char *filename, t_map *map);
int					verif_creare(t_map map, t_tetris *t);
int					solve_map(t_map map, t_tetris *tetris);
int					verificare(char **mat, int nr);
int					verif_linie(char **mat, int i, int *v, int *piese);
int					nr_vecini(char **mat, int i, int j);
t_tetris			*add_list(t_tetris **lst, char *coord, char letter);
t_tetris			*salvare(char **mat, int nr);
void				creare(t_map map, t_tetris *t, char p);
void				afisare(char **map, int size);
void				put_coord(char **mat, int i, int j, char **coord);
char				*move(char *src);
char				**umplere(int size);
char				**citire(int fd);
t_map				solve(t_tetris *tetris);

#endif
