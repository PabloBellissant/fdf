/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:58:44 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/04 01:58:44 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "fdf.h"

int	key_press(const KEY_TYPE keycode, t_data *data)
{
	static const KEY_TYPE	key_map[] = {XK_Up, XK_Left, XK_Down,
		XK_Right, XK_Escape, XK_Shift_L};
	size_t					i;

	i = 0;
	while (i < 6)
	{
		if (key_map[i] == keycode)
		{
			*get_key(data, i) = true;
			return (0);
		}
		++i;
	}
	return (-1);
}
