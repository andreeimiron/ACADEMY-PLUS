/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:04:20 by anmiron           #+#    #+#             */
/*   Updated: 2017/05/26 20:43:02 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_function(int keycode, int x, int y, t_fractol *fract)
{
	double	xx;
	double	yy;

	if (y > 0)
	{
		xx = x / fract->zoom + fract->ox;
		yy = y / fract->zoom + fract->oy;
		if (keycode == 4)
		{
			fract->zoom *= 1.1;
			fract->imax += 2;
		}
		if (keycode == 5)
		{
			fract->zoom /= 1.1;
			fract->imax -= 2;
		}
		fract->ox = xx - x / fract->zoom;
		fract->oy = yy - y / fract->zoom;
		redraw(fract);
	}
	return (0);
}

void	color_move(int keycode, t_fractol *fract)
{
	if (keycode == 8)
	{
		fract->r += 1;
		fract->g += 2;
		fract->b += 3;
	}
	if (keycode == 123)
		fract->ox += 5 / (fract->imax * fract->zoom / 1000);
	if (keycode == 124)
		fract->ox -= 5 / (fract->imax * fract->zoom / 1000);
	if (keycode == 126)
		fract->oy += 5 / (fract->imax * fract->zoom / 1000);
	if (keycode == 125)
		fract->oy -= 5 / (fract->imax * fract->zoom / 1000);
}

void	zoom(int keycode, t_fractol *fract)
{
	double	xx;
	double	yy;

	xx = W / 2 / fract->zoom + fract->ox;
	yy = H / 2 / fract->zoom + fract->oy;
	if (keycode == 69)
		fract->zoom *= 1.1;
	if (keycode == 78)
		fract->zoom /= 1.1;
	fract->ox = xx - W / 2 / fract->zoom;
	fract->oy = xx - H / 2 / fract->zoom;
}

int		function(int keycode, t_fractol *fract)
{
	if (keycode == 53)
	{
		mlx_destroy_image(fract->mlx, fract->img);
		mlx_destroy_window(fract->mlx, fract->win);
		exit(0);
	}
	if (keycode == 46 && (fract->id == 1 || fract->id == 6))
	{
		if (fract->move == 1)
			fract->move = 0;
		else
			fract->move = 1;
	}
	color_move(keycode, fract);
	if (keycode == 69 || keycode == 78)
		zoom(keycode, fract);
	if (keycode == 34)
		fract->imax += 5;
	if (keycode == 31)
		fract->imax -= 5;
	if (keycode == 15)
		init_fractals(fract);
	redraw(fract);
	return (0);
}
