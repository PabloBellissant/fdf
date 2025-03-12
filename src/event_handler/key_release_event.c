/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:05:33 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/04 02:05:36 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "../../include/fdf.h"

int	key_release(const int keycode, t_data *data)
{
	static const KEY_TYPE	key_map[] = {XK_w, XK_a, XK_s, XK_d,
		XK_Up, XK_Left, XK_Down, XK_Right};
	bool	*value[] = {&data->input.w, &data->input.a, &data->input.s,
		&data->input.d, &data->input.up, &data->input.left, &data->input.down,
		&data->input.right};
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if (key_map[i] == keycode)
		{
			(*value)[i] = false;
			return (0);
		}
		++i;
	}
	return (-1);
}
