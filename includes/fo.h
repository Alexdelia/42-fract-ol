/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:49:16 by adelille          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# include <math.h>

# define T_JULIA	1
# define T_MANDEL	2

typedef struct	s_arg
{
	int			type;
}				t_arg;

typedef struct	s_img
{
	void		*addr;
	char		*buffer;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	t_img		*img;
}				t_env;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	int			shadow;
}				t_color;

#endif
