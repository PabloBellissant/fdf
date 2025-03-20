/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:24:53 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 04:59:18 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void	draw_line(t_data *data, t_point point_a, t_point point_b);
static void	draw_line_degrade(t_data *data, t_point point_a, t_point point_b);

void	draw(t_data *data, t_point point_a, t_point point_b)
{
	if (data->param.draw_line == false)
	{
		safe_put_pixel(data, point_a.x_view, point_a.y_view, point_a.color.c);
		return ;
	}
	if (data->param.clipping == true
		&& cohen_sutherland_clip(data, &point_a, &point_b) == false)
	{
		return ;
	}
	if (data->param.antialiasing == true)
	{
		xiaolin_wu(data, point_a, point_b,
			calc_degrade(point_a.color, point_b.color, 0, *data).c);
		return ;
	}
	if (data->param.degrade == true && point_a.color.c != point_b.color.c)
		draw_line_degrade(data, point_a, point_b);
	else
		draw_line(data, point_a, point_b);
}

static void	draw_line(t_data *data, t_point point_a, t_point point_b)
{
	t_color	color;

	color = calc_degrade(point_a.color, point_b.color, 0, *data);
	if (ft_abs(point_b.y_view - point_a.y_view)
		<= ft_abs(point_b.x_view - point_a.x_view))
	{
		if (point_b.x_view < point_a.x_view)
			bresenham_h(data, point_b, point_a, color.c);
		else
			bresenham_h(data, point_a, point_b, color.c);
	}
	else
	{
		if (point_b.y_view < point_a.y_view)
			bresenham_v(data, point_b, point_a, color.c);
		else
			bresenham_v(data, point_a, point_b, color.c);
	}
}

static void	draw_line_degrade(t_data *data, t_point point_a, t_point point_b)
{
	if (ft_abs(point_b.y_view - point_a.y_view)
		<= ft_abs(point_b.x_view - point_a.x_view))
	{
		if (point_b.x_view < point_a.x_view)
			bresenham_degrade_h(data, point_b, point_a);
		else
			bresenham_degrade_h(data, point_a, point_b);
	}
	else
	{
		if (point_b.y_view < point_a.y_view)
			bresenham_degrade_v(data, point_b, point_a);
		else
			bresenham_degrade_v(data, point_a, point_b);
	}
}
