/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:43:59 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 01:44:01 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_buttons(t_data *data)
{
	int			i;
	t_button	b;

	i = 0;
	while (i < BUTTON_NUMBERS)
	{
		b = data->button[i];
		draw_rectangle(data, (t_pos){b.x, b.y}, (t_pos){
			b.x + b.dim_x, b.y + b.dim_y}, b.color);
		draw_string(*data, (t_pos){b.x + (b.dim_x >> 1),
			b.y + b.dim_y / 2}, b.text, b.text_color);
		++i;
	}
}