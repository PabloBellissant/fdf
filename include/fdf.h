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

# include <stdint.h>
# include <stdbool.h>
# include "libft.h"

# define SCREEN_WIDTH screen.width
# define SCREEN_HEIGHT screen.height

# define BUTTON_NUMBERS 8//16

# define KEY_TYPE int

typedef struct s_data t_data;

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
	int		z_view;
	t_color	color;
}	t_point;

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_camera
{
	int		x;
	int		y;
	int		z;
	int		fov;
	float	aspect_ratio;
	float	near_plane;
	float	far_plane;
	float	yaw;
	float	pitch;
	float	roll;
	float	cospitch;
	float	cosyaw;
	float	sinpitch;
	float	sinyaw;
}	t_camera;

typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	float	spacing;
	int		size_x;
	int		size_y;
	int		size_z;
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
	bool	random_rotation;
	bool	degrade;
	bool	antialiasing;
	bool	filled;
	bool	z_buffering;
	bool	limit_fps;
	bool	show_gui;
	bool	show_info;
}	t_param;

typedef struct s_input_map
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	up;
	bool	left;
	bool	down;
	bool	right;
}	t_input_map;

typedef struct	s_mouse_data
{
	bool	left_click;
	bool	middle_click;
	bool	right_click;
	int		old_x;
	int		old_y;
	int		x;
	int		y;
}	t_mouse_data;

typedef struct	s_info
{
	int		fps;
	size_t	frames_generated;
}	t_info;

typedef struct s_screen
{
	int	width;
	int	height;
}	t_screen;

typedef struct	s_button
{
	int		x;
	int		y;
	int		dim_x;
	int		dim_y;
	int		color;
	int		text_color;
	char	*text;
	void	(*f)(t_data *);
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
	t_button		button[BUTTON_NUMBERS];
	t_vector		*map;
	void			*mlx;
	void			*win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				delta_time;
} t_data;

int		open_map(t_data *data, int fd);
void	init_key(t_data *data);
bool	key_is_pressed(const KEY_TYPE key, t_data data);
int		key_press(const int keycode, t_data *data);
int		key_release(const int keycode, t_data *data);
bool	mouse_is_pressed(const KEY_TYPE button, const t_data data);
int		mouse_press(const int button, int x, int y, t_data *data);
int		mouse_release(const int button, int x, int y, t_data *data);
void	mouse_wheel(const int button, t_data *data);
t_color	calc_degrade(const t_color color_a, const t_color color_b, double mod
			, t_data data);
void	calc_matrix(t_point *p, float m[3][3]);
void	rotation_matrix(t_point *point, const t_camera camera);
void	init_param(t_data *data);
void	put_pixel(t_data *data, int x, int y, const int color);
ssize_t	get_proc_time(void);
void	draw_string(const t_data data, t_pos pos, char *str, int color);
void	draw_int(const t_data data, const int x, const int y, int value);
float	to_rad(float degrees);
float	to_degrees(float radian);
void	isometric_projection(t_point *point, const t_camera camera);
void	draw_line(t_data *data, t_point point_a, t_point point_b);
bool	can_put_pixel(const t_data *data, const t_point point_a);
void	normalize_camera(t_camera *camera);
int		get_fps(void);
void	draw_rectangle(t_data *data, t_pos pos_a, t_pos pos_b, int color);
void	clear_window(t_data *data);
void	set_camera_math(t_camera *camera);
int		get_delta_time(void);
void	auto_rotate(t_data *data);

void	set_button(t_data *data);
void	set_draw_line(t_data *data);
void	draw_buttons(t_data *data);
t_button	*click_button(t_data data, t_pos pos);
void	same_level_draw(t_data *data);
void	diff_level_draw(t_data *data);
void	set_clipping(t_data *data);
void	fun_lsd(t_data *data);
void	set_motion_blur(t_data *data);
void	set_full_clear(t_data *data);
void	set_auto_rotate(t_data *data);

#endif