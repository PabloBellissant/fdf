/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 06:43:40 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 06:43:41 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	blend_color(int base, int blend, float alpha)
{
	t_color	new;

	new.color = 0;
	new.rgb.r = ((base >> 16) & 0xFF) * (1 - alpha) + ((blend >> 16) & 0xFF) * alpha;
	new.rgb.g = ((base >> 8) & 0xFF) * (1 - alpha) + ((blend >> 8) & 0xFF) * alpha;
	new.rgb.b = (base & 0xFF) * (1 - alpha) + (blend & 0xFF) * alpha;
	return (new.color);
}

void	draw_xiaolin_wu(t_data *data, int steep,
		int x, float y, int color)
{
	int	y_int;
	float	frac;
	int	bg1;
	int	bg2;
	int	c1;
	int	c2;

	y_int = (int)y;
	frac = y - y_int;
	bg1 = data->addr[(steep ? x : y_int)
		* data->WIDTH + (steep ? y_int : x)];
	bg2 = data->addr[(steep ? x : y_int + 1)
		* data->WIDTH + (steep ? y_int + 1 : x)];
	c1 = blend_color(bg1, color, 1 - frac);
	c2 = blend_color(bg2, color, frac);
	safe_put_pixel(data, steep ? y_int : x,
		steep ? x : y_int, c1);
	safe_put_pixel(data, steep ? y_int + 1 : x,
		steep ? x : y_int + 1, c2);
}

void	xiaolin_wu(t_data *data, t_point a, t_point b, int color)
{
	int		steep;
	float	dx;
	float	dy;
	float	gradient;
	float	y;

	steep = ft_fabs(b.y_view - a.y_view) > ft_fabs(b.x_view - a.x_view);
	if (steep)
	{
		swap_float(&a.x_view, &a.y_view);
		swap_float(&b.x_view, &b.y_view);
	}
	if (a.x_view > b.x_view)
	{
		swap_float(&a.x_view, &b.x_view);
		swap_float(&a.y_view, &b.y_view);
	}
	dx = b.x_view - a.x_view;
	dy = b.y_view - a.y_view;
	gradient = dy / dx;
	y = a.y_view + 0.5;
	while (a.x_view <= b.x_view)
		draw_xiaolin_wu(data, steep, a.x_view++, y += gradient, color);
}
