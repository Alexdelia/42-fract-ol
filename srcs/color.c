/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:41:27 by adelille          #+#    #+#             */
/*   Updated: 2021/10/15 03:35:23 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

int	ft_ints_to_int(int r, int g, int b)
{
	int	color;

	color = r | g << 8 | b << 16;
	return (color);
}

int				ft_adjust_int(int color) // need to norm ternary operator
{
	int r;
	int g;
	int b;

	r = color & 0xFF;
	g = color >> 8 & 0xFF;
	b = color >> 16 & 0xFF;
	r = r < 0 ? 0 : r;
	r = r > 255 ? 255 : r;
	g = g < 0 ? 0 : g;
	g = g > 255 ? 255 : g;
	b = b < 0 ? 0 : b;
	b = b > 255 ? 255 : b;
	color = r | g << 8 | b << 16;
	return (color);
}
