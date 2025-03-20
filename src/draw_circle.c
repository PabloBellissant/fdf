/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 05:00:14 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/19 05:00:24 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	plot_circle(t_data *data, t_pos pos, int x, int y);

void	draw_circle(t_data *data, t_pos pos)
{
	int	x;
	int	y;
	int	d;
	int	r;

	r = data->map_data.spacing;
	if (r < 4)
		r = 4;
	if (can_put_pos(data, pos) == false)
		return ;
	d = 3 - (r >> 1);
	y = r >> 2;
	x = 0;
	while (x <= y)
	{
		plot_circle(data, pos, x, y);
		if (d < 0)
			d += 4 * x + 6;
		else
		{
			d += 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}

static void	plot_circle(t_data *data, t_pos pos, int x, int y)
{
	safe_put_pixel(data, pos.x + x, pos.y + y, CYAN);
	safe_put_pixel(data, pos.x - x, pos.y + y, CYAN);
	safe_put_pixel(data, pos.x + x, pos.y - y, CYAN);
	safe_put_pixel(data, pos.x - x, pos.y - y, CYAN);
	safe_put_pixel(data, pos.x + y, pos.y + x, CYAN);
	safe_put_pixel(data, pos.x - y, pos.y + x, CYAN);
	safe_put_pixel(data, pos.x + y, pos.y - x, CYAN);
	safe_put_pixel(data, pos.x - y, pos.y - x, CYAN);
}
