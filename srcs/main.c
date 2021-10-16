/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:48:21 by adelille          #+#    #+#             */
/*   Updated: 2021/10/16 22:19:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

int	ft_option(void)
{
	ft_pserc("\n  - format:\n", "\033[3;37m");
	ft_pserc("./fractol ", BWHI);
	ft_pserc("[TYPE] ", "\033[1;34m");
	ft_pserc("[MAX_ITERATION] ", RED);
	ft_pserc("[REAL] [IMAGINARY]\n", BMAG);
	ft_pserc("\n  - type:\n", "\033[3;34m");
	ft_pserc("./fractol Julia\n  = ./fractol J\n", "\033[1;34m");
	ft_pserc("./fractol Mandelbrot\n  = ./fractol M\n", "\033[1;34m");
	ft_pserc("\n  - example:\n", "\033[3;37m");
	ft_pserc("./fractol ", BWHI);
	ft_pserc("J ", "\033[1;34m");
	ft_pserc("250 ", RED);
	ft_pserc("-0.7 0.27015\n\n", BMAG);
	// might add RGB feature, size, etc ...
	return (FALSE);
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
	env->size_x = SIZE_X; // need to check if bigger than screen
	env->size_y = SIZE_Y; //might had possiblity to change from arg
	if (env->type == T_MANDEL)
	{
		env->size_x = 1000;
		env->size_y = 1000;
	}
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
	ft_display(&env);
	mlx_loop(env.mlx);
	return (0);
}
