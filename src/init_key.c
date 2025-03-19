/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:47:48 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/04 01:47:51 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_key(t_data *data)
{
	data->input.up = false;
	data->input.left = false;
	data->input.down = false;
	data->input.right = false;
	data->mouse.left_click = false;
	data->mouse.middle_click = false;
	data->mouse.right_click = false;
}
