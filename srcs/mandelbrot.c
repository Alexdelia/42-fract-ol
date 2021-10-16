/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:09:06 by adelille          #+#    #+#             */
/*   Updated: 2021/10/16 22:21:21 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

#define	MIN_R	-2
#define	MAX_R	2
#define	MIN_I	-2
#define MAX_I	2

int	ft_mandelbrot(t_env *env, int x, int y)
{
	t_complex	c;
	double		tmp;
	int			i;

	c.cr = (double)(x * 4) / env->size_x - 2;
	c.ci = (double)(y * 4) / env->size_y - 2;
	c.zr = c.cr;
	c.zi = c.ci;
	i = 0;
	while (c.zr * c.zr + c.zi * c.zi < 4 && i < env->ite)
	{
		tmp = c.zr * c.zr - c.zi * c.zi + c.cr;
		c.zi = 2 * c.zr * c.zi + c.ci;
		c.zr = tmp;
		i++;
	}
	return (ft_red_to_black(ft_ints_to_int(255 - 255 * ((env->ite - i) * (env->ite - i)) % (env->ite * env->ite), 0, 0)));
	//return (ft_ints_to_int(i % 256, i % 256, i % 256));
}
