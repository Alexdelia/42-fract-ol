/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:49:16 by adelille          #+#    #+#             */
/*   Updated: 2021/06/15 19:04:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# include <math.h>

# define T_JULIA	1
# define T_MANDEL	2

typedef struct	s_arg
{
	int			type;
}				t_arg;

#endif
