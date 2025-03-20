/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_clip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 06:48:43 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/19 06:48:50 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	compute_intersection(double val, t_pos_double pos1, t_pos_double pos2)
{
	double	res;

	res = pos1.x + (pos1.y - pos1.x) * (val - pos2.x) / (pos2.y - pos2.x);
	return (res);
}

void	compute_new_coordinates(int out, t_point *a, t_point *b, t_data *data)
{
	double	x;
	double	y;

	if (out & 0b1000)
	{
		x = get_intersection(data->screen.h - 1, a, b, 0);
		y = data->screen.h - 1;
	}
	else if (out & 0b0100)
	{
		x = get_intersection(0, a, b, 0);
		y = 0;
	}
	else if (out & 0b0010)
	{
		y = get_intersection(data->screen.w - 1, a, b, 1);
		x = data->screen.w - 1;
	}
	else
	{
		y = get_intersection(590, a, b, 1);
		x = 590;
	}
	data->clip_data.x = x;
	data->clip_data.y = y;
}

int	compute_out(t_screen screen, t_pos_double pos)
{
	int	code;

	code = 0;
	if (pos.x < 590)
		code |= 0b0001;
	else if (pos.x >= screen.w)
		code |= 0b0010;
	if (pos.y < 0)
		code |= 0b0100;
	else if (pos.y >= screen.h)
		code |= 0b1000;
	return (code);
}
