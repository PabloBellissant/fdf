/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:28:29 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 23:28:30 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline t_point	*get_point(t_data *data, size_t x, size_t y)
{
	t_vector	*line;

	if (y >= data->map.num_elements)
		return (NULL);
	line = get_vector_value(&data->map, y);
	if (x >= line->num_elements)
		return (NULL);
	return (get_vector_value(line, x));
}
