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
	normalize_float_value(&camera->pitch, M_PI * 2);
	normalize_float_value(&camera->yaw, M_PI * 2);
}
