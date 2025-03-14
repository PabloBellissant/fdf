/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_wheel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:30:03 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/06 01:30:05 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mouse_wheel(const int button, t_data *data)
{
	if (button == 4)
	{
		if (data->map_data.spacing < data->WIDTH)
		{
			data->map_data.spacing *= 1.10;
			data->map_data.x = -data->map_data.spacing;
			data->map_data.y = -data->map_data.spacing;
		}
	}
	else
	{
		if (data->map_data.spacing > 1)
		{
			data->map_data.spacing /= 1.10;
			data->map_data.x = -data->map_data.spacing;
			data->map_data.y = -data->map_data.spacing;
		}
	}
}
