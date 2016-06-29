/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 20:02:04 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/29 19:34:59 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_reset_fract(t_var *var)
{
	SPEED = 1;
	ZOOM = 0;
	POS_X = 0;
	POS_Y = 0;
	NX = 0;
	NY = 0;
	IM = 0;
	init_window(var);
	return (0);
}

int		ft_mouse(int button, int x, int y, t_var *var)
{
	SX = x;
	SY = y;
	dprintf(1, "button==%d  ", button);
	dprintf(1, "x==%d  y==%d\n", SX, SY);
	if ((button == 1 || button == 4) &&
			(SX < WIDTH_WIN && SX > 0 && SY > 40 && SY < HEIGHT_WIN))
	{
		ZOOM += ZOOM < 200 ? 50 : 100;
		NX += WIDTH_WIN / 2 - SX;
		NY += HEIGHT_WIN / 2 - SY;
	}
	if ((button == 2 || button == 6) &&
			(SX < WIDTH_WIN && SX > 0 && SY < HEIGHT_WIN && SY > 40))
	{
		ZOOM -= ZOOM < 200 ? 50 : 100;
		NX += WIDTH_WIN / 2 - SX;
		NY += HEIGHT_WIN / 2 - SY;
	}
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
	{
		NX ? RESET : 0;
		ZOOM += ZOOM < 200 ? 50 : 100;
	}
	if (keycode == 78)
	{
		NX ? RESET : 0;
		ZOOM -= ZOOM < 200 ? 50 : 100;
	}
}

void	ft_switchfrac(int keycode, t_var *var)
{
	keycode == 83 ? FRACTOL = ft_strdupfree(FRACTOL, "Mandelbrot") : 0;
	keycode == 84 ? FRACTOL = ft_strdupfree(FRACTOL, "Julia") : 0;
	keycode == 85 ? FRACTOL = ft_strdupfree(FRACTOL, "Buddhabrot") : 0;
	keycode == 86 ? FRACTOL = ft_strdupfree(FRACTOL, "Ricobrot") : 0;
	keycode == 87 ? FRACTOL = ft_strdupfree(FRACTOL, "Burningship") : 0;
	keycode == 88 ? FRACTOL = ft_strdupfree(FRACTOL, "Sierpinski") : 0;
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
	ft_switchfrac(keycode, var);
	keycode == 18 ? VARCOL = BLUE : COLOR;
	keycode == 19 ? VARCOL = GREEN : COLOR;
	keycode == 20 ? VARCOL = RED : COLOR;
	keycode == 21 ? VARCOL = YELLOW : COLOR;
	keycode == 23 ? VARCOL = PURPLE : COLOR;
	keycode == 22 ? VARCOL = WHITE : COLOR;
	keycode == 27 && ITERMAX > 1 ? --IM : 0;
	keycode == 24 ? ++IM : 0;
	keycode == 75 && SPEED > 1 ? --SPEED : 0;
	keycode == 67 ? ++SPEED : 0;
	keycode == 49 ? ft_reset_fract(var) : 0;
	init_window(var);
	return (0);
}
