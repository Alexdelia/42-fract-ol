/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:58:20 by adelille          #+#    #+#             */
/*   Updated: 2021/10/14 13:05:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

int	ft_free_exit(t_params *p)
{
	mlx_destroy_image(p->env->mlx, p->env->img.addr);
	mlx_destroy_window(p->env->mlx, p->env->win);
	mlx_destroy_display(p->env->mlx);
	//free(p->env->img);
	free(p->env->mlx);
	free(p);
	exit (0);
	return (1);
}
