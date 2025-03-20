/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:12:44 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/14 01:12:45 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <mlx.h>
#include "fdf.h"

int	check_input(t_data *data)
{
	t_map	*map_data;

	map_data = &data->map_data;
	mlx_mouse_get_pos(data->mlx, data->win, &data->mouse.x, &data->mouse.y);
	if (key_is_pressed(XK_Up, *data) || key_is_pressed(XK_Down, *data))
		change_height(data);
	if (key_is_pressed(XK_Escape, *data))
		mlx_loop_end(data->mlx);
	if (key_is_pressed(XK_Right, *data) || key_is_pressed(XK_Left, *data))
	{
		if (change_map(data) == -1)
			return (-1);
		if (map_data->size_x <= 0)
			map_data->spacing = 1;
		else
		{
			map_data->spacing = data->screen.w / (map_data->size_x * 3);
			if (map_data->spacing < 1)
				map_data->spacing = 1;
		}
	}
	simple_clic(data);
	data->mouse.old_x = data->mouse.x;
	data->mouse.old_y = data->mouse.y;
	return (0);
}
