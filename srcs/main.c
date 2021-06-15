/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:48:21 by adelille          #+#    #+#             */
/*   Updated: 2021/06/15 19:11:55 by adelille         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_arg	arg;

	if (ac == 1)
		return (ft_no_param());
	if (ft_arg(&arg, ac, av) != TRUE);
		return (2);
	return (0);
}
