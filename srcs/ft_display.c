/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:26:58 by adelille          #+#    #+#             */
/*   Updated: 2021/10/14 12:51:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

static int		ft_minimize(t_params *params)
{
	mlx_hook(params->env->win, 15, 1L << 16, ft_put_img_back, params);
	return (0);
}

int	ft_display(t_env *env)
{
	// will need to re-render if wheel is moved
	// mlx_hook for zoom / un-zoom + wasd (+ zoom on mouse)

	env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "fract-ol");
	mlx_put_image_to_window(env->mlx, env->win, env->img.addr, 0, 0);
	//mlx_hook(env->win, x, 1L << x, ft_function, struct);
	
	mlx_hook(env->win, 33, 1L << 5, ft_free_exit, params);
	//mlx_hook(env->win, 2, 1L << 0, ft_img_to_window, params);
	mlx_hook(env->win, 15, 1L << 16, ft_minimize, params);
	return (0);
}
