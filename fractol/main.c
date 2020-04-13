/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:07:29 by anmiron           #+#    #+#             */
/*   Updated: 2017/06/02 17:38:56 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_color(t_fractol *fract)
{
	if (fract->iter == fract->imax)
	{
		fract->img_str[fract->size * fract->y + 4 * fract->x + 2] = 0;
		fract->img_str[fract->size * fract->y + 4 * fract->x + 1] = 0;
		fract->img_str[fract->size * fract->y + 4 * fract->x] = 0;
	}
	else
	{
		fract->img_str[fract->size * fract->y + 4 * fract->x + 2] =
			fract->iter * 255 / fract->imax * fract->b;
		fract->img_str[fract->size * fract->y + 4 * fract->x + 1] =
			fract->iter * 255 / fract->imax * fract->b * fract->g;
		fract->img_str[fract->size * fract->y + 4 * fract->x] =
			fract->iter * 255 / fract->imax * fract->b * fract->g * fract->r;
	}
}

void	legend(t_fractol *fract)
{
	mlx_string_put(fract->mlx, fract->win, 70, 1, 0xFFFFFF, "Change colors: C \
			| Zoom in/out: SCROLL, +, - | Change motion: M       | \
			Current iteration: ");
	mlx_string_put(fract->mlx, fract->win, 975, 1, 0xFFFFFF,
			ft_itoa(fract->imax));
	mlx_string_put(fract->mlx, fract->win, 270, 21, 0xFFFFFF, "Move: RIGHT, UP,\
			LEFT, DOWN | Reset: R | Exit: ESC");
	if (fract->move == 1 && (fract->id == 1 || fract->id == 6))
		mlx_string_put(fract->mlx, fract->win, 715, 1, 0xFFFFFF, "(ON)");
	else
		mlx_string_put(fract->mlx, fract->win, 710, 1, 0xFFFFFF, "(OFF)");
}

int		check_param(char *str)
{
	if (ft_strcmp(str, "julia") != 0 &&
			ft_strcmp(str, "mandelbrot") != 0 &&
			ft_strcmp(str, "burningship") != 0 &&
			ft_strcmp(str, "extra1") != 0 &&
			ft_strcmp(str, "extra2") != 0 &&
			ft_strcmp(str, "extra3") != 0 &&
			ft_strcmp(str, "extra4") != 0 &&
			ft_strcmp(str, "extra5") != 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_fractol	fract;
	t_fractol	fract1;

	if (argc < 2 || !check_param(argv[1]) ||
			(argc > 2 && !check_param(argv[2])))
	{
		ft_putstr("usage: ./fractol [julia, mandelbrot, burningship]\n");
		ft_putstr("You can also try: extra1, extra2, extra3, extra4, extra5\n");
		return (0);
	}
	if (argc > 2)
	{
		initializare(&fract, argv[2]);
		initializare(&fract1, argv[1]);
		mlx_loop(fract1.mlx);
		mlx_loop(fract.mlx);
	}
	else
	{
		initializare(&fract, argv[1]);
		mlx_loop(fract.mlx);
	}
	return (0);
}
