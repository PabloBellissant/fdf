/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_event.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:19:15 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/05 02:19:19 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define ZONE data->mouse.zone

static bool	select_all_points(t_data *data);
static void	deselect_all_points(t_data *data);
static bool	is_in_rectangle(t_point *point, t_pos pos_a, t_pos pos_b);

int	mouse_release(const int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == 1)
	{
		select_all_points(data);
		data->mouse.left_click = false;
	}
	else if (button == 2)
		data->mouse.middle_click = false;
	else if (button == 3)
		data->mouse.right_click = false;
	return (0);
}

static bool	select_all_points(t_data *data)
{
	size_t		x;
	size_t		y;
	t_vector	*line;
	t_point		*point;

	y = 0;
	deselect_all_points(data);
	data->param.have_points_select = false;
	while (y < data->map.num_elements)
	{
		line = get_vector_value(&data->map, y);
		x = 0;
		while (x < line->num_elements)
		{
			point = get_point(data, x, y);
			if (point && is_in_rectangle(point, (t_pos){ZONE.start_x,
				ZONE.start_y}, (t_pos){ZONE.end_x, ZONE.end_y}))
			{
				point->is_pressed = true;
				data->param.have_points_select = true;
			}
			++x;
		}
		++y;
	}
	return (data->param.have_points_select);
}

static void	deselect_all_points(t_data *data)
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
			if (point)
				point->is_pressed = false;
			++x;
		}
		++y;
	}
}

static bool	is_in_rectangle(t_point *point, t_pos pos_a, t_pos pos_b)
{
	if (pos_a.x > pos_b.x)
		swap_int(&pos_a.x, &pos_b.x);
	if (pos_a.y > pos_b.y)
		swap_int(&pos_a.y, &pos_b.y);
	if (point->x_view < pos_a.x)
		return (false);
	if (point->y_view < pos_a.y)
		return (false);
	if (point->x_view > pos_b.x)
		return (false);
	if (point->y_view > pos_b.y)
		return (false);
	return (true);
}
