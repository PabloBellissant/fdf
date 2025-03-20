/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:04:01 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/11 21:04:04 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	can_put_pixel(const t_data *data, const t_point point_a)
{
	if (point_a.x_view < 0)
		return (false);
	if (point_a.y_view < 0)
		return (false);
	if (point_a.x_view >= data->screen.w)
		return (false);
	if (point_a.y_view >= data->screen.h)
		return (false);
	return (true);
}

bool	can_put_pos(const t_data *data, const t_pos pos)
{
	if (pos.x < 0)
		return (false);
	if (pos.y < 0)
		return (false);
	if (pos.x >= data->screen.w)
		return (false);
	if (pos.y >= data->screen.h)
		return (false);
	return (true);
}

bool	can_put_rectangle(const t_data *data, t_pos pos_a, t_pos pos_b)
{
	if (can_put_pos(data, pos_a) == true && can_put_pos(data, pos_b) == true)
		return (true);
	return (false);
}
