/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 07:46:46 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/15 07:46:47 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*draw_single(t_data *data, t_pos *pos, int dif, t_point *point);

void	draw_map(t_data *data)
{
	t_pos	pos;
	t_point	*next;

	next = NULL;
	t_vector	*line;
	if (data->camera.pitch < to_rad(90) || data->camera.pitch >= to_rad(271))
	{
		pos.y = 0;
		while ((size_t) pos.y < data->map.num_elements)
		{
			line = get_vector_value(&data->map, pos.y);
			pos.x = 0;
			while ((size_t) pos.x < line->num_elements)
			{
				next = draw_single(data, &pos, 1, next);
				++pos.x;
			}
			++pos.y;
		}
		return ;
	}
	pos.y = data->map.num_elements - 1;
	while (pos.y >= 0)
	{
		line = get_vector_value(&data->map, pos.y);
		pos.x = line->num_elements - 1;
		while (pos.x >= 0)
		{
			next = draw_single(data, &pos, -1, next);
			--pos.x;
		}
		--pos.y;
	}
}

static t_point	*draw_single(t_data *data, t_pos *pos, int dif, t_point *point)
{
	int		x;
	int		y;
	t_point	*temp;

	x = pos->x;
	y = pos->y;
	if (point == NULL)
		point = get_point(data, x, y);
	temp = get_point(data, x, y + dif);
	if (temp && ((data->param.draw_diff_level_line == true && point->z != temp->z) || (data->param.draw_same_level_line == true && point->z == temp->z)))
		draw_line(data, *point, *temp);
	temp = get_point(data, x + dif, y);
	if (temp && ((data->param.draw_diff_level_line == true && point->z != temp->z) || (data->param.draw_same_level_line == true && point->z == temp->z)))
		draw_line(data, *point, *temp);
	return (temp);
}
