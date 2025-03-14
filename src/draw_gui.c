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

# define L_GRAY 0x212121
# define GRAY 0x292929
# define WHITE 0xFFFFFF

void	draw_gui(t_data *data)
{
	if (can_put_rectangle(data, (t_pos){0, 0}, (t_pos){590, data->HEIGHT - 1}))
	{
		draw_full_rectangle(data, (t_pos){0, 0},
			(t_pos){590, data->HEIGHT - 1}, L_GRAY);
		draw_full_rectangle(data, (t_pos){50, 100},
			(t_pos){540, 595}, GRAY);
		draw_edge_rectangle(data, (t_pos){50, 100},
			(t_pos){540, 595}, WHITE);
		draw_full_rectangle(data, (t_pos){50, 645},
			(t_pos){540, 1050}, GRAY);
		draw_edge_rectangle(data, (t_pos){50, 645},
			(t_pos){540, 1050}, WHITE);
		draw_edge_rectangle(data, (t_pos){230, 130},
			(t_pos){365, 160}, WHITE);
		draw_string(*data, (t_pos){245, 150}, "<Settings>", WHITE);
	}
	draw_buttons(data);
	draw_data(data);
}
