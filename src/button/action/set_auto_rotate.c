/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_auto_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:46:24 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 04:46:26 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_auto_rotate(t_data *data)
{
	if (data->param.auto_rotate == false)
	{
		data->param.auto_rotate = true;
		data->button[7].pressed = true;
		data->button[7].color = 0xFFFFFF;
		data->button[7].text_color = 0x000000;
	}
	else
	{
		data->param.auto_rotate = false;
		data->button[7].pressed = false;
		data->button[7].color = 0xFFFFFF;
		data->button[7].text_color = 0xFFFFFF;
	}
}
