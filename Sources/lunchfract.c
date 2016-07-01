/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunchfract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 19:10:57 by atoulous          #+#    #+#             */
/*   Updated: 2016/07/01 16:30:12 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_image(t_var *var)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (COLOR)
	{
		r = COLOR >> 0;
		g = COLOR >> 8;
		b = COLOR >> 16;
	}
	else
	{
		r = 0x000000 >> 16;
		g = 0x000000 >> 8;
		b = 0x000000 >> 0;
	}
	if (X >= 0 && X < WIDTH_WIN && Y > 0 && Y < HEIGHT_WIN)
	{
		DATA[Y * SIZELINE + X * (BPP / 8)] = r;
		DATA[Y * SIZELINE + X * (BPP / 8) + 1] = g;
		DATA[Y * SIZELINE + X * (BPP / 8) + 2] = b;
	}
}

int		ft_lunchfrac(t_var *var)
{
	if (!ft_strcmp(FRACTOL, "Mandelbrot") || !ft_strcmp(FRACTOL, "mandelbrot"))
		ft_mandelbrot(var);
	if (!ft_strcmp(FRACTOL, "Julia") || !ft_strcmp(FRACTOL, "julia"))
		ft_julia(var);
	if (!ft_strcmp(FRACTOL, "Buddhabrot") || !ft_strcmp(FRACTOL, "buddhabrot"))
		ft_buddhabrot(var);
	if (!ft_strcmp(FRACTOL, "Ricobrot") || !ft_strcmp(FRACTOL, "ricobrot"))
		ft_ricobrot(var);
	if (!ft_strcmp(FRACTOL, "Burningship")
			|| !ft_strcmp(FRACTOL, "burningship"))
		ft_burningship(var);
	if (!ft_strcmp(FRACTOL, "Sierpinski") || !ft_strcmp(FRACTOL, "sierpinski"))
		ft_sierpinski(var);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 40);
	init_window(var);
	return (0);
}

int		ft_reset_fract(t_var *var)
{
	SPEED = 1;
	ZOOM = 0;
	POS_X = 0;
	POS_Y = 0;
	NX = 0;
	NY = 0;
	IM = 0;
	V = 0;
	return (0);
}

void	ft_refresh_image(t_var *var)
{
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
		{
			COLOR = 0x0;
			fill_image(var);
		}
	}
}

void	ft_freefrac(t_var *var)
{
	mlx_destroy_image(MLX, IMG);
	free(FRACTOL);
	free(var);
}
