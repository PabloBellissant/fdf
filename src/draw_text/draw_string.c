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
	int	adjust;

	adjust = 5 * ft_strlen(str);
	mlx_set_font(data.mlx, data.win, "-misc-fixed-medium-r-normal--20-200-75-75-c-100-iso8859-16");
	mlx_string_put(data.mlx, data.win, pos.x - adjust, pos.y + 6, color, str);
}
