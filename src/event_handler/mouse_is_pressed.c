/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_is_pressed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:09:53 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/05 03:09:56 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <X11/keysym.h>
#include "../../include/fdf.h"

bool	mouse_is_pressed(const KEY_TYPE button, const t_data data)
{
	static const KEY_TYPE	key_map[] = {1, 2, 3};
	const bool				value[] = {data.mouse.left_click,
		data.mouse.middle_click, data.mouse.right_click};
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if (key_map[i] == button)
			return (value[i]);
		++i;
	}
	return (false);
}