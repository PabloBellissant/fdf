/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 07:08:06 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/19 07:08:07 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

int	change_map(t_data *data)
{
	int	fd;
	int	old;

	old = data->map_list.actual;
	if (old == -1)
		return (1);
	if (key_is_pressed(XK_Right, *data))
		++data->map_list.actual;
	else
		--data->map_list.actual;
	normalize_value(&data->map_list.actual, 0, MAPS_AMOUNT);
	fd = open(data->map_list.map_list[data->map_list.actual], O_RDONLY);
	if (fd == -1)
	{
		data->map_list.actual = old;
		return (-1);
	}
	free_map(&data->map);
	open_map(data, fd);
	if (close(fd) == -1)
		return (-1);
	change_param_lag_comp(data);
	data->input.right = false;
	data->input.left = false;
	return (0);
}
