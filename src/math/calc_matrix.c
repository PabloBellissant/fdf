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

inline void	calc_matrix(t_point *p, float m[16])
{
	float	x;
	float	y;
	float	z;
	float	w;

	x = p->x_view;
	y = p->y_view;
	z = p->z_view;
	w = p->w;
	p->x_view = (x * m[0]) + (y * m[1]) + (z * m[2]) + (w * m[3]);
	p->y_view = (x * m[4]) + (y * m[5]) + (z * m[6]) + (w * m[7]);
	p->z_view = (x * m[8]) + (y * m[9]) + (z * m[10]) + (w * m[11]);
	p->w = (x * m[12]) + (y * m[13]) + (z * m[14]) + (w * m[15]);
}
