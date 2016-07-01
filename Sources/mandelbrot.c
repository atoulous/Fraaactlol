/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 12:35:42 by atoulous          #+#    #+#             */
/*   Updated: 2016/07/01 15:27:58 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_calcbrot(t_var *var)
{
	CR = (X + ZOOM * SPEED - NX) / (ZOOM_X) + X1;
	CI = (Y + ZOOM * SPEED - NY) / (ZOOM_Y) + Y1;
	ZR = 0 + V;
	ZI = 0 + V / 2;
	I = -1;
	while ((ZR * ZR + ZI * ZI) < 4 && ++I < ITERMAX)
	{
		T = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * T + CI;
	}
	if (I == ITERMAX)
	{
		COLOR = BLACK;
		fill_image(var);
	}
	else
	{
		COLOR = (I * VARCOL / ITERMAX);
		fill_image(var);
	}
}

void		ft_mandelbrot(t_var *var)
{
	X1 = -2.1 + POS_X;
	X2 = 0.6 + POS_X;
	Y1 = -1.2 + POS_Y;
	Y2 = 1.2 + POS_Y;
	ITERMAX = IM + 50;
	ZOOM_X = (WIDTH_WIN / (X2 - X1) + ZOOM * SPEED);
	ZOOM_Y = (HEIGHT_WIN / (Y2 - Y1) + ZOOM * SPEED);
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
			ft_calcbrot(var);
	}
}
