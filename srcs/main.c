/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:48:21 by adelille          #+#    #+#             */
/*   Updated: 2021/10/21 18:54:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_default(t_env *env)
{
	env->size_x = SIZE_X; // need to check if bigger than screen
	env->size_y = SIZE_Y; //might had possiblity to change from arg
	/*if (env->type == T_JULIA)
	{
		env->size_x = 1024;
		env->size_y = 768;
	}*/
	env->ite = MAX_ITERATION;
	env->min = ft_init_complex(MIN_R, MIN_I);
	env->max = ft_init_complex(MAX_R,
			MIN_I + (MAX_R - MIN_R)* env->size_x / env->size_y);
	env->k = ft_init_complex(-0.4, 0.6);
	//env->color_shift = 0;
}

int	main(int ac, char **av)
{
	t_env		env;

	if (ac == 1)
		return (ft_no_param());
	if (ft_arg(&env, ac, av) == FALSE)
		return (2);
	ft_init_env(&env);
	//while (escape / x not press)
	//mlx_hook for zoom / un-zoom + wasd (+ zoom on mouse)
	ft_render(&env);
	mlx_loop(env.mlx);
	return (0);
}
