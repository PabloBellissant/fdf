/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:36:48 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 06:36:49 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_move(const int x, const int y, t_data *data)
{
	data->mouse.old_x = data->mouse.x;
	data->mouse.old_y = data->mouse.y;
	data->mouse.x = x;
	data->mouse.y = y;
	return (0);
}
