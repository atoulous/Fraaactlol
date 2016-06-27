/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 20:02:04 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/27 15:57:00 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_reset_fract(t_var *var)
{
	ZOOM = 0;
	POS_X = 0;
	POS_Y = 0;
}

int		ft_mouse(int button, int x, int y, t_var *var)
{
	dprintf(1, "x==%d\ny==%d\n", x, y);
	if (button == 1 && x < WIDTH_WIN && x > 0 && y > 40 && y < HEIGHT_WIN)
	{
		ZOOM += ZOOM < 200 ? 50 : 100;
		POS_X += WIDTH_WIN / (long double)x;
		POS_Y += HEIGHT_WIN / (long double)y;
	}
	if (button == 2 && y < HEIGHT_WIN && Y > 40)
		ZOOM -= ZOOM < 200 ? 50 : 100;
	return (0);
}

void	ft_key_move(int keycode, t_var *var)
{
	if (keycode == 124)
		POS_X += ZOOM < 300 ? 0.1 : 0.01;
	if (keycode == 123)
		POS_X -= ZOOM < 300 ? 0.1 : 0.01;
	if (keycode == 125)
		POS_Y += ZOOM < 300 ? 0.1 : 0.01;
	if (keycode == 126)
		POS_Y -= ZOOM < 300 ? 0.1 : 0.01;
	if (keycode == 69)
		ZOOM += ZOOM < 200 ? 50 : 100;
	if (keycode == 78)
		ZOOM -= ZOOM < 200 ? 50 : 100;
}

int		ft_key(int keycode, t_var *var)
{
	if (keycode == 53)
	{
		ft_freefrac(var);
		exit(EXIT_SUCCESS);
	}
	ft_refresh_image(var);
	ft_key_move(keycode, var);
	if (keycode == 49)
		ft_reset_fract(var);
	return (0);
}
