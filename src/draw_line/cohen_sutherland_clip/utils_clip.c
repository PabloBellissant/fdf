/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 06:50:54 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/19 06:50:56 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_point(t_screen screen, t_point *p, t_pos_double pos, int *out)
{
	p->x_view = pos.x;
	p->y_view = pos.y;
	*out = compute_out(screen, pos);
}

double	get_intersection(int limit, t_point *a, t_point *b, int swap)
{
	if (swap)
		return (compute_intersection(limit, (t_pos_double){a->y_view,
				b->y_view}, (t_pos_double){a->x_view, b->x_view}));
	return (compute_intersection(limit, (t_pos_double){a->x_view,
			b->x_view}, (t_pos_double){a->y_view, b->y_view}));
}
