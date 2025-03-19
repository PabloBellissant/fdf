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

# define WIDTH screen.width
# define HEIGHT screen.height

# define BG_COLOR 0x181818
# define WHITE 0xFFFFFF
# define BLACK 0x000000

# define INFILE argv[1]

# define BUTTON_AMOUNT 11//16
# define MAPS_AMOUNT 31
# define FONT "-misc-fixed-medium-r-normal--20-200-75-75-c-100-iso8859-16"

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
	float	x_view;
	float	y_view;
	float	z_view;
	bool	is_pressed;
	int		w;
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
	bool	filled;
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
}	t_input_map;

typedef struct	s_select_zone
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
}	t_select_zone;

typedef struct	s_mouse_data
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
	int				delta_time;
} t_data;

bool	cohen_sutherland_clip(t_screen screen, t_point *a, t_point *b);
void	init_fdf(t_data *data, char *map_in);
int		open_map(t_data *data, int fd);
int		convert_hexa(const char *str);
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
void	calc_matrix(t_point *p, float m[9]);
void	iso_matrix(t_point *p, const t_camera camera);
void	draw_map(t_data *data);
void	draw_circle(t_data *data, int xc, int yc, int r, int color);

void	init_param(t_data *data);
void	put_pixel(t_data *data, int x, int y, const int color);
void	safe_put_pixel(t_data *data, int x, int y, const int color);
ssize_t	get_proc_time(void);
void	draw_string(const t_data data, t_pos pos, char *str, int color);
void	draw_center_string(const t_data data, t_pos pos, char *str, int color);
void	draw_int(const t_data data, const int x, const int y, int value);
void	draw_string_int(const t_data data, t_pos pos, char *str, int value);
float	to_rad(float degrees);
float	to_degrees(float radian);
int		check_input(t_data *data);
void	isometric_projection(t_point *point, const t_camera camera);
bool	*get_key(t_data *data, int value);
bool	can_put_pixel(const t_data *data, const t_point point_a);
bool	can_put_pos(const t_data *data, const t_pos pos);
bool	can_put_rectangle(const t_data *data, t_pos pos_a, t_pos pos_b);
void	normalize_camera(t_camera *camera);
int		get_fps(void);
void	draw_full_rectangle(t_data *data, t_pos pos_a, t_pos pos_b, int color);
void	draw_edge_rectangle(t_data *data, t_pos pos_a, t_pos pos_b, int color);
void	clear_window(t_data *data);
void	set_camera_math(t_camera *camera);
int		get_delta_time(void);
void	auto_rotate(t_data *data);
void	draw_data(t_data *data);
void	ft_sleep(int ms);
void	hook_handler(t_data *data);
int		loop(t_data *data);
void	calc_view(t_vector *map, t_data *data);
t_point	*get_point(t_data *data, size_t x, size_t y);
int		init_graphic(t_data *data);
char	*get_name(char *str);
void	free_map(t_vector *map);
char	**get_map_list();
void	normalize_value(int *value, int	min, int max);
void	normalize_float_value(float *value, float max);

void	draw(t_data *data, t_point point_a, t_point point_b);
void	bresenham_h(t_data *data, t_point point_a, t_point point_b, int color);
void	bresenham_v(t_data *data, t_point point_a, t_point point_b, int color);
void	bresenham_degrade_h(t_data *data, t_point point_a, t_point point_b);
void	bresenham_degrade_v(t_data *data, t_point point_a, t_point point_b);
void	xiaolin_wu(t_data *data, t_point point_a, t_point point_b, int color);

void	draw_gui(t_data *data);
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
void	set_limit_fps(t_data *data);
void	set_degrade(t_data *data);
void	set_antialiasing(t_data *data);

void	exit_fdf(t_data *data);

#endif