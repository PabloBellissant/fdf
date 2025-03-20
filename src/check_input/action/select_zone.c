/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_zone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 07:09:01 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/19 07:09:02 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	select_zone(t_data *data)
{
	t_mouse_data	*mouse;

	mouse = &data->mouse;
	if (can_put_rectangle(data, (t_pos){mouse->zone.start_x,
			mouse->zone.start_y}, (t_pos){mouse->x, mouse->y}) == true)
	{
		mouse->zone.end_x = data->mouse.x;
		mouse->zone.end_y = data->mouse.y;
	}
}
