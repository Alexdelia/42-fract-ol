/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:19:02 by adelille          #+#    #+#             */
/*   Updated: 2021/10/15 03:39:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

int	ft_color_to_int(t_color color)
{
	int	cint;

	cint = 0;
	cint = (int)color.r | (int)color.g << 8 | (int)color.b << 16;
	return (cint);
}

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

int	ft_render(t_env *env)
{
	int	x;
	int	y;
	int	index;

	env->img->addr = mlx_new_image(env->mlx, env->size_x, env->size_y);
	env->img->buffer = mlx_get_data_addr(env->img->addr, &env->img->bpp,
			&env->img->line_size, &env->img->endian);
	index = 0;
	y = 0;
	while (y < env->size_y)
	{
		x = 0;
		while (x < env->size_x)
		{
			// if julia, launch julia
			if (env->type == T_JULIA)
				ft_pixel_fix(env->img, ft_julia(env, x, y), index);
			index += 4;
			x++;
		}
		y++;
		printf("\rRender: [%d%%]", (y * 100) / env->size_y);
	}
	printf("		\033[1;32mDone\033[0m\033[1m\n");
	return (TRUE); //
}
