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

#include "fdf.h"

void	calc_view(t_vector *map, t_data *data)
{
	size_t	i;
	t_point	*point;

	i = 0;
	while (i < map->num_elements)
	{
		point = (t_point *)get_vector_value(map, i);
		point->x_view = point->x * data->map_data.spacing + data->map_data.x;
		point->y_view = -point->z * data->map_data.spacing;
		point->z_view = point->y * data->map_data.spacing + data->map_data.y;
		iso_matrix(point, data->camera);
		point->x_view += data->camera.x;
		point->y_view += data->camera.y;
		++i;
	}
}
