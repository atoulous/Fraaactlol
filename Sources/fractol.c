/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 12:27:00 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/26 22:05:26 by atoulous         ###   ########.fr       */
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
	else
	{
		ft_putendl("Not a valid name, try Mandelbrot or Julia");
		ft_freefrac(var);
		exit(EXIT_FAILURE);
	}
}

void	init_window(t_var *var)
{
	mlx_string_put(MLX, WIN, 0, 0, 0xFFFFFF, "1 2 3 4 5 6 7 8 9");
}

int		init_fractol(t_var *var)
{
	WIDTH_WIN = 1280;
	HEIGHT_WIN = 1024;
	ZOOM = 0;
	POS_X = 0;
	POS_Y = 0;
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

	if (ac < 2)
		ft_putendl("Usage: ./fractol <Mandelbrot/Julia/Buddhabrot>");
	else
	{
		i = 0;
		while (++i < ac)
			ft_fractol(av[i]);
	}
	return (0);
}
