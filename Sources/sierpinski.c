/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 17:35:54 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/30 14:57:17 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_calcski(t_var *var)
{
	ZI = fabsl(X + POS_X - NX);
	ZR = fabsl(Y + POS_Y - NY);
	I = -1;
	while (((int)ZI % 3 != 1 || (int)ZR % 3 != 1) && ++I < ITERMAX)
	{
		ZI /= 3;
		ZR /= 3;
	}
	if (I != ITERMAX)
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

void		ft_sierpinski(t_var *var)
{
	ITERMAX = IM + 10;
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
			ft_calcski(var);
	}
}
