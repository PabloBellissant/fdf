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
	size_t		x;
	t_vector	*line;

	data->info.fps = get_fps();
	++data->info.frames_generated;
	if (check_input(data) == -1)
		mlx_loop_end(data->mlx);
	clear_window(data);
	data->map_data.x = -((data->map_data.size_x >> 1) * data->map_data.spacing);
	data->map_data.y = -((data->map_data.size_y >> 1) * data->map_data.spacing);
	x = 0;
	while (x < data->map.num_elements)
	{
		line = get_vector_value(&data->map, x);
		calc_view(line, data);
		++x;
	}
	draw_map(data);
	auto_rotate(data);
	data->delta_time = get_delta_time();
	if (data->param.limit_fps == true)
		ft_sleep(23 - data->delta_time);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw_gui(data);
	return (0);
}
