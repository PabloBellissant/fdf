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

#include "../../include/fdf.h"

static void		draw_map_backward(t_data *data);
static t_point	*draw_single(t_data *data, t_pos *pos, int dif, t_point *point);

void	draw_map(t_data *data)
{
	t_pos		pos;
	t_point		*next;
	t_vector	*line;

	next = NULL;
	if (data->camera.pitch <= to_rad(90) || data->camera.pitch >= to_rad(270))
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
	}
	else
		draw_map_backward(data);
}

static void	draw_map_backward(t_data *data)
{
	t_pos		pos;
	t_point		*next;
	t_vector	*line;

	next = NULL;
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
	t_point	*temp;
	t_param	*param;

	param = &data->param;
	if (point == NULL)
		point = get_point(data, pos->x, pos->y);
	if (point->is_pressed)
		draw_circle(data, (t_pos){point->x_view, point->y_view});
	temp = get_point(data, pos->x, pos->y + dif);
	if (temp && ((param->draw_diff_level_line == true && point->z != temp->z)
			|| (param->draw_same_level_line == true && point->z == temp->z)))
	{
		draw(data, *point, *temp);
	}
	temp = get_point(data, pos->x + dif, pos->y);
	if (temp && ((param->draw_diff_level_line == true && point->z != temp->z)
			|| (param->draw_same_level_line == true && point->z == temp->z)))
	{
		draw(data, *point, *temp);
	}
	return (temp);
}
