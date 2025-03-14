/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:48:15 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 01:48:17 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_full_rectangle(t_data *data, t_pos pos_a, t_pos pos_b, int color)
{
	int	x;
	int	y;

	y = pos_a.y;
	while (y <= pos_b.y)
	{
		x = pos_a.x;
		while (x <= pos_b.x)
		{
			put_pixel(data, x, y, color);
			++x;
		}
		++y;
	}
}

void	draw_edge_rectangle(t_data *data, t_pos pos_a, t_pos pos_b, int color)
{
	int	x;
	int	y;

	y = pos_a.y;
	x = pos_a.x;
	while (x < pos_b.x)
	{
		put_pixel(data, x, y, color);
		++x;
	}
	while (y < pos_b.y)
	{
		put_pixel(data, x, y, color);
		++y;
	}
	while (x > pos_a.x)
	{
		put_pixel(data, x, y, color);
		--x;
	}
	while (y > pos_a.y)
	{
		put_pixel(data, x, y, color);
		--y;
	}
}
