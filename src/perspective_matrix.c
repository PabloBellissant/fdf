/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:47:02 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/15 04:47:05 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

typedef float Matrix44f[4][4];

void setProjectionMatrix(const float angleOfView, const float near, const float far, Matrix44f M)
{
	float scale = 1 / tan(angleOfView * 0.5 * M_PI / 180);
	M[0][0] = scale;
	M[1][1] = scale;
	M[2][2] = -far / (far - near);
	M[3][2] = -far * near / (far - near);
	M[2][3] = -1;
	M[3][3] = 0;
}

void perspective_matrix(t_point *p, const t_camera camera)
{
	int x = p->x;
	int y = p->y;
	int z = p->z;

	Matrix44f projectionMatrix;
	setProjectionMatrix(camera.fov, camera.near, camera.far, projectionMatrix);

	// Projection en perspective
	float projection_x = (x * projectionMatrix[0][0]) + (y * projectionMatrix[0][1]);
	float projection_y = (x * projectionMatrix[1][0]) + (y * projectionMatrix[1][1]);
	float projection_z = (z * projectionMatrix[2][2]) + (y * projectionMatrix[2][3]);

	p->x_view = projection_x / (z + camera.distance);
	p->y_view = projection_y / (z + camera.distance);
	p->z_view = projection_z;

	// Application des rotations de la caméra
	float temp_x = p->x_view;
	p->x_view = (temp_x * camera.cospitch) + (p->y_view * -camera.sinpitch);
	p->y_view = (temp_x * camera.sinpitch) + (p->y_view * camera.cospitch);
	p->z_view = (p->z_view * camera.cosyaw) + (p->y_view * camera.sinyaw);
}
