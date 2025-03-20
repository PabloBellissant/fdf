/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:14:53 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/14 00:20:47 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"

int	init_graphic(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	mlx_get_screen_size(data->mlx, &data->screen.w, &data->screen.h);
	data->win = mlx_new_window(data->mlx, data->screen.w, data->screen.h, FDF);
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (-1);
	}
	data->img = mlx_new_image(data->mlx, data->screen.w, data->screen.h);
	if (data->img == NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (-1);
	}
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_set_font(data->mlx, data->win, FONT);
	data->camera.x = data->screen.w / 2 + 295;
	data->camera.y = data->screen.h / 2;
	return (0);
}
