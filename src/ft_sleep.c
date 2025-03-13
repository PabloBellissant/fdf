/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:39:14 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 07:39:15 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_sleep(int ms)
{
	int	first;

	if (ms <= 0)
		return ;
	first = get_proc_time();
	while (ms > get_proc_time() - first)
		;
}
