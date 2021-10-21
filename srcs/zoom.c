/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:53:06 by adelille          #+#    #+#             */
/*   Updated: 2021/10/21 20:07:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_interpolate(double min, double max, double inter)
{
	return (min + ((max - min) * inter));
}

int	ft_zoom(int button, int x, int y, t_env *env)
{
	t_complex	mouse;
	double		zoom;
	double		inter;

	if (button == M_SCROLL_UP || button == M_SCROLL_DOWN)
	{
		mouse.r = (double)x / (env->size_x / (env->max.r - env->min.r))
			+ env->min.r;
		mouse.i = (double)y / (env->size_y / (env->max.i - env->min.i))
			* -1 + env->max.i;
		if (button == M_SCROLL_UP)
			zoom = 0.80;
		else
			zoom = 1.20;
		inter = 1.0 / zoom;
		env->min.r = ft_interpolate(mouse.r, env->min.r, inter);
		env->min.i = ft_interpolate(mouse.i, env->min.i, inter);
		env->max.r = ft_interpolate(mouse.r, env->max.r, inter);
		env->max.i = ft_interpolate(mouse.i, env->max.i, inter);
		ft_render(env);
	}
	else
		printf("Unkown mouse input, keycode = %d\n", button);
	return (0);
}
