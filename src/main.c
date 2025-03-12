/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:03:46 by pabellis          #+#    #+#             */
/*   Updated: 2025/02/28 01:03:48 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

t_point	*get_point(t_data *data, int x, int y)
{
	t_point	*point;

	point = ((t_point *)get_vector_value(data->map, y * data->map_data.size_x + x));
	return (point);
}

void	set_view(t_vector *map, t_data data)
{
	size_t	i;
	t_point	*point;

	i = 0;
	while (i < map->num_elements)
	{
		point = (t_point *)get_vector_value(map, i);
		point->x_view = point->x * data.map_data.spacing + data.map_data.x;
		point->y_view = -point->z * data.map_data.spacing;
		point->z_view = point->y * data.map_data.spacing + data.map_data.y;

		if (point->z == 0)
			point->color.color = 2147483647;
		else
		{
			point->color.color = 0;
			point->color.rgb.r = 255;
			point->color.rgb.b = 250;
		}
		rotation_matrix(point, data.camera);
		point->x_view += data.camera.x;
		point->y_view += data.camera.y;
		++i;
	}
}
#include <fcntl.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

int game_loop(t_data *data)
{
	data->info.fps = get_fps();
	++data->info.frames_generated;
	if (mouse_is_pressed(3, *data))
	{
		data->camera.pitch -= (float)(data->mouse.x - data->mouse.old_x) / 300;
		data->camera.yaw += (float)(data->mouse.y - data->mouse.old_y) / 300;
		normalize_camera(&data->camera);
		data->mouse.old_x = data->mouse.x;
		data->mouse.old_y = data->mouse.y;
		set_camera_math(&data->camera);
	}
	if (mouse_is_pressed(2, *data))
	{
		data->camera.x += (data->mouse.x - data->mouse.old_x) * 1.6;
		data->camera.y += (data->mouse.y - data->mouse.old_y) * 1.6;
		data->mouse.old_x = data->mouse.x;
		data->mouse.old_y = data->mouse.y;
	}
	clear_window(data);
	set_view(data->map, *data);
	data->map_data.x = -((data->map_data.size_x >> 1) * data->map_data.spacing);
	data->map_data.y = -((data->map_data.size_y >> 1) * data->map_data.spacing);

	int	x;
	int	y = 0;
	t_point	*point;
	t_point	*temp;
	while (y < data->map_data.size_y)
	{
		x = 0;
		while (x < data->map_data.size_x)
		{
			point = get_point(data, x, y);
			if (x < data->map_data.size_x - 1)
			{
				temp = get_point(data, x + 1, y);
				if ((data->param.draw_diff_level_line == true && point->z != temp->z) || (data->param.draw_same_level_line == true && point->z == temp->z))
					draw_line(data, *point, *temp);
			}
			if (y < data->map_data.size_y - 1)
			{
				temp = get_point(data, x, y + 1);
				if ((data->param.draw_diff_level_line == true && point->z != temp->z) || (data->param.draw_same_level_line == true && point->z == temp->z))
					draw_line(data, *point, *temp);
			}
			++x;
		}
		++y;
	}
	auto_rotate(data);
	data->delta_time = get_delta_time();
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw_buttons(data);
	draw_string(*data, (t_pos){data->SCREEN_WIDTH - 220, 100}, "FPS :", 0xFFFFFF);
	draw_int(*data, data->SCREEN_WIDTH - 160, 100, data->info.fps);
	draw_int(*data, data->SCREEN_WIDTH - 160, 150, to_degrees(data->camera.pitch));
	draw_int(*data, data->SCREEN_WIDTH - 160, 200, to_degrees(data->camera.yaw));
	return (0);
}

int	mouse_move(const int x, const int y, t_data *data)
{
	if (x == data->mouse.x && y == data->mouse.y)
		return (-1);
	data->mouse.old_x = data->mouse.x;
	data->mouse.old_y = data->mouse.y;
	data->mouse.x = x;
	data->mouse.y = y;
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data = {0};

	init_key(&data);
	set_button(&data);
	(void) argc;
	data.mlx = mlx_init();
	mlx_get_screen_size(data.mlx, &data.screen.width, &data.screen.height);
	data.win = mlx_new_window(data.mlx, data.SCREEN_WIDTH, data.SCREEN_HEIGHT, "FDF");
	data.img = mlx_new_image(data.mlx, data.SCREEN_WIDTH, data.SCREEN_HEIGHT);
	data.addr = (int *)mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	init_param(&data);
	int fd = open(argv[1], O_RDONLY);
	data.camera.x = data.SCREEN_WIDTH / 2;
	data.camera.y = data.SCREEN_HEIGHT / 2;
	data.camera.fov = 90;
	data.camera.aspect_ratio = data.SCREEN_WIDTH / data.SCREEN_HEIGHT;
	data.camera.near_plane = 1.0;
	data.camera.far_plane = 1000.0;
	data.camera.pitch = to_rad(45);
	data.camera.yaw = to_rad(35.264);
	data.camera.roll = 0;
	open_map(&data, fd);

	set_camera_math(&data.camera);
	data.map_data.spacing = 5;
	mlx_hook(data.win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.win, ButtonPress, ButtonPressMask, mouse_press, &data);
	mlx_hook(data.win, ButtonRelease, ButtonReleaseMask, mouse_release, &data);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, mouse_move, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}


//quaternion