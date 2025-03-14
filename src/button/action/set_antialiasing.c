/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_antialiasing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 04:55:55 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 04:55:57 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_antialiasing(t_data *data)
{
	if (data->param.antialiasing == false)
	{
		data->param.antialiasing = true;
		data->button[10].pressed = true;
		data->button[10].color = 0xFFFFFF;
		data->button[10].text_color = 0x000000;
	}
	else
	{
		data->param.antialiasing = false;
		data->button[10].pressed = false;
		data->button[10].color = 0xFFFFFF;
		data->button[10].text_color = 0xFFFFFF;
	}
}
