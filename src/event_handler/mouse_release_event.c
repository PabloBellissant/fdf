/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_event.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:19:15 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/05 02:19:19 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "../../include/fdf.h"

int	mouse_release(const int button, int x, int y, t_data *data)
{
	static const KEY_TYPE	key_map[] = {1, 2, 3};
	bool					*value[] = {&data->mouse.left_click,
		&data->mouse.middle_click, &data->mouse.right_click};
	size_t	i;

	(void) x;
	(void) y;
	if (button > 3)
		return (0);
	i = 0;
	while (i < 3)
	{
		if (key_map[i] == button)
		{
			(*value)[i] = false;
			return (0);
		}
		++i;
	}
	return (-1);
}