/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delta_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:59:52 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 04:59:53 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_delta_time(void)
{
	static int	last_time;
	int			new_time;
	int			output;

	if (last_time == 0)
		last_time = get_proc_time();
	new_time = get_proc_time();
	output = new_time - last_time;
	last_time = new_time;
	return (output);
}
