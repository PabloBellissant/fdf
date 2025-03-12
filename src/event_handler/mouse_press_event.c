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

#include <X11/keysym.h>
#include "../../include/fdf.h"

int	mouse_press(const int button, int x, int y, t_data *data)
{
	static const KEY_TYPE	key_map[] = {1, 2, 3};
	bool					*value[] = {&data->mouse.left_click,
		&data->mouse.middle_click, &data->mouse.right_click};
	size_t	i;
	t_button	*gui_button;

	if (button > 3)
	{
		mouse_wheel(button, data);
		return (1);
	}
	if (button == 1)
	{
		gui_button = click_button(*data, (t_pos){x, y});
		if (gui_button)
			gui_button->f(data);
	}
	i = 0;
	while (i < 3)
	{
		if (key_map[i] == button)
		{
			(*value)[i] = true;
			return (0);
		}
		++i;
	}
	return (-1);
}