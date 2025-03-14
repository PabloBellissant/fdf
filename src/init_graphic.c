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

#include "mlx.h"
#include "fdf.h"

int	init_graphic(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	mlx_get_screen_size(data->mlx, &data->WIDTH, &data->HEIGHT);
	data->win = mlx_new_window(data->mlx, data->WIDTH, data->HEIGHT, "FDF");
	if (data->win == NULL)
		return (-1);
	data->img = mlx_new_image(data->mlx, data->WIDTH, data->HEIGHT);
	if (data->img == NULL)
		return (-1);
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_set_font(data->mlx, data->win, FONT);
	return (0);
}
