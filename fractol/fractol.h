/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:15:06 by anmiron           #+#    #+#             */
/*   Updated: 2017/05/27 13:01:02 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# define W 1100
# define H 800

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_str;
	int			id;
	int			x;
	int			y;
	int			size;
	int			end;
	int			bits;
	int			move;
	int			iter;
	int			imax;
	int			r;
	int			g;
	int			b;
	double		ox;
	double		oy;
	double		zoom;
	double		tmp;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
}				t_fractol;

void			initializare(t_fractol *fract, char *str);
void			init_fractals(t_fractol *fract);
void			draw_julia(t_fractol *fract);
void			draw_mandelbrot(t_fractol *fract);
void			draw_burningship(t_fractol *fract);
void			draw_extra1(t_fractol *fract);
void			draw_extra2(t_fractol *fract);
void			draw_extra3(t_fractol *fract);
void			draw_extra4(t_fractol *fract);
void			draw_extra5(t_fractol *fract);
void			redraw(t_fractol *fract);
void			pixel_color(t_fractol *fract);
void			color_move(int keycode, t_fractol *fract);
void			legend(t_fractol *fract);
int				mouse_move(int x, int y, t_fractol *fract);
int				function(int keycode, t_fractol *fract);
int				mouse_function(int keycode, int x, int y, t_fractol *fract);

#endif
