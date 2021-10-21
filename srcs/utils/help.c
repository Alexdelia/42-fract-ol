/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:46:30 by adelille          #+#    #+#             */
/*   Updated: 2021/10/21 20:30:18 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_no_param(void)
{
	ft_pser("- No parameter entered\nHere is the list of availible option:\n");
	ft_option();
	return (1);
}

void	ft_input(void)
{
	ft_pserc("  - input:\n", "\033[3;37m");
	ft_pserc("scroll up/down:\t\tzoom in/out  ", GRN);
	ft_pserc("(will follow mouse)\n", "\033[1;3;32m");
	ft_pserc("M/N:\t\tzoom in/out  ", GRN);
	ft_pserc("WASD/ZQSD/Arrow key:\tmove up/left/down/right\n", BMAG);
}

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
	ft_input();
	return (FALSE);
}

int	ft_has_help(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-h") == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
