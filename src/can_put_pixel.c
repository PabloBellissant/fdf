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
	if (point_a.x_view >= data->SCREEN_WIDTH)
		return (false);
	if (point_a.y_view >= data->SCREEN_HEIGHT)
		return (false);
	return (true);
}
