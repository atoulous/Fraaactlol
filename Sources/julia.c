/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 20:04:59 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/26 21:44:36 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_calcjulia(t_var *var)
{
	ZR = (ZOOM + X) / (ZOOM_X + ZOOM) + X1;
	ZI = (ZOOM + Y) / (ZOOM_Y + ZOOM) + Y1;
	CR = 0.285;
	CI = 0.01;
	I = -1;
	while ((ZR * ZR + ZI * ZI) < 4 && ++I < ITERMAX)
	{
		T = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * T + CI;
	}
	if (I == ITERMAX)
	{
		COLOR = 0x000000;
		fill_image(var);
	}
	else
	{
		COLOR = (I * 0x00FFFF / ITERMAX);
		fill_image(var);
	}
}

void		ft_julia(t_var *var)
{
	X1 = -1 + POS_X;
	X2 = 1 + POS_X;
	Y1 = -1.2 + POS_Y;
	Y2 = 1.2 + POS_Y;
	ITERMAX = 150;
	ZOOM_X = (WIDTH_WIN / (X2 - X1));
	ZOOM_Y = (HEIGHT_WIN / (Y2 - Y1));
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
			ft_calcjulia(var);
	}
}
