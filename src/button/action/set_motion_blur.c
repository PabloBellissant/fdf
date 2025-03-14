/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_degrade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:14:51 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 04:14:58 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_motion_blur(t_data *data)
{
	if (data->param.motion_blur == false)
	{
		data->param.motion_blur = true;
		data->button[5].pressed = true;
		data->button[5].color = 0xFFFFFF;
		data->button[5].text_color = 0x000000;
		data->param.fun_lsd = false;
		data->button[4].pressed = false;
		data->button[4].color = 0xFFFFFF;
		data->button[4].text_color = 0xFFFFFF;
		data->param.full_clear = false;
		data->button[6].pressed = false;
		data->button[6].color = 0xFFFFFF;
		data->button[6].text_color = 0xFFFFFF;
	}
	else
	{
		data->param.motion_blur = false;
		data->button[5].pressed = false;
		data->button[5].color = 0xFFFFFF;
		data->button[5].text_color = 0xFFFFFF;
	}
}
