/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 02:35:43 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/07 02:35:45 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	draw_string(const t_data data, t_pos pos, char *str, int color)
{
	if (str)
		mlx_string_put(data.mlx, data.win, pos.x, pos.y, color, str);
	else
		mlx_string_put(data.mlx, data.win, pos.x, pos.y, color, "ERROR");
}

void	draw_center_string(const t_data data, t_pos pos, char *str, int color)
{
	int	adjust;

	if (!str)
		return ;
	adjust = 5 * ft_strlen(str);
	mlx_string_put(data.mlx, data.win, pos.x - adjust, pos.y + 6, color, str);
}
