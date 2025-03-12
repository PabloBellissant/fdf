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

void	calc_matrix(t_point *p, float m[3][3])
{
	int	x;
	int	y;
	int	z;

	x = (p->x_view * m[0][0]) + (p->y_view * m[0][1]) + (p->z_view * m[0][2]);
	y = (p->x_view * m[1][0]) + (p->y_view * m[1][1]) + (p->z_view * m[1][2]);
	z = (p->x_view * m[2][0]) + (p->y_view * m[2][1]) + (p->z_view * m[2][2]);
	p->x_view = x;
	p->y_view = y;
	p->z_view = z;
}
