/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_string_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:42:33 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 06:42:34 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_string_int(const t_data data, t_pos pos, char *str, int value)
{
	draw_string(data, pos, str, WHITE);
	if (!str)
		return ;
	draw_int(data, pos.x + (10 * ft_strlen(str)), pos.y, value);
}
