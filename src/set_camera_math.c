/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:05:06 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 05:05:08 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	set_camera_math(t_camera *camera)
{
	camera->cospitch = cos(camera->pitch);
	camera->sinpitch = sin(camera->pitch);
	camera->cosyaw = cos(camera->yaw);
	camera->sinyaw = sin(camera->yaw);
}
