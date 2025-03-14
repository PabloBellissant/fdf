/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:09:19 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 23:09:20 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int	loop(t_data *data)
{
	data->info.fps = get_fps();
	++data->info.frames_generated;
	check_input(data);
	clear_window(data);
	data->map_data.x = -((data->map_data.size_x >> 1) * data->map_data.spacing);
	data->map_data.y = -((data->map_data.size_y >> 1) * data->map_data.spacing);
	size_t	i = 0;
	while (i < data->map.num_elements)
	{
		t_vector *line = get_vector_value(&data->map, i);
		calc_view(line, data);
		++i;
	}

	t_point	*point;
	t_point	*temp;
	int	x;
	int	y;
	y = 0;
	t_vector	*line;
	while ((size_t) y < data->map.num_elements)
	{
		line = get_vector_value(&data->map, y);
		x = 0;
		while ((size_t) x < line->num_elements)
		{
			point = get_point(data, x, y);
			if (point && (size_t) x < line->num_elements - 1)
			{
				temp = get_point(data, x + 1, y);
				if (temp && ((data->param.draw_diff_level_line == true && point->z != temp->z) || (data->param.draw_same_level_line == true && point->z == temp->z)))
					draw_line(data, *point, *temp);
			}
			if (point && (size_t) y < data->map.num_elements - 1)
			{
				temp = get_point(data, x, y + 1);
				if (temp && ((data->param.draw_diff_level_line == true && point->z != temp->z) || (data->param.draw_same_level_line == true && point->z == temp->z)))
					draw_line(data, *point, *temp);
			}
			++x;
		}
		++y;
	}
	auto_rotate(data);
	data->delta_time = get_delta_time();
	if (data->param.limit_fps == true)
		ft_sleep(23 - data->delta_time);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw_gui(data);
	return (0);
}
