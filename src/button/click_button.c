/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:04:53 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 03:04:54 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_button	*click_button(t_data data, t_pos pos)
{
	int			i;
	t_button	*button;

	i = 0;
	while (i < BUTTON_NUMBERS)
	{
		button = &data.button[i];
		if (pos.x > button->x && pos.x < button->x + button->dim_x)
		{
			if (pos.y > button->y && pos.y < button->y + button->dim_y)
				return (button);
		}
		++i;
	}
	return (NULL);
}