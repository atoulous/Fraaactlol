/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunchfract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 19:10:57 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/26 22:24:06 by atoulous         ###   ########.fr       */
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
	DATA[Y * SIZELINE + X * (BPP / 8)] = r;
	DATA[Y * SIZELINE + X * (BPP / 8) + 1] = g;
	DATA[Y * SIZELINE + X * (BPP / 8) + 2] = b;
}

int		ft_lunchfrac(t_var *var)
{
	if (!ft_strcmp(FRACTOL, "Mandelbrot") || !ft_strcmp(FRACTOL, "mandelbrot"))
		ft_mandelbrot(var);
	if (!ft_strcmp(FRACTOL, "Julia") || !ft_strcmp(FRACTOL, "julia"))
		ft_julia(var);
	if (!ft_strcmp(FRACTOL, "Buddhabrot") || !ft_strcmp(FRACTOL, "buddhabrot"))
		ft_buddhabrot(var);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 40);
	return (0);
}

void	ft_refresh_image(t_var *var)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
}

void	ft_freefrac(t_var *var)
{
	mlx_destroy_image(MLX, IMG);
	free(FRACTOL);
	free(var);
}
