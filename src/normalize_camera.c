/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:05:17 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 00:05:19 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	normalize_camera(t_camera *camera)
{
	if (camera->pitch < 0)
		camera->pitch += to_rad(360);
	camera->pitch = fmod(camera->pitch, to_rad(360));
	// if (camera->yaw > to_rad(90))
	// 	camera->yaw = to_rad(90);
	// else if (camera->yaw < to_rad(-90))
	// 	camera->yaw = to_rad(-90);
}
