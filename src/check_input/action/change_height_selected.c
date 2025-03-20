/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_height_selected.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 07:05:51 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/19 07:05:53 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <limits.h>
#include "fdf.h"

void	change_height_selected(t_data *data)
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
				normalize_value(&point->z, INT_MIN + 1, INT_MAX - 1);
			}
			++x;
		}
		++y;
	}
}
