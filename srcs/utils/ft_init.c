/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:09:52 by adelille          #+#    #+#             */
/*   Updated: 2021/10/19 20:11:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

t_complex	ft_init_complex(double real, double imaginary)
{
	t_complex	c;

	c.cr = real;
	c.ci = imaginary;
	return (c);
}
