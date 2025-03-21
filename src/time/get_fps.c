/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:02:41 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 01:02:43 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_fps(void)
{
	static size_t	start_time;
	static int		frame_generated;
	static int		fps;
	size_t			new_time;

	if (start_time == 0)
		start_time = get_cpu_time();
	++frame_generated;
	new_time = get_cpu_time();
	if (start_time + 1000 < new_time)
	{
		fps = frame_generated;
		frame_generated = 0;
		start_time = new_time;
	}
	return (fps);
}
