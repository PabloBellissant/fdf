/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:18:54 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/05 02:18:58 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_mouse(t_data *data, int x, int y);
static void	update_click_map(const int button, t_data *data);

int	mouse_press(const int button, int x, int y, t_data *data)
{
	t_button	*gui_button;

	if (button > 3)
	{
		mouse_wheel(button, data);
		return (0);
	}
	if (button == 1)
	{
		gui_button = click_button(*data, (t_pos){x, y});
		if (gui_button)
		{
			gui_button->f(data);
			return (0);
		}
	}
	set_mouse(data, x, y);
	update_click_map(button, data);
	return (-1);
}

static void	set_mouse(t_data *data, int x, int y)
{
	data->mouse.x = x;
	data->mouse.y = y;
	data->mouse.old_x = x;
	data->mouse.old_y = y;
	data->mouse.zone.start_x = x;
	data->mouse.zone.start_y = y;
}

static void	update_click_map(const int button, t_data *data)
{
	if (button == 1)
		data->mouse.left_click = true;
	else if (button == 2)
		data->mouse.middle_click = true;
	else if (button == 3)
		data->mouse.right_click = true;
}
