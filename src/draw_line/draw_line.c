/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:24:53 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 04:59:18 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void	draw_line_degrade(t_data *data, t_point point_a, t_point point_b);
bool		CohenSutherlandLineClip(t_screen screen, t_point *point_a, t_point *point_b);

void	draw_line(t_data *data, t_point point_a, t_point point_b)
{
	int	color;

	if (data->param.draw_line == false)
	{
		if (can_put_pixel(data, point_a) == true)
			put_pixel(data, point_a.x_view, point_a.y_view, point_a.color.color);
		return ;
	}
	if (data->param.clipping == true && CohenSutherlandLineClip(data->screen, &point_a, &point_b) == false)
		return ;
	if (data->param.antialiasing == true)
	{
		xiaolin_wu(data, point_a, point_b, calc_degrade(point_a.color, point_b.color, 0, *data).color);
		return ;
	}
	if (data->param.degrade == true && point_a.color.color != point_b.color.color)
	{
		draw_line_degrade(data, point_a, point_b);
		return ;
	}
	color = calc_degrade(point_a.color, point_b.color, 0, *data).color;
	if (ft_abs(point_b.y_view - point_a.y_view) <= ft_abs(point_b.x_view - point_a.x_view))
	{
		if (point_b.x_view < point_a.x_view)
			bresenham_h(data, point_b, point_a, color);
		else
			bresenham_h(data, point_a, point_b, color);
	}
	else
	{
		if (point_b.y_view < point_a.y_view)
			bresenham_v(data, point_b, point_a, color);
		else
			bresenham_v(data, point_a, point_b, color);
	}
}

static void	draw_line_degrade(t_data *data, t_point point_a, t_point point_b)
{
	if (ft_abs(point_b.y_view - point_a.y_view) <= ft_abs(point_b.x_view - point_a.x_view))
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

int	ComputeOutCode(t_screen screen, double x, double y)
{
	int	code = 0;

	if (x < 590)
		code |= 0b0001;
	else if (x >= WIDTH)
		code |= 0b0010;
	if (y < 0)
		code |= 0b0100;
	else if (y >= HEIGHT)
		code |= 0b1000;

	return code;
}

bool	CohenSutherlandLineClip(t_screen screen, t_point *point_a, t_point *point_b)
{
	int outcode0 = ComputeOutCode(screen, point_a->x_view, point_a->y_view);
	int outcode1 = ComputeOutCode(screen, point_b->x_view, point_b->y_view);

	if (!(outcode0 | outcode1))
		return (true);
	if (outcode0 & outcode1)
		return (false);
	double x, y;
	int outcodeOut = outcode1 > outcode0 ? outcode1 : outcode0;
	if (outcodeOut & 0b1000) {
		x = point_a->x_view + (point_b->x_view - point_a->x_view) * (HEIGHT - 1 - point_a->y_view) / (point_b->y_view - point_a->y_view);
		y = HEIGHT - 1;
	} else if (outcodeOut & 0b0100) {
		x = point_a->x_view + (point_b->x_view - point_a->x_view) * (0 - point_a->y_view) / (point_b->y_view - point_a->y_view);
		y = 0;
	} else if (outcodeOut & 0b0010) {
		y = point_a->y_view + (point_b->y_view - point_a->y_view) * (WIDTH + 1 - point_a->x_view) / (point_b->x_view - point_a->x_view);
		x = WIDTH - 1;
	} else if (outcodeOut & 0b0001) {
		y = point_a->y_view + (point_b->y_view - point_a->y_view) * (590 - point_a->x_view) / (point_b->x_view - point_a->x_view);
		x = 590;
	}
	if (outcodeOut == outcode0) {
		point_a->x_view = x;
		point_a->y_view = y;
		outcode0 = ComputeOutCode(screen, point_a->x_view, point_a->y_view);
	} else {
		point_b->x_view = x;
		point_b->y_view = y;
		outcode1 = ComputeOutCode(screen, point_b->x_view, point_b->y_view);
	}
	if (!(outcode0 | outcode1))
		return (true);
	return (false);
}
