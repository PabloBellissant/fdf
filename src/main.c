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

#include "mlx.h"
#include "fdf.h"

#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_data	data;
	int		map_fd;
	int		map_list_fd;
	char	map_list[5000];

	(void) argc;
	if (init_graphic(&data) == -1)
		return (-1);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		return (-1);
	init_key(&data);
	init_param(&data);
	set_button(&data);
	data.camera.x = data.WIDTH / 2;
	data.camera.y = data.HEIGHT / 2;
	data.camera.pitch = to_rad(45);
	data.camera.yaw = to_rad(35.264);
	open_map(&data, map_fd);
	set_camera_math(&data.camera);
	map_list_fd = open("maps/maps_name", O_RDONLY);
	read(map_list_fd, map_list, 5000);
	data.map_list.map_list = ft_split(map_list, '\n');
	data.map_list.actual = 0;
	data.map_data.spacing = 5;
	hook_handler(&data);
	return (0);
}
