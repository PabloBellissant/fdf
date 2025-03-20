/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_height.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 07:04:03 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/19 07:04:09 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "fdf.h"

void	change_height(t_data *data)
{
	if (data->param.have_points_select == true)
	{
		change_height_selected(data);
		return ;
	}
	if (key_is_pressed(XK_Up, *data))
		data->map_data.z_multiple *= 1.1;
	else
		data->map_data.z_multiple *= 0.9;
	if (data->map_data.z_multiple > 10000.0)
		data->map_data.z_multiple = 10000.0;
}
