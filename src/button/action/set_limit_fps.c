/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_limit_fps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:34:21 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 07:34:24 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_limit_fps(t_data *data)
{
	if (data->param.limit_fps == false)
	{
		data->param.limit_fps = true;
		data->button[8].pressed = true;
		data->button[8].color = 0xFFFFFF;
		data->button[8].text_color = 0x000000;
	}
	else
	{
		data->param.limit_fps = false;
		data->button[8].pressed = false;
		data->button[8].color = 0xFFFFFF;
		data->button[8].text_color = 0xFFFFFF;
	}
}
