/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:18:08 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/06 03:18:09 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

inline void	put_pixel(t_data *data, int x, int y, const int color)
{
	data->addr[y * data->screen.w + x] = color;
}

inline void	safe_put_pixel(t_data *data, int x, int y, const int color)
{
	if (can_put_pos(data, (t_pos){x, y}) == true)
		data->addr[y * data->screen.w + x] = color;
}
