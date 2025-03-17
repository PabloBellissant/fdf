/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:58:49 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 04:58:50 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	auto_rotate(t_data *data)
{
	if (data->param.auto_rotate == true)
	{
		data->camera.pitch += (float)1 / 1000 * data->delta_time;
		data->camera.yaw -= (float)1 / 30000 * data->delta_time;
		normalize_camera(&data->camera);
		set_camera_math(&data->camera);
	}
}
