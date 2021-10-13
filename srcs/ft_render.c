/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:19:02 by adelille          #+#    #+#             */
/*   Updated: 2021/10/13 12:27:39 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

int	ft_color_to_int(t_color color)
{
	int	cint;

	cint = 0;
	cint = (int)color.r | (int)color.g << 8 | (int)color.b << 16;
	return (cint);
}

void	ft_pixel(t_img *img, int color, int index)
{
	img->buffer[index] = color & 0xFF;
	img->buffer[index + 1] = color >> 8 & 0xFF;
	img->buffer[index + 2] = color >> 16 & 0xFF;
	img->buffer[index + 3] = 0;
}
