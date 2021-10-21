/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:26:58 by adelille          #+#    #+#             */
/*   Updated: 2021/10/21 18:50:08 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_put_img_back(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img->addr, 0, 0);
	return (0);
}

int	ft_minimize(t_env *env)
{
	mlx_hook(env->win, 15, 1L << 16, ft_put_img_back, env);
	return (0);
}

int	ft_keypress(int keycode, t_env *env)
{
	if (keycode == 65307)
		ft_free_exit(env);
	return (0);
}

int	ft_display(t_env *env)
{
	//env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "fract-ol");
	mlx_put_image_to_window(env->mlx, env->win, env->img->addr, 0, 0);
	return (TRUE);
}
