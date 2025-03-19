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

void plot_circle(t_data *data, int xc, int yc, int x, int y, int color)
{
	put_pixel(data, xc + x, yc + y, color);
	put_pixel(data, xc - x, yc + y, color);
	put_pixel(data, xc + x, yc - y, color);
	put_pixel(data, xc - x, yc - y, color);
	put_pixel(data, xc + y, yc + x, color);
	put_pixel(data, xc - y, yc + x, color);
	put_pixel(data, xc + y, yc - x, color);
	put_pixel(data, xc - y, yc - x, color);
}

void draw_circle(t_data *data, int xc, int yc, int r, int color)
{
	int x = 0;
	int y = r;
	int d = 3 - 2 * r;
	while (x <= y)
	{
		plot_circle(data, xc, yc, x, y, color);
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