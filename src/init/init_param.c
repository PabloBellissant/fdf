/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:10:25 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/06 03:10:27 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_param(t_data *data)
{
	data->param.draw_line = true;
	data->param.draw_same_level_line = true;
	data->param.draw_diff_level_line = true;
	data->param.clipping = true;
	data->param.full_clear = true;
	data->param.fun_lsd = false;
	data->param.motion_blur = false;
	data->param.auto_rotate = false;
	data->param.limit_fps = false;
	data->param.degrade = false;
	data->param.antialiasing = false;
	data->info.frames_generated = 0;
	data->info.fps = 0;
}
