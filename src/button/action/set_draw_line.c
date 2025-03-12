/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:34:14 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 01:34:16 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_draw_line(t_data *data)
{
	if (data->param.draw_line == false)
	{
		data->param.draw_line = true;
		data->button[0].color = 0x39F200;
		data->button[0].text_color = 0x000000;
	}
	else
	{
		data->param.draw_line = false;
		data->button[0].color = 0xf20000;
		data->button[0].text_color = 0xFFFFFF;
	}
}
