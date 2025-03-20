/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:41:14 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/17 08:41:16 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	*get_key(t_data *data, int value)
{
	bool		*keys_list[6];
	t_input_map	*input;

	input = &data->input;
	keys_list[0] = &input->up;
	keys_list[1] = &input->left;
	keys_list[2] = &input->down;
	keys_list[3] = &input->right;
	keys_list[4] = &input->escape;
	keys_list[5] = &input->maj;
	return (keys_list[value]);
}
