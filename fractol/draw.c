/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:25:53 by anmiron           #+#    #+#             */
/*   Updated: 2017/06/05 14:15:57 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractol *fract)
{
	fract->x = 0;
	while (fract->x < W)
	{
		fract->y = 0;
		while (fract->y < H)
		{
			fract->iter = 0;
			fract->cr = fract->cr;
			fract->ci = fract->ci;
			fract->zr = fract->x / fract->zoom + fract->ox;
			fract->zi = fract->y / fract->zoom + fract->oy;
			while (fract->zr * fract->zr + fract->zi * fract->zi < 4 &&
					fract->iter < fract->imax)
			{
				fract->tmp = fract->zr;
				fract->zr = fract->zr * fract->zr - fract->zi * fract->zi +
					fract->cr;
				fract->zi = 2 * fract->zi * fract->tmp + fract->ci;
				fract->iter++;
			}
			pixel_color(fract);
			fract->y++;
		}
		fract->x++;
	}
}

void	draw_mandelbrot(t_fractol *fract)
{
	fract->x = 0;
	while (fract->x < W)
	{
		fract->y = 0;
		while (fract->y < H)
		{
			fract->iter = 0;
			fract->cr = fract->x / fract->zoom + fract->ox;
			fract->ci = fract->y / fract->zoom + fract->oy;
			fract->zr = 0;
			fract->zi = 0;
			while (fract->zr * fract->zr + fract->zi * fract->zi < 4 &&
					fract->iter < fract->imax)
			{
				fract->tmp = fract->zr;
				fract->zr = fract->zr * fract->zr - fract->zi * fract->zi +
					fract->cr;
				fract->zi = 2 * fract->zi * fract->tmp + fract->ci;
				fract->iter++;
			}
			pixel_color(fract);
			fract->y++;
		}
		fract->x++;
	}
}

void	draw_burningship(t_fractol *fract)
{
	fract->x = 0;
	while (fract->x < W)
	{
		fract->y = 0;
		while (fract->y < H)
		{
			fract->iter = 0;
			fract->cr = fract->x / fract->zoom + fract->ox;
			fract->ci = fract->y / fract->zoom + fract->oy;
			fract->zr = 0;
			fract->zi = 0;
			while (fract->zr * fract->zr + fract->zi * fract->zi < 4 &&
					fract->iter < fract->imax)
			{
				fract->tmp = fract->zr;
				fract->zr = fabs(fract->zr * fract->zr - fract->zi * fract->zi +
						fract->cr);
				fract->zi = fabs(2 * fract->zi * fract->tmp + fract->ci);
				fract->iter++;
			}
			pixel_color(fract);
			fract->y++;
		}
		fract->x++;
	}
}

int		mouse_move(int x, int y, t_fractol *fract)
{
	if (fract->move % 2)
		if (x > 0 && x <= W && y > 0 && y <= H)
		{
			x -= fract->x;
			y -= fract->y;
			fract->cr = ((float)x / (W / 2)) * 2;
			fract->ci = ((float)y / (H / 2)) * 2;
			redraw(fract);
		}
	return (0);
}

void	redraw(t_fractol *fract)
{
	if (fract->id == 1)
		draw_julia(fract);
	if (fract->id == 2)
		draw_mandelbrot(fract);
	if (fract->id == 3)
		draw_burningship(fract);
	if (fract->id == 4)
		draw_extra1(fract);
	if (fract->id == 5)
		draw_extra2(fract);
	if (fract->id == 6)
		draw_extra3(fract);
	if (fract->id == 7)
		draw_extra4(fract);
	if (fract->id == 8)
		draw_extra5(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	legend(fract);
}
