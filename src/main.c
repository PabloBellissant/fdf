/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:03:46 by pabellis          #+#    #+#             */
/*   Updated: 2025/02/28 01:03:48 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

typedef struct s_data
{
	t_param	param;
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

void put_pixel(const t_data *data, const int x, const int y, const int color)
{
	if (y * SCREEN_WIDTH + x > 0)
		data->addr[y * SCREEN_WIDTH + x] = color;
}

int	av(const int val_a, const int val_b)
{
	return ((val_a + val_b) >> 1);
}

t_color	calc_degrade(const t_color color_a, const t_color color_b, const double mod)
{
	t_color	new;
	if (color_a.color != color_b.color)
		dprintf(2, "%d, %d, %f : ", color_a.color, color_b.color, mod);
	new.color = 0;
	new.rgb.r = color_a.rgb.r * (1 - mod);
	new.rgb.g = color_a.rgb.g * (1 - mod);
	new.rgb.b = color_a.rgb.b * (1 - mod);
	new.rgb.r += color_b.rgb.r * mod;
	new.rgb.g += color_b.rgb.g * mod;
	new.rgb.b += color_b.rgb.b * mod;
	if (color_a.color != color_b.color)
		dprintf(2, "%d\n", new.color);
	return (new);
}

void	draw_line(t_data *data, t_point point_a, t_point point_b)
{
	int	dx;
	int	dy;
	int	i;
	t_point temp;
	double coef;
	t_color	color;

	t_point *var = NULL;
	if (point_b.x_view < point_a.x_view)
	{
		temp = point_a;
		var = &temp;
		point_a = point_b;
		point_b = temp;
		swap_int((int *) &(point_a.color.color), (int *) &(point_b.color.color));
	}
	dx = point_b.x_view - point_a.x_view;
	dy = point_b.y_view - point_a.y_view;
	if (abs(dx) >= abs(dy))
	{
		if (var != NULL)
			swap_int((int *) &(point_a.color.color), (int *) &(point_b.color.color));
		coef = (double)dy / dx;
		i = point_a.x_view;
		color = point_a.color;
		while (i <= point_b.x_view)
		{
			if (data->param.degrade == true)
				color = calc_degrade(point_a.color, point_b.color, (double)(i - point_a.x_view) / point_b.x_view);
			put_pixel(data, i, point_a.y_view + ((i - point_a.x_view) * coef), color.color);
			++i;
		}
		return ;
	}
	coef = (double)dx / dy;
	i = point_a.y_view;
	color = point_a.color;
	while (i < point_b.y_view || i > point_b.y_view)
	{
		if (data->param.degrade == true)
			color = calc_degrade(point_a.color, point_b.color, (double)(i - point_a.y_view) / point_b.x_view);
		put_pixel(data, point_a.x_view + ((i - point_a.y_view) * coef), i, color.color);
		++i;
		if (i > point_b.y_view)
			i -= 2;
	}
	put_pixel(data, point_a.x_view + ((i - point_a.y_view) * coef), i, point_a.color.color);
}

void	iso_calc(t_point *point)
{
	int	new_x;
	int	new_y;

	point->y_view *= -1;
	new_x = (sqrt(2)/2) * (point->x_view - point->y_view);
	new_y = (sqrt((double)2 / 3) * (point->z * -3)) - (((double)1 / sqrt(6)) * (point->x_view + point->y_view));
	point->x_view = new_x;
	point->y_view = new_y;
}

void	init_param(t_data *data)
{
	data->param.draw_line = true;
	data->param.degrade = false;
	data->param.antialiasing = false;
	data->param.filled = false;
	data->param.z_buffering = false;
	data->param.limit_fps = false;
	data->param.auto_rotate = false;
	data->param.random_rotation = false;
}

t_point	*get_point(t_vector *map, int x, int y)
{
	t_point	*point;
	size_t	i;

	i = 1;
	point = ((t_point *)get_vector_value(map, 0));
	while (point->x != x || point->y != y)
	{
		point = (t_point *)get_vector_value(map, i);
		++i;
		if (map->num_elements == i)
			return (NULL);
	}
	return (point);
}

void	set_view(t_vector *map)
{
	size_t	i;
	t_point	*point;

	i = 0;
	while (i < map->num_elements)
	{
		point = (t_point *)get_vector_value(map, i);
		point->x_view = point->x * 50 - 800;
		point->y_view = point->y * 50 + 1600;
		if (point->z == 0)
			point->color.color = 2147483647;
		else
		{
			point->color.color = 0;
			point->color.rgb.r = 255;
			point->color.rgb.b = 250;
		}
		iso_calc(point);
		++i;
	}
}

#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	t_data		data;
	t_vector	*map;

	(void) argc;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	data.img = mlx_new_image(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data.addr = (int *)mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	init_param(&data);
	map = NULL;
	int fd = open(argv[1], O_RDONLY);
	open_map(&map, fd);
	set_view(map);

	int	x;
	int	y = 0;
	t_point *point;
	t_point	*temp;
	while (y < 11)
	{
		x = 0;
		while (x < 18)
		{
			point = get_point(map, x, y);
			if (x < 17)
			{
				temp = get_point(map, x + 1, y);
				draw_line(&data, *point, *temp);
			}
			if (y < 10)
			{
				temp = get_point(map, x, y + 1);
				draw_line(&data, *point, *temp);
			}
			++x;
		}
		++y;
	}

	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
