/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_lsd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:12:24 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 04:12:26 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fun_lsd(t_data *data)
{
	if (data->param.fun_lsd == false)
	{
		data->param.fun_lsd = true;
		data->button[4].pressed = true;
		data->button[4].color = 0xFFFFFF;
		data->button[4].text_color = 0x000000;
		data->param.motion_blur = false;
		data->button[5].pressed = false;
		data->button[5].color = 0xFFFFFF;
		data->button[5].text_color = 0xFFFFFF;
		data->param.full_clear = false;
		data->button[6].pressed = false;
		data->button[6].color = 0xFFFFFF;
		data->button[6].text_color = 0xFFFFFF;
	}
	else
	{
		data->param.fun_lsd = false;
		data->button[4].pressed = false;
		data->button[4].color = 0xFFFFFF;
		data->button[4].text_color = 0xFFFFFF;
	}
}
