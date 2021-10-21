/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:09:52 by adelille          #+#    #+#             */
/*   Updated: 2021/10/21 18:50:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_init_complex(double real, double imaginary)
{
	t_complex	c;

	c.r = real;
	c.i = imaginary;
	return (c);
}

void	ft_init_env(t_env *env)
{
	env->img = malloc(sizeof(t_img));
	if (!env->img)
		exit(1);
	env->mlx = mlx_init();
	env->img->addr = mlx_new_image(env->mlx, env->size_x, env->size_y);
	env->img->buffer = mlx_get_data_addr(env->img->addr, &env->img->bpp,
			&env->img->line_size, &env->img->endian);
	env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "fract-ol");
	//mlx_hook(env->win, x, 1L << x, ft_function, struct);	
	mlx_hook(env->win, 2, 1L << 0, ft_keypress, env);
	mlx_hook(env->win, 4, 0, ft_zoom, env);
	mlx_hook(env->win, 15, 1L << 16, ft_minimize, env);
	mlx_hook(env->win, 33, 1L << 5, ft_free_exit, env);
}
