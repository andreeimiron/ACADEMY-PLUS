/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desenare.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:55:27 by anmiron           #+#    #+#             */
/*   Updated: 2017/03/24 17:52:18 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	conversie(t_fdf *mat)
{
	int		i;
	int		j;
	double	space;
	double	sin_a;
	double	cos_a;

	i = 0;
	space = mat->zoom * (W / (mat->line * 0.5 + mat->collumn * 0.86));
	sin_a = sin(mat->sin * M_PI / 180);
	cos_a = cos(mat->cos * M_PI / 180);
	while (i < mat->line)
	{
		j = 0;
		while (j < mat->collumn)
		{
			mat->mat[i][j].x = (i - mat->line / 2) * space * -cos_a +
				(j - mat->collumn / 2) * space * cos_a + W / 2 + mat->ox;
			mat->mat[i][j].y = (i - mat->line / 2) * space * sin_a -
				(j - mat->collumn / 2) * space * -sin_a - mat->mat[i][j].z *
				space * mat->height + H / 2 + mat->oy;
			j++;
		}
		i++;
	}
	legend(mat);
}

int		draw(t_fdf *mat)
{
	int			i;
	int			j;
	t_dpoints	dp;

	i = -1;
	mlx_clear_window(mat->mlx, mat->win);
	conversie(mat);
	while (++i < mat->line)
	{
		j = -1;
		while (++j < mat->collumn)
		{
			if (j < mat->collumn - 1)
			{
				init_dpoints_1(&dp, mat, i, j);
				draw_line(dp, mat);
			}
			if (i < mat->line - 1)
			{
				init_dpoints_2(&dp, mat, i, j);
				draw_line(dp, mat);
			}
		}
	}
	return (0);
}

void	draw_line(t_dpoints dp, t_fdf *mat)
{
	t_draw	d;

	d.dx = abs(dp.x1 - dp.x0);
	d.dy = abs(dp.y1 - dp.y0);
	d.sx = dp.x0 < dp.x1 ? 1 : -1;
	d.sy = dp.y0 < dp.y1 ? 1 : -1;
	d.err = (d.dx > d.dy ? d.dx : -d.dy) / 2;
	while (1)
	{
		if (dp.y0 > 43)
			mlx_pixel_put(mat->mlx, mat->win, dp.x0, dp.y0, mat->color[mat->c]);
		if (dp.x0 == dp.x1 && dp.y0 == dp.y1)
			break ;
		d.e2 = d.err;
		if (d.e2 > -d.dx)
		{
			d.err -= d.dy;
			dp.x0 += d.sx;
		}
		if (d.e2 < d.dy)
		{
			d.err += d.dx;
			dp.y0 += d.sy;
		}
	}
}

void	desenare(t_fdf *mat)
{
	mat->mlx = mlx_init();
	mat->win = mlx_new_window(mat->mlx, W, H, "Fdf");
	mlx_expose_hook(mat->win, draw, mat);
	mlx_key_hook(mat->win, function, mat);
	mlx_loop(mat->mlx);
}
