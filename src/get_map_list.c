/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:47:13 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/17 01:47:17 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

char	**get_map_list(void)
{
	int		fd;
	char	map_list[5000];
	char	**output;

	ft_bzero(map_list, 5000);
	fd = open("maps/maps_name", O_RDONLY);
	if (!fd)
		return (NULL);
	if (read(fd, map_list, 5000) == -1)
	{
		close(fd);
		return (NULL);
	}
	if (close(fd) == -1)
		return (NULL);
	output = ft_split(map_list, '\n');
	return (output);
}
