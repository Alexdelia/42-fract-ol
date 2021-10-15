/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:09:06 by adelille          #+#    #+#             */
/*   Updated: 2021/10/15 22:41:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

#define	MIN_R	-1.5
#define	MAX_R	0.7
#define	MIN_I	-1.0
#define MAX_I	1.0

int	ft_mandelbrot(t_env *env, int x, int y)
{
	t_complex	c;
	double		tmp;
	int			i;

	c.r0 = x * (MAX_R - MIN_R / SIZE_X) + MIN_R;
	c.i0 = y * (MAX_I - MIN_I / SIZE_Y) + MIN_I;
	c.r1 = 0;
	c.i1 = 0;
	i = 0;
	while (c.r1 * c.r1 + c.i1 * c.i1 < 4 && i < env->ite)
	{
		tmp = c.r1 * c.r1 - c.i1 * c.i1 + c.r0;
		c.i1 = 2 * c.r1 * c.i1 + c.i0;
		c.r1 = tmp;
		i++;
	}
	return (ft_ints_to_int(i % 256, i % 256, i % 256));
}
