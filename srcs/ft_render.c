/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:19:02 by adelille          #+#    #+#             */
/*   Updated: 2021/10/19 20:19:58 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

void	ft_pixel(t_img *img, int color, int index)
{
	img->buffer[index] = color & 0xFF;
	img->buffer[index + 1] = color >> 8 & 0xFF;
	img->buffer[index + 2] = color >> 16 & 0xFF;
	img->buffer[index + 3] = 0;
}

void	ft_pixel_fix(t_img *img, int color, int index)
{
	img->buffer[index] = color >> 16 & 0xFF;
	img->buffer[index + 1] = color >> 8 & 0xFF;
	img->buffer[index + 2] = color & 0xFF;
	img->buffer[index + 3] = 0;
}

static void	ft_launch(t_env *env, int x, int y, int index)
{	
	if (env->type == T_JULIA)
		ft_pixel_fix(env->img, ft_julia(env, x, y), index);
	else if (env->type == T_MANDEL)
		ft_pixel_fix(env->img, ft_mandelbrot(env, x, y), index);
}

int	ft_process(t_env *env)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = 0;
	while (y < env->size_y)
	{
		env->c.ci = env->max.ci - y * env->factor.ci;
		x = 0;
		while (x < env->size_x)
		{
			env->c.cr = env->min.cr + x * env->factor.cr;
			ft_launch(env, x, y, index);
			index += 4;
			x++;
		}
		y++;
		printf("\rRender: [%d%%]", (y * 100) / env->size_y);
	}
	printf("\t\033[1;32mDone\033[0m\n");
	return (TRUE); //
}

int	ft_render(t_env *env)
{
	env->factor = ft_init_complex(
			(env->max.cr - env->min.cr) / (env->size_x - 1),
			(env->max.ci - env->min.ci) / (env->size_y - 1));
	ft_process(env);
	ft_display(env);
	return (TRUE); //
}
