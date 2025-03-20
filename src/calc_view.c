/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:13:05 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 23:13:07 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	calc_view(t_vector *map, t_data *data)
{
	size_t	i;
	t_point	*point;
	size_t	num_element;
	t_map	*map_data;

	map_data = &data->map_data;
	i = 0;
	num_element = map->num_elements;
	while (i < num_element)
	{
		point = (t_point *)get_vector_value(map, i);
		point->x_view = point->x * map_data->spacing + map_data->x;
		point->y_view = -point->z * map_data->spacing * map_data->z_multiple;
		point->z_view = point->y * map_data->spacing + map_data->y;
		iso_matrix(point, data->camera);
		point->x_view += data->camera.x;
		point->y_view += data->camera.y;
		++i;
	}
}
