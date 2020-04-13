/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:38:31 by anmiron           #+#    #+#             */
/*   Updated: 2017/03/24 19:16:42 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# define W 1100
# define H 800

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_fdf
{
	char		**chr_mat;
	t_point		**mat;
	int			line;
	int			collumn;
	void		*mlx;
	void		*win;
	int			sin;
	int			cos;
	double		height;
	int			ox;
	int			oy;
	double		zoom;
	int			*color;
	int			c;
}				t_fdf;

typedef struct	s_draw
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_draw;

typedef struct	s_dpoints
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_dpoints;

void			init_dpoints_1(t_dpoints *dp, t_fdf *mat, int i, int j);
void			init_dpoints_2(t_dpoints *dp, t_fdf *mat, int i, int j);
int				validation(t_fdf *mat);
int				function(int keycode, t_fdf *mat);
int				nr_collumn(const char *str);
void			legend(t_fdf *mat);
void			initializare(t_fdf *mat);
void			conversie(t_fdf *mat);
void			desenare(t_fdf *mat);
void			draw_line(t_dpoints dp, t_fdf *mat);
int				draw(t_fdf *mat);
t_point			**char_to_int(char **src, int collumn, int lines);

#endif
