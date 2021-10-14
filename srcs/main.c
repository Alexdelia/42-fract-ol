/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:48:21 by adelille          #+#    #+#             */
/*   Updated: 2021/10/14 13:26:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

void	ft_option(void)
{
	ft_pserc("./fractol Julia\n\t= ./fractol J\n", "\033[1;34m");
	ft_pserc("./fractol Mandelbrot\n\t= ./fractol M\n", "\033[1;34m");
	// might add RGB feature, size, etc ...
}

static int	ft_no_param(void)
{
	ft_pser("- No parameter entered\nHere is the list of availible option:\n");
	ft_option();
	return (1);
}

static void	ft_init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->size_x = 300;
	env->size_y = 300;
}

int	main(int ac, char **av)
{
	// might create a struct that hold them both
	t_env		env;

	if (ac == 1)
		return (ft_no_param());
	if (ft_arg(&env, ac, av) == FALSE)
		return (2);
	ft_init_env(&env);
	//while (escape / x not press)
	//mlx_hook for zoom / un-zoom + wasd (+ zoom on mouse)
	ft_render(&env);
	ft_display(&env);
	mlx_loop(env.mlx);
	return (0);
}
