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

#include <X11/keysym.h>
#include "fdf.h"

static void	select_all_points(t_data *data, t_select_zone *zone);
static void	deselect_all_points(t_data *data);
static bool	is_in_rectangle(t_point *point, t_pos pos_a, t_pos pos_b);

int	mouse_release(const int button, int x, int y, t_data *data)
{
	(void) y;
	if (button == 1)
	{
		if (x > 490)
		{
			if (key_is_pressed(XK_Shift_L, *data) == false)
				deselect_all_points(data);
			select_all_points(data, &data->mouse.zone);
		}
		data->mouse.left_click = false;
	}
	else if (button == 2)
		data->mouse.middle_click = false;
	else if (button == 3)
		data->mouse.right_click = false;
	return (0);
}

static void	select_all_points(t_data *data, t_select_zone *zone)
{
	size_t		x;
	size_t		y;
	t_vector	*line;
	t_point		*point;

	y = 0;
	data->param.have_points_select = false;
	while (y < data->map.num_elements)
	{
		line = get_vector_value(&data->map, y);
		x = 0;
		while (x < line->num_elements)
		{
			point = get_point(data, x, y);
			if (point && is_in_rectangle(point, (t_pos){zone->start_x,
					zone->start_y}, (t_pos){zone->end_x, zone->end_y}))
			{
				point->is_pressed = true;
				data->param.have_points_select = true;
			}
			++x;
		}
		++y;
	}
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
