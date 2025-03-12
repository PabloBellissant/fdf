/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:09:03 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/06 03:09:05 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	rotation_matrix(t_point *point, const t_camera camera)
{
	float	matrix_a[3][3] = {{camera.cospitch, 0, -camera.sinpitch},
		{0, 1, 0},
		{camera.sinpitch, 0, camera.cospitch}};
	float	matrix_b[3][3] = {{1, 0, 0},
		{0, camera.cosyaw, camera.sinyaw},
		{0, -camera.sinyaw, camera.cosyaw}};
	calc_matrix(point, matrix_a);
	calc_matrix(point, matrix_b);
}
