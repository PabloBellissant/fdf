/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:04:42 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/20 08:04:45 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data	t_data;

typedef union u_color
{
	struct s_rgb
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
	}	rgb;
	uint32_t	c;
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	float	x_view;
	float	y_view;
	float	z_view;
	bool	is_pressed;
	float	w;
	t_color	color;
}	t_point;

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_pos_double
{
	double		x;
	double		y;
}	t_pos_double;

typedef struct s_map_list
{
	char	**map_list;
	int		actual;
}	t_map_list;

typedef struct s_camera
{
	int		x;
	int		y;
	int		z;
	int		fov;
	float	aspect_ratio;
	float	near;
	float	far;
	float	yaw;
	float	pitch;
	float	roll;
	float	cospitch;
	float	cosyaw;
	float	sinpitch;
	float	sinyaw;
	float	distance;
}	t_camera;

typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	float	spacing;
	int		size_x;
	int		size_y;
	float	z_multiple;
}	t_map;

typedef struct s_param
{
	bool	draw_line;
	bool	draw_same_level_line;
	bool	draw_diff_level_line;
	bool	clipping;
	bool	fun_lsd;
	bool	motion_blur;
	bool	full_clear;
	bool	auto_rotate;
	bool	degrade;
	bool	antialiasing;
	bool	limit_fps;
	bool	have_points_select;
}	t_param;

typedef struct s_input_map
{
	bool	up;
	bool	left;
	bool	down;
	bool	right;
	bool	escape;
	bool	maj;
}	t_input_map;

typedef struct s_select_zone
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
}	t_select_zone;

typedef struct s_mouse_data
{
	bool			left_click;
	bool			middle_click;
	bool			right_click;
	int				old_x;
	int				old_y;
	int				x;
	int				y;
	t_select_zone	zone;
}	t_mouse_data;

typedef struct s_info
{
	int		fps;
	size_t	frames_generated;
}	t_info;

typedef struct s_screen
{
	int	w;
	int	h;
}	t_screen;

typedef struct s_button
{
	int		x;
	int		y;
	int		dim_x;
	int		dim_y;
	int		color;
	int		text_color;
	char	*text;
	void	(*f)(t_data *);
	bool	pressed;
}	t_button;

typedef struct s_data
{
	t_param			param;
	t_camera		camera;
	t_input_map		input;
	t_mouse_data	mouse;
	t_map			map_data;
	t_info			info;
	t_screen		screen;
	t_button		button[BUTTON_AMOUNT];
	t_vector		map;
	t_map_list		map_list;
	void			*mlx;
	void			*win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	size_t			delta_time;
	t_pos			clip_data;
}	t_data;

#endif