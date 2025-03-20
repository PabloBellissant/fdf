/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_clic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 07:09:51 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/19 07:09:53 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	simple_clic(t_data *data)
{
	if (mouse_is_pressed(3, *data))
	{
		data->camera.pitch -= (float)(data->mouse.x - data->mouse.old_x) / 300;
		data->camera.yaw += (float)(data->mouse.y - data->mouse.old_y) / 300;
		normalize_camera(&data->camera);
		set_camera_math(&data->camera);
	}
	if (mouse_is_pressed(2, *data))
	{
		data->camera.x += (data->mouse.x - data->mouse.old_x) * 1.6;
		data->camera.y += (data->mouse.y - data->mouse.old_y) * 1.6;
	}
	if (mouse_is_pressed(1, *data))
		select_zone(data);
}
