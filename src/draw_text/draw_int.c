/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 04:44:51 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/07 04:51:39 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"


/**
 * @brief Draw an integer on the screen.
 * @param data A pointer to the data structure containing pixel information.
 * @param x the position x.
 * @param y the position y.
 * @param color The color of the line.
 * @author Bellissant Pablo
 */
void	draw_int(const t_data data, const int x, const int y, int value)
{
	char	*value_in_str;

	value_in_str = ft_itoa(value);
	if (!value_in_str)
		return ;
	mlx_string_put(data.mlx, data.win, x, y, 0xFFFFFF, value_in_str);
	free(value_in_str);
}
