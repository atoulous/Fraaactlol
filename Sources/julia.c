/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 20:04:59 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/30 18:08:04 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_calcjulia(t_var *var)
{
	ZR = (ZOOM * SPEED + X - NX) / (ZOOM_X) + X1;
	ZI = (ZOOM * SPEED + Y - NY) / (ZOOM_Y) + Y1;
	CR = 0.285 + V;
	CI = V ? 0.01 / V : 0.01;
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

void		ft_julia(t_var *var)
{
	X1 = -1 + POS_X;
	X2 = 1 + POS_X;
	Y1 = -1.2 + POS_Y;
	Y2 = 1.2 + POS_Y;
	ITERMAX = IM + 150;
	ZOOM_X = (WIDTH_WIN / (X2 - X1) + ZOOM * SPEED);
	ZOOM_Y = (HEIGHT_WIN / (Y2 - Y1) + ZOOM * SPEED);
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
			ft_calcjulia(var);
	}
}
