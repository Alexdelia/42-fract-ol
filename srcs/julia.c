/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:37:46 by adelille          #+#    #+#             */
/*   Updated: 2021/10/15 03:53:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

int	ft_red_to_black(int color)
{
	int r;
	int g;
	int b;

	r = color & 0xFF;
	g = color >> 8 & 0xFF;
	b = color >> 16 & 0xFF;
	if (r == 255 && g == 0 && b == 0)
		return (0);
	return (color);
}

int	ft_julia(t_env *env, int x, int y)
{
	t_complex	c;
	int			i;

	// tmp
	double	zoom = 1, move_x = 0, move_y = 0; // will be get from input

	// tmp
	int	res;

	c.r0 = 1.5 * (x - env->size_x / 2) / (0.5 * zoom * env->size_x) + move_x;
	c.i0 = (y - env->size_y / 2) / (0.5 * zoom * env->size_y) + move_y;
	i = 0;
	while (i < env->ite)
	{
		c.r1 = c.r0;
		c.i1 = c.i0;
		c.r0 = c.r1 * c.r1 - c.i1 * c.i1 + env->real;
		c.i0 = 2 * c.r1 * c.i1 + env->imaginary;
		if ((c.r0 * c.r0 + c.i0 * c.i0) > 4)
			break ;
		i++;
	}
	res = ft_ints_to_int(255 - 255 * ((env->ite - i) * (env->ite - i)) % (env->ite * env->ite), 0, 0);
	return (ft_red_to_black(res));
	//return (ft_ints_to_int(255 - 255 * ((env->ite - i) * (env->ite - i)) % (env->ite * env->ite), 0, 0));
	//return (ft_ints_to_int(i % 256, 255, 255 * (i < env->ite)));
}
