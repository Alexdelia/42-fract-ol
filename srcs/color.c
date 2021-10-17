/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:41:27 by adelille          #+#    #+#             */
/*   Updated: 2021/10/17 21:22:55 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

int	ft_ints_to_int(int r, int g, int b)
{
	int	color;

	color = r | g << 8 | b << 16;
	return (color);
}

int	ft_red_to_black(int color)
{
	int	r;
	int	g;
	int	b;

	r = color & 0xFF;
	g = color >> 8 & 0xFF;
	b = color >> 16 & 0xFF;
	if (r == 255 && g == 0 && b == 0)
		return (0);
	return (color);
}
