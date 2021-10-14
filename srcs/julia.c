/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:37:46 by adelille          #+#    #+#             */
/*   Updated: 2021/10/14 14:19:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

#define	C_R		-0.7
#define	C_IM	0.27015

#define	MAX_ITERATION	100

int	ft_julia(t_env *env, int x, int y)
{
	int		i;
	double	newR; // will be struct
	double	newIm;
	double	oldR;
	double	oldIm;

	// tmp
	double	zoom = 1, move_x = 0, move_y = 0; // will be get from input

	newR = 1.5 * (x - env->size_x / 2) / (0.5 * zoom * env->size_x) + move_x;
	newIm = (y - env->size_y / 2) / (0.5 * zoom * env->size_y) + move_y;
	i = 0;
	while (i < MAX_ITERATION)
	{
		oldR = newR;
		oldIm = newIm;
		newR = oldR * oldR - oldIm * oldIm + C_R;
		newIm = 2 * oldR * oldIm + C_IM;
		if ((newR * newR + newIm * newIm) > 4)
			break ;
		i++;
	}
	//return (ft_ints_to_int(255 - 255 * ((MAX_ITERATION - i) * (MAX_ITERATION - i)) % (MAX_ITERATION * MAX_ITERATION), 0, 0));
	//return (ft_ints_to_int(i % 256, 255, 255 * (i < MAX_ITERATION)));
}
