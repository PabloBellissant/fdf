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
static void	*screen_memset(int *s, int color, size_t n);

void	clear_window(t_data *data)
{
	if (data->param.full_clear == true)
		screen_memset(data->addr, BG_COLOR, data->HEIGHT * data->line_length);
	else if (data->param.fun_lsd == true)
		lsd_clear(data->addr, data->HEIGHT * data->line_length);
	else if (data->param.motion_blur == true)
		blur_clear(data->addr, data->HEIGHT * data->line_length);
}

static void	lsd_clear(void *s, size_t n)
{
	size_t	i;
	t_color	*ptr;

	ptr = (t_color *)s;
	i = 0;
	while (i < n / sizeof(int))
	{
		if (ptr[i].color > 0x181818)
			ptr[i].color >>= 1;
		else
			ptr[i].color = 0x181818;
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
		if (ptr[i].color > 0x181818)
		{
			ptr[i].rgb.r *= 0.95;
			ptr[i].rgb.g *= 0.95;
			ptr[i].rgb.b *= 0.95;
		}
		else
			ptr[i].color = 0x181818;
		++i;
	}
}

static void	*screen_memset(int *s, int color, size_t n)
{
	size_t	i;
	size_t	blocks;
	size_t	i_time_8;

	n /= 4;
	blocks = n / 8;
	i = 0;
	i_time_8 = i * 8;
	while (i < blocks)
	{
		i_time_8 = i * 8;
		s[i_time_8] = color;
		s[i_time_8 + 1] = color;
		s[i_time_8 + 2] = color;
		s[i_time_8 + 3] = color;
		s[i_time_8 + 4] = color;
		s[i_time_8 + 5] = color;
		s[i_time_8 + 6] = color;
		s[i_time_8 + 7] = color;
		++i;
	}
	i = i_time_8;
	while (i < n)
		s[i++] = color;
	return (s);
}
