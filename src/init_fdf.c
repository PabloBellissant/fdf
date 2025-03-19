/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:13:51 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/17 04:13:56 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	find_actual_map(char *map_name, char **map_list);

void	init_fdf(t_data *data, char *map_in)
{
	t_map	*map_data;

	map_data = &data->map_data;
	data->camera.pitch = to_rad(45);
	data->camera.yaw = to_rad(35.264);
	data->map_list.map_list = get_map_list();
	data->map_list.actual = find_actual_map(map_in, data->map_list.map_list);
	if (map_data->size_x <= 0)
		map_data->spacing = 1;
	else
	{
		map_data->spacing = data->screen.width / (map_data->size_x * 3);
		if (map_data->spacing < 1)
			map_data->spacing = 1;
	}
	init_key(data);
	init_param(data);
	set_button(data);
	set_camera_math(&data->camera);
	if (data->WIDTH <= 590)
		data->param.clipping = false;
}

static int	find_actual_map(char *map_name, char **map_list)
{
	size_t	i;

	if (map_name == NULL || map_list == NULL)
		return (-1);
	i = 0;
	while (map_list[i] != NULL)
	{
		if (ft_strcmp(map_name, map_list[i]) == 0)
			return (i);
		++i;
	}
	return (-1);
}
