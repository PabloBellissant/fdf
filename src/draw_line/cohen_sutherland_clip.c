/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohen_sutherland_clip.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 06:45:52 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/18 06:45:54 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_point(t_screen screen, t_point *p, t_pos_double pos, int *out);
int		compute_out(t_screen screen, t_pos_double pos);
void	compute_new_coordinates(int out, t_point *a, t_point *b, double *x, double *y, t_screen *screen);
double	compute_intersection(double val, t_pos_double pos1, t_pos_double pos2);

bool	cohen_sutherland_clip(t_screen screen, t_point *a, t_point *b)
{
	int out0;
	int out1;
	int out;
	double x;
	double y;

	out0 = compute_out(screen, (t_pos_double){a->x_view, a->y_view});
	out1 = compute_out(screen, (t_pos_double){b->x_view, b->y_view});
	while (out0 | out1)
	{
		if (out0 & out1)
			return (false);
		out = out1 > out0 ? out1 : out0;
		compute_new_coordinates(out, a, b, &x, &y, &screen);
		if (out == out0)
			update_point(screen, a, (t_pos_double){x, y}, &out0);
		else
			update_point(screen, b, (t_pos_double){x, y}, &out1);
	}
	return (true);
}

int	compute_out(t_screen screen, t_pos_double pos)
{
	int code;

	code = 0;
	if (pos.x < 590)
		code |= 0b0001;
	else if (pos.x >= WIDTH)
		code |= 0b0010;
	if (pos.y < 0)
		code |= 0b0100;
	else if (pos.y >= HEIGHT)
		code |= 0b1000;
	return (code);
}

double	compute_intersection(double val, t_pos_double pos1, t_pos_double pos2)
{
	double res;

	res = pos1.x + (pos1.y - pos1.x) * (val - pos2.x) / (pos2.y - pos2.x);
	return (res);
}

void	update_point(t_screen screen, t_point *p, t_pos_double pos, int *out)
{
	p->x_view = pos.x;
	p->y_view = pos.y;
	*out = compute_out(screen, pos);
}

void	compute_new_coordinates(int out, t_point *a, t_point *b, double *x, double *y, t_screen *screen)
{
	if (out & 0b1000)
	{
		*x = compute_intersection(screen->height - 1, (t_pos_double)
			{a->x_view, b->x_view}, (t_pos_double){a->y_view, b->y_view});
		*y = screen->height - 1;
	}
	else if (out & 0b0100)
	{
		*x = compute_intersection(0, (t_pos_double){a->x_view, b->x_view},
			(t_pos_double){a->y_view, b->y_view});
		*y = 0;
	}
	else if (out & 0b0010)
	{
		*y = compute_intersection(screen->width - 1, (t_pos_double)
			{a->y_view, b->y_view}, (t_pos_double){a->x_view, b->x_view});
		*x = screen->width - 1;
	}
	else
	{
		*y = compute_intersection(590, (t_pos_double){a->y_view, b->y_view},
			(t_pos_double){a->x_view, b->x_view});
		*x = 590;
	}
}
