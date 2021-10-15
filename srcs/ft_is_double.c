/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:20:33 by adelille          #+#    #+#             */
/*   Updated: 2021/10/15 14:36:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fo.h"

int	ft_is_double(const char *n)
{
	unsigned long	i;
	int				p;

	i = 0;
	while (n[i] == '\t' || n[i] == '\n' || n[i] == '\v'
			|| n[i] == '\f' || n[i] == '\r' || n[i] == ' ')
		i++;
	if (n[i] == '+' || n[i] == '-')
		i++;
	p = FALSE;
	while (n[i])
	{
		if (!ft_isdigit(n[i]) && n[i] != '.' && n[i] != ',')
			return (FALSE);
		if ((n[i] == '.' || n[i] == ',') && p == TRUE)
			return (FALSE);
		if (n[i] == '.' || n[i] == ',')
			p = TRUE;
		i++;
	}
	return (TRUE);
}
