/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:26:58 by adelille          #+#    #+#             */
/*   Updated: 2021/06/15 20:30:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

int	ft_display(t_env *env)
{
	// will need to re-render if wheel is moved

	env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "fract-ol");
	//mlx_put_image_to_window(env->mlx, env->win, env->img.addr, 0, 0);
	//mlx_hook(env->win, x, 1L << x, ft_function, struct);
}
