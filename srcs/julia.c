/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:37:46 by adelille          #+#    #+#             */
/*   Updated: 2021/10/20 20:17:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_env *env, int x, int y)
{
	t_complex	c;
	int			i;

	// tmp
	double	zoom = 0.75, move_x = 0, move_y = 0; // will be get from input

	c.cr = 1.5 * (x - env->size_x / 2) / (0.5 * zoom * env->size_x) + move_x;
	c.ci = (y - env->size_y / 2) / (0.5 * zoom * env->size_y) + move_y;
	i = 0;
	while (i < env->ite)
	{
		c.zr = c.cr;
		c.zi = c.ci;
		c.cr = c.zr * c.zr - c.zi * c.zi + env->real;
		c.ci = 2 * c.zr * c.zi + env->imaginary;
		if ((c.cr * c.cr + c.ci * c.ci) > 4)
			break ;
		i++;
	}
	return (ft_red_to_black(ft_ints_to_int(
				255 - 255 * ((env->ite - i) * (env->ite - i))
				% (env->ite * env->ite), 0, 0)));
	//return (ft_ints_to_int(i % 256, 255, 255 * (i < env->ite)));
}
