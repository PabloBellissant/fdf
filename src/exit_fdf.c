/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:40:10 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/15 22:40:12 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"

void	free_map(t_vector *map);

void	exit_fdf(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(&data->map);
	free_tab(data->map_list.map_list);
	exit(0);
}

void	free_map(t_vector *map)
{
	size_t		i;
	t_vector	*line;

	i = 0;
	while (i < map->num_elements)
	{
		line = get_vector_value(map, i);
		free(line->data);
		++i;
	}
	free(map->data);
}
