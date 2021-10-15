/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:04:52 by adelille          #+#    #+#             */
/*   Updated: 2021/10/15 20:26:23 by adelille         ###   ########.fr       */
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

int	ft_complex_arg(t_env *env, int ac, char **av)
{
	env->real = REAL;
	env->imaginary = IMAGINARY;
	env->ite = MAX_ITERATION;
	if (ac > 2 && ft_is_num(av[2]) == FALSE)
		return (ft_pserc("Error: Some arg that should be numbers are not\n",
				RED) * 0);
	if (ac > 2)
	{
		env->ite = ft_atol(av[2]);
		if (env->ite <= 0)
			env->ite = 1;
	}
	if (ac >= 5
		&& (ft_is_double(av[3]) == FALSE || ft_is_double(av[4]) == FALSE))
		return (ft_pserc("Error: Some arg that should be numbers are not\n",
				RED) * 0);
	if (ac >= 5)
	{
		env->real = ft_atof(av[3]);
		env->imaginary = ft_atof(av[4]);
	}
	return (TRUE);
}

int	ft_arg(t_env *env, int ac, char **av)
{
	if (ft_has_help(ac, av) == TRUE)
		return (ft_option());
	env->type = 0;
	if (ft_strcmp(av[1], "J") == 0 || ft_strcmp(av[1], "Julia") == 0)
		env->type = T_JULIA;
	else if (ft_strcmp(av[1], "M") == 0 || ft_strcmp(av[1], "Mandelbrot") == 0)
		env->type = T_MANDEL;
	else
		return (ft_wrong_param(av[1]));
	if (ft_complex_arg(env, ac, av) == FALSE)
		return (FALSE);
	return (TRUE);
}
