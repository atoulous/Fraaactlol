/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 12:27:00 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/29 18:40:51 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_name(t_var *var, char *name)
{
	if (!ft_strcmp(name, "Mandelbrot") || !ft_strcmp(name, "mandelbrot"))
		FRACTOL = ft_strdup(name);
	else if (!ft_strcmp(name, "Julia") || !ft_strcmp(name, "julia"))
		FRACTOL = ft_strdup(name);
	else if (!ft_strcmp(name, "Buddhabrot") || !ft_strcmp(name, "buddhabrot"))
		FRACTOL = ft_strdup(name);
	else if (!ft_strcmp(name, "Ricobrot") || !ft_strcmp(name, "ricobrot"))
		FRACTOL = ft_strdup(name);
	else if (!ft_strcmp(name, "Burningship") || !ft_strcmp(name, "burningship"))
		FRACTOL = ft_strdup(name);
	else if (!ft_strcmp(name, "Sierpinski") || !ft_strcmp(name, "sierpinski"))
		FRACTOL = ft_strdup(name);
	else
	{
		ft_putendl("Not a valid name, try Mandelbrot or Julia");
		ft_freefrac(var);
		exit(EXIT_FAILURE);
	}
}

void	init_window(t_var *var)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH_WIN)
	{
		y = -1;
		while (++y < 40)
			mlx_pixel_put(MLX, WIN, x, y, 0x0);
	}
	mlx_string_put(MLX, WIN, 10, 0, 0xFFFFFF, "SPEED =");
	mlx_string_put(MLX, WIN, 90, 0, 0xFFFFFF, ft_itoa(SPEED));
	mlx_string_put(MLX, WIN, 10, 20, 0xFFFFFF, "ZOOM =");
	mlx_string_put(MLX, WIN, 90, 20, 0xFFFFFF, ft_itoa(ZOOM * SPEED));
	mlx_string_put(MLX, WIN, 200, 0, 0xFFFFFF, "X =");
	mlx_string_put(MLX, WIN, 260, 0, 0xFFFFFF, ft_itoa(SX));
	mlx_string_put(MLX, WIN, 200, 20, 0xFFFFFF, "Y =");
	mlx_string_put(MLX, WIN, 260, 20, 0xFFFFFF, ft_itoa(SY));
	mlx_string_put(MLX, WIN, 400, 0, 0xFFFFFF, "ITERMAX =");
	mlx_string_put(MLX, WIN, 500, 0, 0xFFFFFF, ft_itoa(ITERMAX));
	mlx_string_put(MLX, WIN, 400, 20, 0xFFFFFF, "FRACTAL =");
	mlx_string_put(MLX, WIN, 500, 20, 0xFFFFFF, FRACTOL);
}

int		init_fractol(t_var *var)
{
	WIDTH_WIN = 1280;
	HEIGHT_WIN = 1024;
	SPEED = 1;
	ZOOM = 0;
	POS_X = 0;
	POS_Y = 0;
	NX = 0;
	NY = 0;
	IM = 0;
	SX = 0;
	SY = 0;
	VARCOL = YELLOW;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_WIN, HEIGHT_WIN + 40, FRACTOL);
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	init_window(var);
	return (0);
}

void	ft_fractol(char *name)
{
	t_var	*var;

	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
		return (exit(EXIT_FAILURE));
	check_name(var, name);
	init_fractol(var);
	mlx_loop_hook(MLX, ft_lunchfrac, var);
	mlx_hook(WIN, KeyPress, KeyPressMask, ft_key, var);
	mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_mouse, var);
	mlx_loop(MLX);
	ft_freefrac(var);
}

int		main(int ac, char **av)
{
	int		i;

	if (ac != 2)
		ft_putendl("Usage: ./fractol <Mandelbrot/Julia/Buddhabrot>");
	else
	{
		i = 0;
		while (++i < ac)
			ft_fractol(av[i]);
	}
	return (0);
}
