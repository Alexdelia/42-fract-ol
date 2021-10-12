/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:37:46 by adelille          #+#    #+#             */
/*   Updated: 2021/10/12 15:53:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

#define	C_R	-0.7
#define	C_IM	0.27015

#define	MAX_ITERATION	1000

int	ft_julia(t_env *env)
{
	int	i;
	int	x;
	int	y;

	// tmp // might be struct
	double	R; // C_R
	double	Im; // C_IM
	double	newR;
	double	newIm;
	double	oldR;
	double	oldIm;

	// tmp
	double	zoom = 1, move_x = 0, move_y = 0; // will be get from input
	// can be dispansable
	t_color	color; // RGBA

	y = 0;
	while (y < env->size_y)
	{
		x = 0;
		while (x < env->size_x)
		{
			newR = 1.5 * (x - env->size_x / 2) / (0.5 * zoom * env->size_x) + move_x;
			newIm = (y - env->size_y / 2) / (0.5 * zoom * env->size_y) + move_y;
			i = 0;
			while (i < MAX_ITERATION)
			{
				oldR = newR;
				oldIm = newIm;
				newR = oldR * oldR - oldIm * oldIm + C_R;
				newIm = 2 * oldR * oldIm + C_I;
				if ((newR * newR + newIm * newIm) > 4)
					break ;
				i++;
			}
			// if used, will be set an other way
			color = i % 256, 255, 255 * (i < MAX_ITERATION), A; // RGBA
			// set pixel as color
			ft_xxx(x, y, color);
			x++;
		}
		y++;
	}
}