/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 12:32:52 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/27 12:23:47 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../Libs/libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <OpenCL/opencl.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

# define MLX var->mlx
# define WIN var->win
# define IMG var->img
# define BPP var->bpp
# define SIZELINE var->sizeline
# define ENDIAN var->endian
# define WIDTH_WIN var->width_win
# define HEIGHT_WIN var->height_win
# define ZOOM var->zoom
# define POS_X var->pos_x
# define POS_Y var->pos_y
# define COLOR var->color
# define DATA var->data
# define FRACTOL var->fractol

# define ITERMAX var->itermax
# define X var->x
# define X1 var->x1
# define X2 var->x2
# define Y var->y
# define Y1 var->y1
# define Y2 var->y2
# define I var->i
# define CR var->cr
# define CI var->ci
# define ZR var->zr
# define ZI var->zi
# define T var->t
# define ZOOM_X var->zoom_x
# define ZOOM_Y var->zoom_y

typedef struct		s_var
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*fractol;
	int				color;
	int				bpp;
	int				sizeline;
	int				endian;
	int				width_win;
	int				height_win;
	int				itermax;
	int				x;
	int				y;
	int				i;
	long double		zoom;
	long double		pos_x;
	long double		pos_y;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		cr;
	long double		ci;
	long double		zr;
	long double		zi;
	long double		t;
	long double		zoom_x;
	long double		zoom_y;
}					t_var;

int					ft_lunchfrac(t_var *var);
int					ft_key(int keycode, t_var *var);
int					ft_mouse(int button, int x, int y, t_var *var);
void				fill_image(t_var *var);
void				init_window(t_var *var);
void				ft_refresh_image(t_var *var);
void				ft_freefrac(t_var *var);

void				ft_mandelbrot(t_var *var);
void				ft_julia(t_var *var);
void				ft_buddhabrot(t_var *var);
#endif
