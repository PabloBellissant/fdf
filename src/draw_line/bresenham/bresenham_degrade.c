/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_degrade.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 06:05:39 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 06:05:46 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	color_h(t_point point_a, t_point point_b, int div, t_data *data);
static int	color_v(t_point point_a, t_point point_b, int div, t_data *data);

void	bresenham_degrade_h(t_data *data, t_point point_a, t_point point_b)
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
	while (++point_a.x_view <= point_b.x_view)
	{
		if (data->param.clipping == true || can_put_pixel(data, point_a))
			put_pixel(data, point_a.x_view, point_a.y_view,
				color_h(point_b, point_a, dx, data));
		if (err >= 0)
		{
			point_a.y_view += dir;
			err -= 2 * dx;
		}
		err += 2 * dy;
	}
}

void	bresenham_degrade_v(t_data *data, t_point point_a, t_point point_b)
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
	while (++point_a.y_view <= point_b.y_view)
	{
		if (data->param.clipping == true || can_put_pixel(data, point_a))
			put_pixel(data, point_a.x_view, point_a.y_view,
				color_v(point_b, point_a, dy, data));
		if (err >= 0)
		{
			point_a.x_view += dir;
			err -= 2 * dy;
		}
		err += 2 * dx;
	}
}

static int	color_v(t_point point_a, t_point point_b, int div, t_data *data)
{
	t_color	color;

	color = calc_degrade(point_a.color, point_b.color,
			(float)(point_a.y_view - point_b.y_view) / div, *data);
	return (color.c);
}

static int	color_h(t_point point_a, t_point point_b, int div, t_data *data)
{
	t_color	color;

	color = calc_degrade(point_a.color, point_b.color,
			(float)(point_a.x_view - point_b.x_view) / div, *data);
	return (color.c);
}
