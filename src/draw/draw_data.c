/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:39:12 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 06:39:14 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/fdf.h"

static void	draw_info(t_data data, int x, int start_y);
static void	draw_camera_info(t_data data, int x, int start_y);
static void	draw_map_info(t_data data, int x, int start_y);

void	draw_data(t_data *data)
{
	draw_info(*data, 110, 620);
	draw_camera_info(*data, 350, 620);
	draw_map_info(*data, 350, 770);
}

static void	draw_info(t_data data, int x, int start_y)
{
	char	*map_name;

	if (data.map_list.actual != -1)
		map_name = get_name(data.map_list.map_list[data.map_list.actual]);
	else
		map_name = ft_strdup("ERROR");
	if (data.param.limit_fps == true && data.info.fps > 61)
		data.info.fps = 60;
	draw_string(data, (t_pos){x - 5, start_y - 5}, "<Info>", 0xFFFFFF);
	draw_string_int(data, (t_pos){x, start_y + 25}, "Fps: ", data.info.fps);
	if (data.param.limit_fps == true)
		draw_string(data, (t_pos){x + 78, start_y + 25}, "(limited)", 0xFFFFFF);
	draw_string(data, (t_pos){x, start_y + 50}, "Name: ", 0xFFFFFF);
	draw_string(data, (t_pos){x + 60, start_y + 50}, map_name, 0xFFFFFF);
	draw_string_int(data, (t_pos){x, start_y + 75}, "Delta time: ",
		data.delta_time);
	draw_string_int(data, (t_pos){x, start_y + 100}, "Total frames: ",
		data.info.frames_generated);
	draw_string(data, (t_pos){x - 5, start_y + 145}, "<Screen>", 0xFFFFFF);
	draw_string_int(data, (t_pos){x, start_y + 175}, "Width: ",
		data.screen.w);
	draw_string_int(data, (t_pos){x, start_y + 200}, "Height: ",
		data.screen.h);
	free(map_name);
}

static void	draw_camera_info(t_data data, int x, int start_y)
{
	t_camera	camera;

	camera = data.camera;
	draw_string(data, (t_pos){x - 5, start_y - 5}, "<Camera>", 0xFFFFFF);
	draw_string_int(data, (t_pos){x, start_y + 25}, "Pitch: ",
		to_degrees(camera.pitch));
	draw_string_int(data, (t_pos){x, start_y + 50}, "Yaw: ",
		to_degrees(camera.yaw));
	draw_string_int(data, (t_pos){x, start_y + 75}, "Zoom: ",
		data.map_data.spacing);
}

static void	draw_map_info(t_data data, int x, int start_y)
{
	draw_string(data, (t_pos){x - 5, start_y - 5}, "<Map>", 0xFFFFFF);
	draw_string_int(data, (t_pos){x, start_y + 25}, "Width: ",
		data.map_data.size_x);
	draw_string_int(data, (t_pos){x, start_y + 50}, "Height: ",
		data.map_data.size_y);
	draw_string_int(data, (t_pos){x, start_y + 75}, "Pixels: ",
		data.map_data.size_x * data.map_data.size_y);
	draw_string_int(data, (t_pos){x, start_y + 100}, "PosX: ",
		data.camera.x);
	draw_string_int(data, (t_pos){x, start_y + 125}, "PosY: ",
		data.camera.y);
	draw_string_int(data, (t_pos){x, start_y + 150}, "Z_ratio: ",
		(int)data.map_data.z_multiple);
}
