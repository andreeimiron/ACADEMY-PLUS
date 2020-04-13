/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:29:21 by anmiron           #+#    #+#             */
/*   Updated: 2017/03/24 17:52:55 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	legend(t_fdf *mat)
{
	mlx_string_put(mat->mlx, mat->win, 120, 1, 0xB8860B, "Change color: C | \
			Zoom in/out: I, O | Height: +, - | Rotate: NUM2, NUM4, NUM6, NUM8");
	mlx_string_put(mat->mlx, mat->win, 270, 21, 0xB8860B, "Move: RIGHT, UP, \
			LEFT, DOWN | Reset: R | Exit: ESC");
}

void	move(int keycode, t_fdf *mat)
{
	if (keycode == 126)
		mat->oy -= 20;
	if (keycode == 125)
		mat->oy += 20;
	if (keycode == 123)
		mat->ox -= 20;
	if (keycode == 124)
		mat->ox += 20;
	draw(mat);
}

void	zoom_height(int keycode, t_fdf *mat)
{
	if (keycode == 69)
		mat->height += 0.05;
	if (keycode == 78)
		mat->height -= 0.05;
	if (keycode == 34 && mat->zoom <= 2.70)
		mat->zoom += 0.05;
	if (keycode == 31 && mat->zoom >= 0.05)
		mat->zoom -= 0.05;
	draw(mat);
}

void	rotate(int keycode, t_fdf *mat)
{
	if (keycode == 91)
		mat->sin += 5;
	if (keycode == 84)
		mat->sin -= 5;
	if (keycode == 86)
		mat->cos += 5;
	if (keycode == 88)
		mat->cos -= 5;
	draw(mat);
}

int		function(int keycode, t_fdf *mat)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		move(keycode, mat);
	if (keycode == 69 || keycode == 78 || keycode == 31 || keycode == 34)
		zoom_height(keycode, mat);
	if (keycode == 84 || keycode == 86 || keycode == 88 || keycode == 91)
		rotate(keycode, mat);
	if (keycode == 15)
	{
		initializare(mat);
		draw(mat);
	}
	if (keycode == 8)
	{
		if (mat->c < 10)
			mat->c++;
		else
			mat->c = 0;
		draw(mat);
	}
	return (0);
}
