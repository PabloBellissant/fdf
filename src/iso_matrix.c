/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:09:03 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/06 03:09:05 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_matrix(t_point *p, const t_camera camera)
{
	int	x;
	int	y;
	int	z;

	x = p->x_view;
	z = p->z_view;
	p->x_view = (x * camera.cospitch) + (z * -camera.sinpitch);
	p->z_view = (x * camera.sinpitch) + (z * camera.cospitch);
	y = p->y_view;
	z = p->z_view;
	p->y_view = (y * camera.cosyaw) + (z * camera.sinyaw);
	p->z_view = (y * -camera.sinyaw) + (z * camera.cosyaw);
}
