/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:48:21 by adelille          #+#    #+#             */
/*   Updated: 2021/10/15 04:26:49 by adelille         ###   ########.fr       */
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
	env->img = malloc(sizeof(t_img));
	if (!env->img)
		exit(1);
	env->mlx = mlx_init();
	env->size_x = 1024;
	env->size_y = 768;
	//env->ite = 250;
	//env->real = -0.7;
	//env->imaginary = 0.27015;
	/*env->real = 0;
	env->imaginary = -0.8;
	env->ite = 15;*/
	/*env->real = -0.835;
	env->imaginary = 0.2321;
	env->ite = 10000000;*/
	/*env->real = -1;
	env->imaginary = -1.618033988749;
	env->ite = 1000000000;*/
	/*env->real = 0;
	env->imaginary = -1;
	env->ite = 250;*/
	/*env->real = -0.83;
	env->imaginary = 0;
	env->ite = 250;*/
	env->real = 0.4;
	env->imaginary = -0.8;
	env->ite = 16;
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
