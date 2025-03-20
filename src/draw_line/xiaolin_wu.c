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

static int	blend(int base, int blend, float alpha);
static void	draw_xiaolin_wu(t_data *data, int steep,
				t_pos_double pos, int color);

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
		draw_xiaolin_wu(data, steep,
			(t_pos_double){a.x_view++, y += gradient}, color);
}

static int	blend(int base, int blend, float alpha)
{
	t_color	new;

	new.c = 0;
	new.rgb.r = ((base >> 16) & 0xFF) * (1 - alpha) + ((blend >> 16) & 0xFF)
		* alpha;
	new.rgb.g = ((base >> 8) & 0xFF) * (1 - alpha) + ((blend >> 8) & 0xFF)
		* alpha;
	new.rgb.b = (base & 0xFF) * (1 - alpha) + (blend & 0xFF) * alpha;
	return (new.c);
}

static void	draw_xiaolin_wu(t_data *data, int steep,
	t_pos_double pos, int color)
{
	float	frac;
	int		bg1;
	int		bg2;

	frac = pos.y - (int)pos.y;
	if (steep)
	{
		bg1 = data->addr[(int)pos.x * data->screen.w + (int)pos.y];
		bg2 = data->addr[(int)pos.x * data->screen.w + (int)pos.y + 1];
		put_pixel(data, (int)pos.y, (int)pos.x, blend(bg1, color, 1 - frac));
		put_pixel(data, (int)pos.y + 1, (int)pos.x, blend(bg2, color, frac));
	}
	else
	{
		bg1 = data->addr[(int)pos.y * data->screen.w + (int)pos.x];
		bg2 = data->addr[((int)pos.y + 1) * data->screen.w + (int)pos.x];
		put_pixel(data, pos.x, (int)pos.y, blend(bg1, color, 1 - frac));
		put_pixel(data, pos.x, (int)pos.y + 1, blend(bg2, color, frac));
	}
}
