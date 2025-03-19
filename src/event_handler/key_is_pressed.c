/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pressed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:11:57 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/03 23:12:02 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <X11/keysym.h>
#include "fdf.h"

bool	key_is_pressed(const KEY_TYPE key, const t_data data)
{
	static const KEY_TYPE	key_map[] = {XK_Up, XK_Left,
		XK_Down, XK_Right, XK_Escape};
	const bool				value[] = {data.input.up, data.input.left,
		data.input.down, data.input.right, data.input.escape};
	int						i;

	i = 0;
	while (i < 9)
	{
		if (key_map[i] == key)
			return (value[i]);
		++i;
	}
	return (false);
}
