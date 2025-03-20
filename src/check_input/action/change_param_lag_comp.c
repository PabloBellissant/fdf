/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_param_lag_comp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 07:07:10 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/19 07:07:12 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_param_lag_comp(t_data *data)
{
	if (data->map_data.size_x * data->map_data.size_y >= 50000
		&& data->param.draw_line == true)
		set_draw_line(data);
	if (data->map_data.size_x * data->map_data.size_y < 50000
		&& data->param.draw_line == false)
		set_draw_line(data);
}
