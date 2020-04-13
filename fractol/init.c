/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:25:24 by anmiron           #+#    #+#             */
/*   Updated: 2017/05/27 12:59:37 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractals(t_fractol *fract)
{
	fract->ox = -2.75;
	fract->oy = -2;
	fract->imax = 60;
	fract->zoom = H / 4.0;
	fract->cr = -0.8;
	fract->ci = -0.15;
	fract->move = 1;
	fract->r = 5;
	fract->g = 5;
	fract->b = 5;
	redraw(fract);
	mlx_hook(fract->win, 2, 3, function, fract);
	if (fract->id == 1 || fract->id == 6)
		mlx_hook(fract->win, 6, 1L << 6, mouse_move, fract);
	mlx_mouse_hook(fract->win, mouse_function, fract);
}

void	initializare(t_fractol *fract, char *str)
{
	fract->mlx = mlx_init();
	fract->img = mlx_new_image(fract->mlx, W, H);
	fract->win = mlx_new_window(fract->mlx, W, H, "Fractol");
	fract->img_str = mlx_get_data_addr(fract->img, &(fract->bits),
			&(fract->size), &(fract->end));
	if (ft_strcmp(str, "julia") == 0)
		fract->id = 1;
	if (ft_strcmp(str, "mandelbrot") == 0)
		fract->id = 2;
	if (ft_strcmp(str, "burningship") == 0)
		fract->id = 3;
	if (ft_strcmp(str, "extra1") == 0)
		fract->id = 4;
	if (ft_strcmp(str, "extra2") == 0)
		fract->id = 5;
	if (ft_strcmp(str, "extra3") == 0)
		fract->id = 6;
	if (ft_strcmp(str, "extra4") == 0)
		fract->id = 7;
	if (ft_strcmp(str, "extra5") == 0)
		fract->id = 8;
	init_fractals(fract);
}
