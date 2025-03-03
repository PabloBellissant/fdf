/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:58:11 by pabellis          #+#    #+#             */
/*   Updated: 2025/02/28 01:58:14 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SCREEN_WIDTH 3840
# define SCREEN_HEIGHT 2160

# include <stdint.h>
# include <stdbool.h>
# include "libft.h"

typedef union u_color
{
	struct s_rgb
	{
		uint8_t b;
		uint8_t g;
		uint8_t r;
	}	rgb;
	uint32_t color;
} t_color;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		x_view;
	int		y_view;
	t_color	color;
}	t_point;

typedef struct s_param
{
	bool	draw_line;
	bool	antialiasing;
	bool	filled;
	bool	degrade;
	bool	z_buffering;
	bool	limit_fps;
	bool	auto_rotate;
	bool	random_rotation;
}	t_param;

int	open_map(t_vector **map, int fd);

#endif