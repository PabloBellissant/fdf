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

inline t_point	*get_point(t_data *data, int x, int y)
{
	t_vector	*line;

	if ((size_t) y >= data->map.num_elements)
		return (NULL);
	line = get_vector_value(&data->map, y);
	if ((size_t) x >= line->num_elements)
		return (NULL);
	return (get_vector_value(line, x));
}
