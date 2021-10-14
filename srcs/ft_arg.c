/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:04:52 by adelille          #+#    #+#             */
/*   Updated: 2021/10/14 13:15:55 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

static int	ft_wrong_param(char *type)
{
	ft_pserc("Parssing Error:\t\"", RED);
	ft_pser(type);
	ft_pser("\" doesn't corespond to any options.\n");
	ft_pser("Here is a list of availible options:\n");
	ft_option();
	return (FALSE);
}

int	ft_arg(t_env *env, int ac, char **av)
{
	env->type = 0;
	if (ft_strcmp(av[1], "J") == 0 || ft_strcmp(av[1], "Julia") == 0)
		env->type == T_JULIA;
	else if (ft_strcmp(av[1], "M") == 0 || ft_strcmp(av[1], "Mandelbrot") == 0)
		env->type == T_MANDEL;
	else
		return (ft_wrong_param(av[1]));
	return (TRUE);
}
