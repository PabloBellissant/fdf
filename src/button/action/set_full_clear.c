/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_full_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:28:33 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 04:28:41 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_full_clear(t_data *data)
{
	if (data->param.full_clear == false)
	{
		data->param.full_clear = true;
		data->button[6].pressed = true;
		data->button[6].color = 0xFFFFFF;
		data->button[6].text_color = 0x000000;
		data->param.fun_lsd = false;
		data->button[4].pressed = false;
		data->button[4].color = 0xFFFFFF;
		data->button[4].text_color = 0xFFFFFF;
		data->param.motion_blur = false;
		data->button[5].pressed = false;
		data->button[5].color = 0xFFFFFF;
		data->button[5].text_color = 0xFFFFFF;
	}
	else
	{
		data->param.full_clear = false;
		data->button[6].pressed = false;
		data->button[6].color = 0xFFFFFF;
		data->button[6].text_color = 0xFFFFFF;
	}
}
