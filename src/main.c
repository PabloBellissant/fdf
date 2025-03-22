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

#include "fdf.h"

#include <fcntl.h>
#include <unistd.h>

static int	check_command(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_data	data;
	int		map_fd;

	if (check_command(argc, argv) == -1)
		return (-1);
	ft_bzero(&data, sizeof(data));
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
	{
		ft_putstr_fd("Error : File does not exist\n", 2);
		return (1);
	}
	if (open_map(&data, map_fd) == -1 || close(map_fd) == -1
		|| init_graphic(&data) == -1)
	{
		close(map_fd);
		free_map(&data.map);
		return (1);
	}
	return 1;

	init_fdf(&data, argv[1]);
	hook_handler(&data);
	exit_fdf(&data);
	return (0);
}

static int	check_command(int argc, char **argv)
{
	size_t	arg_len;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf [map_path].fdf\n", 2);
		return (-1);
	}
	arg_len = ft_strlen(argv[1]);
	if (arg_len <= 4 || ft_strcmp(argv[1] + arg_len - 4, ".fdf"))
	{
		ft_putstr_fd("Error : argument must end with '.fdf'\n", 2);
		return (-1);
	}
	return (0);
}
