/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 12:32:52 by atoulous          #+#    #+#             */
/*   Updated: 2016/07/01 16:24:28 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../Libs/libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <OpenCL/opencl.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define PURPLE 0xFF00FF
# define SKY 0x00FFFF
# define RESET ft_reset_fract(var)

# define MLX var->mlx
# define WIN var->win
# define IMG var->img
# define BPP var->bpp
# define SIZELINE var->sizeline
# define ENDIAN var->endian
# define WIDTH_WIN var->width_win
# define HEIGHT_WIN var->height_win
# define ZOOM var->zoom
# define SPEED var->speed
# define Z var->z
# define POS_X var->pos_x
# define POS_Y var->pos_y
# define COLOR var->color
# define VARCOL var->varcol
# define DATA var->data
# define FRACTOL var->fractol

# define ITERMAX var->itermax
# define IM var->im
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
# define V var->v
# define ZOOM_X var->zoom_x
# define ZOOM_Y var->zoom_y
# define NX var->nx
# define NY var->ny
# define SX var->sx
# define SY var->sy
# define VJ var->vj

typedef struct		s_var
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*fractol;
	double			zoom;
	double			speed;
	double			z;
	double			pos_x;
	double			pos_y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	double			t;
	double			v;
	double			zoom_x;
	double			zoom_y;
	double			nx;
	double			ny;
	int				color;
	int				varcol;
	int				bpp;
	int				sizeline;
	int				endian;
	int				width_win;
	int				height_win;
	int				itermax;
	int				im;
	int				x;
	int				y;
	int				i;
	int				sx;
	int				sy;
	int				vj;
}					t_var;

int					ft_lunchfrac(t_var *var);
int					ft_key(int keycode, t_var *var);
int					ft_mouse(int button, int x, int y, t_var *var);
int					ft_motion_mouse(int x, int y, t_var *var);
int					ft_reset_fract(t_var *var);
void				fill_image(t_var *var);
void				init_window(t_var *var);
void				ft_refresh_image(t_var *var);
void				ft_freefrac(t_var *var);

void				ft_mandelbrot(t_var *var);
void				ft_julia(t_var *var);
void				ft_buddhabrot(t_var *var);
void				ft_ricobrot(t_var *var);
void				ft_burningship(t_var *var);
void				ft_sierpinski(t_var *var);

#endif
