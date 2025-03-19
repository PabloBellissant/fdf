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
#include <fcntl.h>
#include <mlx.h>
#include <unistd.h>
#include <limits.h>
#include "fdf.h"

static void	simple_clic(t_data *data);
static int	change_map(t_data *data);
static void	remove_line_lag_comp(t_data *data);
static void	change_height(t_data *data);
static void	select_zone(t_data *data);
static void	change_all_points(t_data *data);

int	check_input(t_data *data)
{
	mlx_mouse_get_pos(data->mlx, data->win, &data->mouse.x, &data->mouse.y);
	if (key_is_pressed(XK_Up, *data) || key_is_pressed(XK_Down, *data))
		change_height(data);
	if (key_is_pressed(XK_Escape, *data))
		mlx_loop_end(data->mlx);
	if (key_is_pressed(XK_Right, *data) || key_is_pressed(XK_Left, *data))
	{
		if (change_map(data) == -1)
			return (-1);
		if (data->map_data.size_x <= 0)
			data->map_data.spacing = 1;
		else
		{
			data->map_data.spacing = data->WIDTH / (data->map_data.size_x * 3);
			if (data->map_data.spacing < 1)
				data->map_data.spacing = 1;
		}
	}
	simple_clic(data);
	data->mouse.old_x = data->mouse.x;
	data->mouse.old_y = data->mouse.y;
	return (0);
}

static void	change_height(t_data *data)
{
	if (data->param.have_points_select == true)
	{
		change_all_points(data);
		return ;
	}
	if (key_is_pressed(XK_Up, *data))
		data->map_data.z_multiple *= 1.1;
	else
		data->map_data.z_multiple *= 0.9;
	if (data->map_data.z_multiple > 10000.0)
		data->map_data.z_multiple = 10000.0;
}

static void	change_all_points(t_data *data)
{
	size_t		x;
	size_t		y;
	t_vector	*line;
	t_point		*point;

	y = 0;
	while (y < data->map.num_elements)
	{
		line = get_vector_value(&data->map, y);
		x = 0;
		while (x < line->num_elements)
		{
			point = get_point(data, x, y);
			if (point->is_pressed == true)
			{
				if (key_is_pressed(XK_Up, *data))
					point->z += 1;
				else
					point->z -= 1;
				normalize_value(&point->z, INT_MIN, INT_MAX);
			}
			++x;
		}
		++y;
	}
}

static void	simple_clic(t_data *data)
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

static void	select_zone(t_data *data)
{
	t_mouse_data	*mouse;

	mouse = &data->mouse;
	if (can_put_rectangle(data, (t_pos){mouse->zone.start_x,
		mouse->zone.start_y}, (t_pos){mouse->x, mouse->y}) == true)
	{
		mouse->zone.end_x = data->mouse.x;
		mouse->zone.end_y = data->mouse.y;
	}
}

static int	change_map(t_data *data)
{
	int	fd;
	int	old;

	old = data->map_list.actual;
	if (old == -1)
		return (0);
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
	remove_line_lag_comp(data);
	data->input.right = false;
	data->input.left = false;
	return (0);
}

static void	remove_line_lag_comp(t_data *data)
{
	if (data->map_data.size_x * data->map_data.size_y >= 50000
		&& data->param.draw_line == true)
		set_draw_line(data);
	if (data->map_data.size_x * data->map_data.size_y < 50000
		&& data->param.draw_line == false)
		set_draw_line(data);
}
