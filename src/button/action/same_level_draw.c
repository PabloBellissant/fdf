/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_level_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:21:06 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 03:34:13 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	same_level_draw(t_data *data)
{
	if (data->param.draw_same_level_line == false)
	{
		data->param.draw_same_level_line = true;
		data->button[1].color = 0x39F200;
		data->button[1].text_color = 0x000000;
	}
	else
	{
		data->param.draw_same_level_line = false;
		data->button[1].color = 0xf20000;
		data->button[1].text_color = 0xFFFFFF;
	}
}
