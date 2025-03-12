/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:30:46 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 01:30:47 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_button(t_data *data)
{
	data->button[0] = (t_button){100, 100, 120, 25, 0x39F200, 0,
		"DRAW_LINE", &set_draw_line};
	data->button[1] = (t_button){100, 140, 120, 25, 0x39F200, 0,
		"SAME_LEVEL", &same_level_draw};
	data->button[2] = (t_button){100, 180, 120, 25, 0x39F200, 0,
		"DIFF_LEVEL", &diff_level_draw};
	data->button[3] = (t_button){100, 220, 120, 25, 0x39F200, 0,
		"SET_CLIP", &set_clipping};
	data->button[4] = (t_button){235, 260, 120, 25, 0xf20000, 0xFFFFFF,
		"FUN_LSD", &fun_lsd};
	data->button[5] = (t_button){370, 260, 120, 25, 0xf20000, 0xFFFFFF,
		"SET_BLUR", &set_motion_blur};
	data->button[6] = (t_button){100, 260, 120, 25, 0x39F200, 0,
		"FULL_CLEAR", &set_full_clear};
	data->button[7] = (t_button){100, 300, 120, 25, 0xf20000, 0xFFFFFF,
		"AUTO_ROTATE", &set_auto_rotate};
}
