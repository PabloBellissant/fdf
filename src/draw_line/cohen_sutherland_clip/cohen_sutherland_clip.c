/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohen_sutherland_clip.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 06:45:52 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/18 06:45:54 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	cohen_sutherland_clip(t_data *data, t_point *a, t_point *b)
{
	int	out0;
	int	out1;
	int	out;

	out0 = compute_out(data->screen, (t_pos_double){a->x_view, a->y_view});
	out1 = compute_out(data->screen, (t_pos_double){b->x_view, b->y_view});
	while (out0 | out1)
	{
		if (out0 & out1)
			return (false);
		if (out1 > out0)
			out = out1;
		else
			out = out0;
		compute_new_coordinates(out, a, b, data);
		if (out == out0)
			update_point(data->screen, a,
				(t_pos_double){data->clip_data.x, data->clip_data.y}, &out0);
		else
			update_point(data->screen, b,
				(t_pos_double){data->clip_data.x, data->clip_data.y}, &out1);
	}
	return (true);
}
