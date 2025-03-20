/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 06:02:32 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 06:02:33 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_h(t_data *data, t_point point_a, t_point point_b, int color)
{
	int	dx;
	int	dy;
	int	dir;
	int	err;

	dx = point_b.x_view - point_a.x_view;
	dy = point_b.y_view - point_a.y_view;
	dir = 1;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	err = 2 * dy - dx;
	while (point_a.x_view <= point_b.x_view)
	{
		++point_a.x_view;
		if (data->param.clipping == true || can_put_pixel(data, point_a))
			put_pixel(data, point_a.x_view, point_a.y_view, color);
		if (err >= 0)
		{
			point_a.y_view += dir;
			err -= 2 * dx;
		}
		err += 2 * dy;
	}
}

void	bresenham_v(t_data *data, t_point point_a, t_point point_b, int color)
{
	int	dx;
	int	dy;
	int	dir;
	int	err;

	dx = point_b.x_view - point_a.x_view;
	dy = point_b.y_view - point_a.y_view;
	dir = 1;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	err = 2 * dx - dy;
	while (point_a.y_view <= point_b.y_view)
	{
		++point_a.y_view;
		if (data->param.clipping == true || can_put_pixel(data, point_a))
			put_pixel(data, point_a.x_view, point_a.y_view, color);
		if (err >= 0)
		{
			point_a.x_view += dir;
			err -= 2 * dy;
		}
		err += 2 * dx;
	}
}
