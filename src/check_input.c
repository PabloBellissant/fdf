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
#include "fdf.h"

static void	middle_clic(t_data *data);
static void	right_clic(t_data *data);
static void	change_map(t_data *data);

void	check_input(t_data *data)
{
	mlx_mouse_get_pos(data->mlx, data->win, &data->mouse.x, &data->mouse.y);
	if (key_is_pressed(XK_Escape, *data))
		exit_fdf(data);
	if (key_is_pressed(XK_Right, *data) || key_is_pressed(XK_Left, *data))
		change_map(data);
	if (mouse_is_pressed(3, *data))
		right_clic(data);
	if (mouse_is_pressed(2, *data))
		middle_clic(data);
}

static void	right_clic(t_data *data)
{
	data->camera.pitch -= (float)(data->mouse.x - data->mouse.old_x) / 300;
	data->camera.yaw += (float)(data->mouse.y - data->mouse.old_y) / 300;
	data->mouse.old_x = data->mouse.x;
	data->mouse.old_y = data->mouse.y;
	normalize_camera(&data->camera);
	set_camera_math(&data->camera);
}

static void	middle_clic(t_data *data)
{
	data->camera.x += (data->mouse.x - data->mouse.old_x) * 1.6;
	data->camera.y += (data->mouse.y - data->mouse.old_y) * 1.6;
	data->mouse.old_x = data->mouse.x;
	data->mouse.old_y = data->mouse.y;
}

static void	change_map(t_data *data)
{
	int	fd;
	int	old;

	old = data->map_list.actual;
	if (key_is_pressed(XK_Right, *data))
		++data->map_list.actual;
	else
		--data->map_list.actual;
	if (data->map_list.actual < 0)
		data->map_list.actual += MAPS_AMOUNT;
	if (data->map_list.actual >= MAPS_AMOUNT)
		data->map_list.actual = 0;
	fd = open(data->map_list.map_list[data->map_list.actual], O_RDONLY);
	if (fd == -1)
	{
		data->map_list.actual = old;
		return ;
	}
	free_map(&data->map);
	open_map(data, fd);
	close(fd);
	if (data->map_data.size_x * data->map_data.size_y > 50000
		&& data->param.draw_line)
		set_draw_line(data);
	set_camera_math(&data->camera);
	data->input.right = false;
	data->input.left = false;
}
