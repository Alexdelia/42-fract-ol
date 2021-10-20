/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:49:16 by adelille          #+#    #+#             */
/*   Updated: 2021/10/20 20:15:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# include <math.h>
# include <stdio.h>

# define T_JULIA	1
# define T_MANDEL	2

# define M_SCROLL_UP	4
# define M_SCROLL_DOWN	5
# define K_LEFT			123
# define K_RIGHT		124
# define K_DOWN			125
# define K_UP			126

# define SIZE_X			1024
# define SIZE_Y			768

# define MAX_ITERATION	250
# define REAL			-0.7
# define IMAGINARY		0.27015

typedef struct s_img
{
	void		*addr;
	char		*buffer;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	int			type;
	long		ite;
	double		real;
	double		imaginary;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_img		*img;
}				t_env;

typedef struct s_color
{
	double		r;
	double		g;
	double		b;
	int			shadow;
}				t_color;

typedef struct s_complex
{
	double		cr;
	double		ci;
	double		zr;
	double		zi;
}				t_complex;

int			ft_arg(t_env *env, int ac, char **av);
int			ft_has_help(int ac, char **av);
int			ft_option(void);

int			ft_render(t_env *env);
int			ft_display(t_env *env);

int			ft_julia(t_env *env, int x, int y);
int			ft_mandelbrot(t_env *env, int x, int y);

int			ft_ints_to_int(int r, int g, int b);
int			ft_adjust_int(int color);
int			ft_red_to_black(int color);

int			ft_free_exit(t_params *p);
int			ft_is_double(const char *n);
int			ft_is_num(const char *n);
t_complex	ft_init_complex(double real, double imaginary);

#endif
