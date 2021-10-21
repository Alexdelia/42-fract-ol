/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:09:06 by adelille          #+#    #+#             */
/*   Updated: 2021/10/21 12:43:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_env *env)
{
	t_complex	c;
	double		tmp;
	int			i;

	c.zr = env->c.cr;
	c.zi = env->c.ci;
	i = 0;
	while (c.zr * c.zr + c.zi * c.zi < 4 && i < env->ite)
	{
		tmp = c.zr * c.zr - c.zi * c.zi + env->c.cr;
		c.zi = 2 * c.zr * c.zi + env->c.ci;
		c.zr = tmp;
		i++;
	}
	return (ft_red_to_black(ft_ints_to_int(
				255 - 255 * ((env->ite - i) * (env->ite - i))
				% (env->ite * env->ite), 0, 0)));
}
