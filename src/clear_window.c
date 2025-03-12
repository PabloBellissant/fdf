/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:19:00 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/12 04:19:02 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	blur_clear(void *s, size_t n);
static void	lsd_clear(void *s, size_t n);

void	clear_window(t_data *data)
{
	if (data->param.full_clear == true)
		ft_bzero(data->addr, data->SCREEN_HEIGHT * data->line_length);
	else if (data->param.fun_lsd == true)
		lsd_clear(data->addr, data->SCREEN_HEIGHT * data->line_length);
	else if (data->param.motion_blur == true)
		blur_clear(data->addr, data->SCREEN_HEIGHT * data->line_length);
}

static void	lsd_clear(void *s, size_t n)
{
	size_t	i;
	t_color	*ptr;

	ptr = (t_color *)s;
	i = 0;
	while (i < n / sizeof(int))
	{
		if (ptr[i].color > 0)
			ptr[i].color >>= 1;
		++i;
	}
}

static void	blur_clear(void *s, size_t n)
{
	size_t	i;
	t_color	*ptr;

	ptr = (t_color *)s;
	i = 0;
	while (i < n / sizeof(int))
	{
		if (ptr[i].color > 0)
		{
			ptr[i].rgb.r >>= 1;
			ptr[i].rgb.g >>= 1;
			ptr[i].rgb.b >>= 1;
		}
		++i;
	}
}
