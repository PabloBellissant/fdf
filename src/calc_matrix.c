/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:30:43 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/06 02:30:46 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline void	calc_matrix(t_point *p, float m[9])
{
	int	x;
	int	y;
	int	z;

	x = p->x_view;
	y = p->y_view;
	z = p->z_view;
	p->x_view = (x * m[0]) + (y * m[1]) + (z * m[2]);
	p->y_view = (x * m[3]) + (y * m[4]) + (z * m[5]);
	p->z_view = (x * m[6]) + (y * m[7]) + (z * m[8]);
}
