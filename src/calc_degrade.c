/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_degrade.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:28:45 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/06 02:28:47 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_color	calc_degrade(const t_color color_a, const t_color color_b, double mod
						, t_data data)
{
	t_color	new;

	new.color = 0;
	if (data.param.degrade == false)
	{
		new.rgb.r = av(color_a.rgb.r, color_b.rgb.r);
		new.rgb.g = av(color_a.rgb.g, color_b.rgb.g);
		new.rgb.b = av(color_a.rgb.b, color_b.rgb.b);
		return (new);
	}
	if (mod < 0)
		mod *= -1;
	new.rgb.r = color_a.rgb.r * (1 - mod);
	new.rgb.g = color_a.rgb.g * (1 - mod);
	new.rgb.b = color_a.rgb.b * (1 - mod);
	new.rgb.r += color_b.rgb.r * mod;
	new.rgb.g += color_b.rgb.g * mod;
	new.rgb.b += color_b.rgb.b * mod;
	return (new);
}
