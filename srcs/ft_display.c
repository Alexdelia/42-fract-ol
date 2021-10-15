/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:26:58 by adelille          #+#    #+#             */
/*   Updated: 2021/10/15 13:35:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

static int	ft_put_img_back(t_params *p)
{
	mlx_put_image_to_window(p->env->mlx, p->env->win, p->env->img->addr, 0, 0);
	return (0);
}

static int	ft_minimize(t_params *params)
{
	mlx_hook(params->env->win, 15, 1L << 16, ft_put_img_back, params);
	return (0);
}

static int	ft_keypress(int keycode, t_params *p)
{
	if (keycode == 65307)
		ft_free_exit(p);
	return (0);
}

int	ft_display(t_env *env)
{
	t_params	*p;

	// will need to re-render if wheel is moved
	// mlx_hook for zoom / un-zoom + wasd (+ zoom on mouse)

	env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "fract-ol");
	mlx_put_image_to_window(env->mlx, env->win, env->img->addr, 0, 0);
	p = malloc(sizeof(t_params));
	if (!p)
		return (FALSE);
	p->env = env;
	//mlx_hook(env->win, x, 1L << x, ft_function, struct);	
	mlx_hook(env->win, 33, 1L << 5, ft_free_exit, p);
	mlx_hook(env->win, 2, 1L << 0, ft_keypress, p);
	mlx_hook(env->win, 15, 1L << 16, ft_minimize, p);
	free(p);
	return (TRUE);
}
