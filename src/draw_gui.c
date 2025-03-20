/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:58:15 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/14 03:58:16 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define L_GRAY 0x212121
#define GRAY 0x292929
#define WHITE 0xFFFFFF

static void	draw_select_zone(t_data *data);

void	draw_gui(t_data *data)
{
	if (can_put_rectangle(data,
			(t_pos){0, 0}, (t_pos){590, data->screen.h - 1}))
	{
		draw_full_rectangle(data, (t_pos){0, 0},
			(t_pos){590, data->screen.h - 1}, L_GRAY);
	}
	else
		return ;
	if (can_put_rectangle(data, (t_pos){50, 50}, (t_pos){540, 490}))
		draw_full_rectangle(data, (t_pos){50, 50}, (t_pos){540, 490}, GRAY);
	if (can_put_rectangle(data, (t_pos){50, 50}, (t_pos){540, 490}))
		draw_edge_rectangle(data, (t_pos){50, 50}, (t_pos){540, 490}, WHITE);
	if (can_put_rectangle(data, (t_pos){50, 540}, (t_pos){540, 960}))
		draw_full_rectangle(data, (t_pos){50, 540}, (t_pos){540, 960}, GRAY);
	if (can_put_rectangle(data, (t_pos){50, 540}, (t_pos){540, 960}))
		draw_edge_rectangle(data, (t_pos){50, 540}, (t_pos){540, 960}, WHITE);
	if (can_put_rectangle(data, (t_pos){230, 80}, (t_pos){365, 110}))
		draw_edge_rectangle(data, (t_pos){230, 80}, (t_pos){365, 110}, WHITE);
	draw_string(*data, (t_pos){245, 100}, "<Settings>", WHITE);
	draw_buttons(data);
	draw_data(data);
	draw_select_zone(data);
}

static void	draw_select_zone(t_data *data)
{
	t_mouse_data	*mouse;

	mouse = &data->mouse;
	if (mouse_is_pressed(1, *data) == false)
		return ;
	if (can_put_rectangle(data, (t_pos){mouse->zone.start_x,
			mouse->zone.start_y}, (t_pos){mouse->x, mouse->y}) == true)
	{
		draw_edge_rectangle(data, (t_pos){mouse->zone.start_x,
			mouse->zone.start_y}, (t_pos){mouse->x, mouse->y}, WHITE);
	}
}
