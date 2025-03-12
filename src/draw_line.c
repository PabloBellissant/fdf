/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw_line.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pabellis <mail@bellissantpablo.fr>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/11 02:24:53 by pabellis		  #+#	#+#			 */
/*   Updated: 2025/03/11 02:24:55 by pabellis		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void	bresenham_h(t_data *data, t_point point_a, t_point point_b, int color);
static void	bresenham_v(t_data *data, t_point point_a, t_point point_b, int color);
bool		CohenSutherlandLineClip(t_screen screen, t_point *point_a, t_point *point_b);

void	draw_line(t_data *data, t_point point_a, t_point point_b)
{
	if (data->param.draw_line == false)
	{
		if (can_put_pixel(data, point_a) == true)
			put_pixel(data, point_a.x_view, point_a.y_view, point_a.color.color);
		return ;
	}
	if (data->param.clipping == true && CohenSutherlandLineClip(data->screen, &point_a, &point_b) == false)
		return ;
	if (ft_abs(point_b.y_view - point_a.y_view) <= ft_abs(point_b.x_view - point_a.x_view))
	{
		if (point_b.x_view < point_a.x_view)
			bresenham_h(data, point_b, point_a, 2147483647);
		else
			bresenham_h(data, point_a, point_b, 2147483647);
	}
	else
	{
		if (point_b.y_view < point_a.y_view)
			bresenham_v(data, point_b, point_a, 2147483647);
		else
			bresenham_v(data, point_a, point_b, 2147483647);
	}
}

static void	bresenham_h(t_data *data, t_point point_a, t_point point_b, int color)
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
	while (point_a.x_view <= point_b.x_view)
	{
		if (data->param.clipping == true || can_put_pixel(data, point_a) == true)
			put_pixel(data, point_a.x_view, point_a.y_view, color);
		if (err >= 0)
		{
			point_a.y_view += dir;
			err -= 2 * dx;
		}
		err += 2 * dy;
		++point_a.x_view;
	}
}

static void	bresenham_v(t_data *data, t_point point_a, t_point point_b, int color)
{
	int	dx;
	int	dy;
	int	dir;
	int	err;

	dx = point_b.x_view - point_a.x_view;
	dy = point_b.y_view - point_a.y_view;
	dir = 1;
	if (dx < 0)
		dir  = -1;
	dx *= dir;
	err = 2 * dx - dy;
	while (point_a.y_view <= point_b.y_view)
	{
		if (data->param.clipping == true || can_put_pixel(data, point_a) == true)
			put_pixel(data, point_a.x_view, point_a.y_view, color);
		if (err >= 0)
		{
			point_a.x_view += dir;
			err -= 2 * dy;
		}
		err += 2 * dx;
		++point_a.y_view;
	}
}

int ComputeOutCode(t_screen screen, double x, double y)
{
	int code = 0;

	if (x < 0)
		code |= 0b0001;
	else if (x >= SCREEN_WIDTH)
		code |= 0b0010;
	if (y < 0)
		code |= 0b0100;
	else if (y >= SCREEN_HEIGHT)
		code |= 0b1000;

	return code;
}

bool CohenSutherlandLineClip(t_screen screen, t_point *point_a, t_point *point_b)
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
		x = point_a->x_view + (point_b->x_view - point_a->x_view) * (SCREEN_HEIGHT - 1 - point_a->y_view) / (point_b->y_view - point_a->y_view);
		y = SCREEN_HEIGHT - 1;
	} else if (outcodeOut & 0b0100) {
		x = point_a->x_view + (point_b->x_view - point_a->x_view) * (0 - point_a->y_view) / (point_b->y_view - point_a->y_view);
		y = 0;
	} else if (outcodeOut & 0b0010) {
		y = point_a->y_view + (point_b->y_view - point_a->y_view) * (SCREEN_WIDTH + 1 - point_a->x_view) / (point_b->x_view - point_a->x_view);
		x = SCREEN_WIDTH - 1;
	} else if (outcodeOut & 0b0001) {
		y = point_a->y_view + (point_b->y_view - point_a->y_view) * (0 - point_a->x_view) / (point_b->x_view - point_a->x_view);
		x = 0;
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
