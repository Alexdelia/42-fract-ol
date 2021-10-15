/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:09:06 by adelille          #+#    #+#             */
/*   Updated: 2021/10/15 21:16:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

int	ft_mandelbrot(t_env *env, int x, int y)
{
	t_complex	c;
	double		tmp;
	int			i;

	c.r0 = x;
	c.i0 = y;
	c.r1 = 0;
	c.i1 = 0;
	i = 0;
	while (c.r1 * c.r1 + c.i1 * c.i1 < 4 && i < env->ite)
	{
		tmp = c.r1 * c.r1 - c.i1 * c.i1 + c.r0;
		c.i1 = 2 * c.r1 * c.r1 + c.i0;
		c.r1 = tmp;
		i++;
	}
	return (ft_ints_to_int(255 - 255 * ((env->ite - i) * (env->ite - i)) % (env->ite * env->ite), 0, 0));
}
