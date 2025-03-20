/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_degrade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 04:54:57 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 04:55:46 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_degrade(t_data *data)
{
	if (data->param.degrade == false)
	{
		data->param.degrade = true;
		data->button[9].pressed = true;
		data->button[9].color = 0xFFFFFF;
		data->button[9].text_color = 0x000000;
		data->param.antialiasing = false;
		data->button[10].pressed = false;
		data->button[10].color = 0xFFFFFF;
		data->button[10].text_color = 0xFFFFFF;
	}
	else
	{
		data->param.degrade = false;
		data->button[9].pressed = false;
		data->button[9].color = 0xFFFFFF;
		data->button[9].text_color = 0xFFFFFF;
	}
}
