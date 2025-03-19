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
	data->button[0] = (t_button){100, 150, 120, 25, WHITE, BLACK,
		"DRAW_LINE", &set_draw_line, true};
	data->button[1] = (t_button){100, 190, 120, 25, WHITE, BLACK,
		"SAME_LEVEL", &same_level_draw, true};
	data->button[2] = (t_button){100, 230, 120, 25, WHITE, BLACK,
		"DIFF_LEVEL", &diff_level_draw, true};
	data->button[3] = (t_button){100, 270, 120, 25, WHITE, BLACK,
		"SET_CLIP", &set_clipping, true};
	data->button[4] = (t_button){235, 310, 120, 25, WHITE, WHITE,
		"FUN_LSD", &fun_lsd, false};
	data->button[5] = (t_button){370, 310, 120, 25, WHITE, WHITE,
		"MOTION_BLUR", &set_motion_blur, false};
	data->button[6] = (t_button){100, 310, 120, 25, WHITE, BLACK,
		"FULL_CLEAR", &set_full_clear, true};
	data->button[7] = (t_button){100, 350, 120, 25, WHITE, WHITE,
		"AUTO_ROTATE", &set_auto_rotate, false};
	data->button[8] = (t_button){100, 390, 120, 25, WHITE, WHITE,
		"LIMIT_FPS", &set_limit_fps, false};
	data->button[9] = (t_button){100, 430, 120, 25, WHITE, WHITE,
		"DEGRADE", &set_degrade, false};
	data->button[10] = (t_button){100, 470, 120, 25, WHITE, WHITE,
		"ANTIALIASING", &set_antialiasing, false};
}
