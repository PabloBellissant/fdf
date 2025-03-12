/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_clipping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:04:53 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 04:04:57 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_clipping(t_data *data)
{
	if (data->param.clipping == false)
	{
		data->param.clipping = true;
		data->button[3].color = 0x39F200;
		data->button[3].text_color = 0x000000;
	}
	else
	{
		data->param.clipping = false;
		data->button[3].color = 0xf20000;
		data->button[3].text_color = 0xFFFFFF;
	}
}
