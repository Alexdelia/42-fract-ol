/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:49:16 by adelille          #+#    #+#             */
/*   Updated: 2021/10/14 13:30:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# include <math.h>
# include <stdio.h>

# define T_JULIA	1
# define T_MANDEL	2

typedef struct	s_img
{
	void		*addr;
	char		*buffer;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	int			type;
	t_img		*img;
}				t_env;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	int			shadow;
}				t_color;

typedef struct	s_params
{
	t_env		*env;
}				t_params;

int		ft_arg(t_env *env, int ac, char **av);
void	ft_option(void);

int		ft_render(t_env *env);
int		ft_display(t_env *env);

int		ft_julia(t_env *env, int x, int y);

#endif
