/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:53:06 by adelille          #+#    #+#             */
/*   Updated: 2021/10/18 18:06:15 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

static double	ft_interpolate(double min, double max, double inter)
{
	return (min + ((max - min) * inter));
}

int	zoom(t_env *env, int keypress, int x, int y)
{
	t_complex	mouse;
	double		zoom;
	double		inter;

	if (keypress == M_SCROLL_UP || keypress == M_SCROLL_DOWN)
	{
		mouse.cr = (double)x / (env->size_x / (/*max*/.cr - /*min*/.cr)) + /*min*/.ci;
		mouse.ci = (double)y / (env->size_y / (/*max*/.ci - /*min*/.ci)) * -1 + /*min*/.ci;
		if (keypress == M_SCROLL_UP)
			zoom == 0.80;
		else
			zoom == 1.20;
		inter = 1.0 / zoom;
		/*min*/.cr = ft_interpolate(mouse.cr, /*min*/.cr, inter);
		/*min*/.ci = ft_interpolate(mouse.ci, /*min*/.ci, inter);
		/*max*/.cr = ft_interpolate(mouse.cr, /*max*/.cr, inter);
		/*max*/.ci = ft_interpolate(mouse.ci, /*max*/.ci, inter);
		//render/draw
	}
	return (0);
}
