/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:09:04 by anmiron           #+#    #+#             */
/*   Updated: 2017/05/25 19:30:28 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_extra1(t_fractol *fract)
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
				fract->zr = sqrt(fabs(fract->zr * fract->zr - fract->zi *
							fract->zi)) + fract->cr;
				fract->zi = 3 * fract->zi * fract->tmp + fract->ci;
				fract->iter++;
			}
			pixel_color(fract);
			fract->y++;
		}
		fract->x++;
	}
}

void	draw_extra2(t_fractol *fract)
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
				fract->zi = -2 * fract->zi * fract->tmp + fract->ci;
				fract->iter++;
			}
			pixel_color(fract);
			fract->y++;
		}
		fract->x++;
	}
}

void	draw_extra3(t_fractol *fract)
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
				fract->zr = fabs(fract->zr * fract->zr - fract->zi * fract->zi)
					+ fract->cr;
				fract->zi = 2 * fract->zi * fract->tmp + fract->ci;
				fract->iter++;
			}
			pixel_color(fract);
			fract->y++;
		}
		fract->x++;
	}
}

void	draw_extra4(t_fractol *fract)
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
				fract->zr = sqrt(fabs(fract->zr * fract->zr - fract->zi *
							fract->zi)) + fract->cr;
				fract->zi = fabs(4 * fract->zi * fract->tmp) + fract->ci;
				fract->iter++;
			}
			pixel_color(fract);
			fract->y++;
		}
		fract->x++;
	}
}

void	draw_extra5(t_fractol *fract)
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
				fract->zr = fabs(fract->zr * fract->zr - fract->zi * fract->zi)
					+ fract->cr;
				fract->zi = 2 * fract->zi * fract->tmp + fract->ci;
				fract->iter++;
			}
			pixel_color(fract);
			fract->y++;
		}
		fract->x++;
	}
}
