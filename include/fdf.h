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
# include "define.h"
# include "struct.h"

void		init_fdf(t_data *data, char *map_in);
int			open_map(t_data *data, int fd);
int			convert_hexa(const char *str);
void		init_key(t_data *data);
bool		key_is_pressed(const KEY_TYPE key, t_data data);
int			key_press(const KEY_TYPE keycode, t_data *data);
int			key_release(const KEY_TYPE keycode, t_data *data);
bool		mouse_is_pressed(const KEY_TYPE button, const t_data data);
int			mouse_press(const int button, int x, int y, t_data *data);
int			mouse_release(const int button, int x, int y, t_data *data);
void		mouse_wheel(const int button, t_data *data);
t_color		calc_degrade(const t_color color_a, const t_color color_b,
				double mod, t_data data);
void		calc_matrix(t_point *p, float m[16]);
void		iso_matrix(t_point *p, const t_camera camera);
void		perspective_matrix(t_point *point, t_data *data);
void		draw_map(t_data *data);
void		draw_circle(t_data *data, t_pos pos);

void		init_param(t_data *data);
void		put_pixel(t_data *data, int x, int y, const int color);
void		safe_put_pixel(t_data *data, int x, int y, const int color);
ssize_t		get_proc_time(void);
void		draw_string(const t_data data, t_pos pos, char *str, int color);
void		draw_center_string(const t_data data, t_pos pos, char *str,
				int color);
void		draw_int(const t_data data, const int x, const int y, int value);
void		draw_string_int(const t_data data, t_pos pos, char *str, int value);
float		to_rad(float degrees);
float		to_degrees(float radian);
void		isometric_projection(t_point *point, const t_camera camera);
bool		*get_key(t_data *data, int value);
bool		can_put_pixel(const t_data *data, const t_point point_a);
bool		can_put_pos(const t_data *data, const t_pos pos);
bool		can_put_rectangle(const t_data *data, t_pos pos_a, t_pos pos_b);
void		normalize_camera(t_camera *camera);
int			get_fps(void);
void		draw_full_rectangle(t_data *data, t_pos pos_a, t_pos pos_b,
				int color);
void		draw_edge_rectangle(t_data *data, t_pos pos_a, t_pos pos_b,
				int color);
void		clear_window(t_data *data);
void		set_camera_math(t_camera *camera);
int			get_delta_time(void);
void		auto_rotate(t_data *data);
void		draw_data(t_data *data);
void		ft_sleep(int ms);
void		hook_handler(t_data *data);
int			loop(t_data *data);
void		calc_view(t_vector *map, t_data *data);
t_point		*get_point(t_data *data, size_t x, size_t y);
int			init_graphic(t_data *data);
char		*get_name(char *str);
void		free_map(t_vector *map);
char		**get_map_list(void);
void		normalize_value(int *value, int min, int max);
void		normalize_float_value(float *value, float max);

/**
 * @brief This function get the mouse position, then dispatch input in
 * differents functions.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
int			check_input(t_data *data);

/**
 * @brief Change the height of the map, by multipling the z_multiple by
 * 1.1, or 0.9 to reduce height.
 * if one or more points are selected, only change the height of it, by
 * increasing / decrease their z value.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		change_height(t_data *data);

/**
 * @brief change the height of the selected points, by increasing / decreasing
 * their z value.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		change_height_selected(t_data *data);

/**
 * @brief Change the state of the option 'draw' to False if the number of
 * points are above 50000, or set it to True if the number of points are
 * less than 50000.
 * This function is only used to reduce lag in big map load.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		change_param_lag_comp(t_data *data);

/**
 * @brief Change the current map, by loading the next map in the map_list
 * struct.
 * @param data A pointer to the struct 'S_DATA'.
 * @return 0 if map load was a success, 1 if the current map is not in
 * the map_list, -1 if open / close failed.
 * @author Bellissant Pablo
 */
int			change_map(t_data *data);

/**
 * @brief compute the selection zone of the mouse.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		select_zone(t_data *data);

/**
 * @brief This function redispatches inputs to different functions,
 * depending on the click (left click, middle click of right click).
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		simple_clic(t_data *data);

/**
 * @brief Draw a line on a screen, by calling differents algorithm,
 * from the parameters used.
 * Only draw a point if param draw_line is set to false.
 * @param data A pointer to the struct 'S_DATA'.
 * @param point_a The point to draw line from.
 * @param point_b The end destination of the line.
 * @author Bellissant Pablo
 */
void		draw(t_data *data, t_point point_a, t_point point_b);

/**
 * @brief This is the bresenham algorithm to draw line in horizontal.
 * @param data A pointer to the struct 'S_DATA'.
 * @param point_a The point to draw line from.
 * @param point_b The end destination of the line.
 * @param color The color of the line.
 * @author Bellissant Pablo
 */
void		bresenham_h(t_data *data, t_point point_a, t_point point_b,
				int color);

/**
 * @brief This is the bresenham algorithm to draw line in vertical.
 * @param data A pointer to the struct 'S_DATA'.
 * @param point_a The point to draw line from.
 * @param point_b The end destination of the line.
 * @param color The color of the line.
 * @author Bellissant Pablo
 */
void		bresenham_v(t_data *data, t_point point_a, t_point point_b,
				int color);

/**
 * @brief This is the bresenham algorithm to draw line in horizontal.
 * This function self compute the degrade.
 * @param data A pointer to the struct 'S_DATA'.
 * @param point_a The point to draw line from. (get the starting color from it).
 * @param point_b The end destination of the line. (get the end color from it).
 * @author Bellissant Pablo
 */
void		bresenham_degrade_h(t_data *data, t_point point_a, t_point point_b);

/**
 * @brief This is the bresenham algorithm to draw line in vertical.
 * This function self compute the degrade.
 * @param data A pointer to the struct 'S_DATA'.
 * @param point_a The point to draw line from. (get the starting color from it).
 * @param point_b The end destination of the line. (get the end color from it).
 * @author Bellissant Pablo
 */
void		bresenham_degrade_v(t_data *data, t_point point_a, t_point point_b);

/**
 * @brief Draws an anti-aliased line using Xiaolin Wu's algorithm.
 * This function renders a smooth line between two points by calculating
 * pixel intensities based on their coverage.
 *
 * @param data A pointer to the data structure containing pixel information.
 * @param a The starting point of the line.
 * @param b The ending point of the line.
 * @param color The color of the line.
 * @author Bellissant Pablo
 */
void		xiaolin_wu(t_data *data, t_point point_a, t_point point_b,
				int color);

void		draw_gui(t_data *data);

/**
 * @brief Initialise all the buttons.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		set_button(t_data *data);

/**
 * @brief Draw all buttons on the screen.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		draw_buttons(t_data *data);

/**
 * @brief Check if the click was on a button or not, If the click was on a
 * button, the function return the button that was click.
 * @param data A pointer to the struct 'S_DATA'.
 * @param pos the position of the click.
 * @return The button that was clicked, NULL if not a button.
 * @author Bellissant Pablo
 */
t_button	*click_button(t_data data, t_pos pos);

/**
 * @brief Change the state of the option 'draw line' to True / False
 * Also change the state / color of the 'draw line' button.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		set_draw_line(t_data *data);

/**
 * @brief Change the state of the option 'same level' to True / False
 * Also change the state / color of the 'same level' button.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		same_level_draw(t_data *data);

/**
 * @brief Change the state of the option 'diff level' to True / False
 * Also change the state / color of the 'diff level' button.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		diff_level_draw(t_data *data);

/**
 * @brief Change the state of the option 'set clipping' to True / False
 * Also change the state / color of the 'set clipping' button.
 * if the clipping is set to False, antialiasing is also set to False.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		set_clipping(t_data *data);

/**
 * @brief Change the state of the option 'fun lsd' to True / False
 * Also change the state / color of the 'fun lsd' button.
 * set also the opposite button / param to false if 'fun lsd' set to True.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		fun_lsd(t_data *data);

/**
 * @brief Change the state of the option 'motion_blur' to True / False
 * Also change the state / color of the 'motion_blur' button.
 * set also the opposite button / param to false if 'motion_blur' set to True.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		set_motion_blur(t_data *data);

/**
 * @brief Change the state of the option 'full clear' to True / False
 * Also change the state / color of the 'full clear' button.
 * set also the opposite button / param to false if 'full clear' set to True.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		set_full_clear(t_data *data);

/**
 * @brief Change the state of the option 'auto rotate' to True / False
 * Also change the state / color of the 'auto rotate' button.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		set_auto_rotate(t_data *data);

/**
 * @brief Change the state of the option 'linit fps' to True / False
 * Also change the state / color of the 'linit fps' button.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		set_limit_fps(t_data *data);

/**
 * @brief Change the state of the option 'degrade' to True / False
 * Also change the state / color of the 'degrade' button.
 * if the degrade is set to True, set 'antialiasing' option to false.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		set_degrade(t_data *data);

/**
 * @brief Change the state of the option 'set antialiasing' to True / False
 * Also change the state / color of the 'set antialiasing' button.
 * if antialiasing is set to true, it set false to 'degrade' option, and
 * set true to 'clipping' option.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		set_antialiasing(t_data *data);

/**
 * @brief This function recreate the line clip of cohen sutherland algorithm.
 * It is used to know if a line is out of the screen.
 * If only one point is out of the screen, the function recalculate the point
 * to be on the screen, keeping his angle.
 * @param data A pointer to the struct 'S_DATA'.
 * @param point_a The point to draw line from.
 * @param point_b The end destination of the line.
 * @return False if both points are out of the screen, True if the line can be
 * drawn.
 * @author Bellissant Pablo, Danny Cohen and Ivan Sutherland.
 */
bool		cohen_sutherland_clip(t_data *data, t_point *a, t_point *b);

/**
 * @brief Computes the intersection of a line with a vertical or horizontal
 * boundary.
 * This function calculates the new x-coordinate of the intersection point
 * when a line segment crosses a given boundary.
 *
 * @param val The boundary value to intersect with.
 * @param pos1 The first point of the line segment.
 * @param pos2 The second point of the line segment.
 * @return The computed intersection coordinate.
 * @author Bellissant Pablo
 */
double		compute_intersection(double val, t_pos_double pos1,
				t_pos_double pos2);

/**
 * @brief Computes the new coordinates of a point when clipped against the
 * screen boundaries.
 * This function adjusts the coordinates of a point that is outside the
 * screen by computing its intersection with the nearest boundary.
 *
 * @param out The outcode determining which boundary the point is outside of.
 * @param a A pointer to the first point of the line segment.
 * @param b A pointer to the second point of the line segment.
 * @param data A pointer to the structure containing screen dimensions and
 * clipping data.
 * @author Bellissant Pablo
 */
void		compute_new_coordinates(int out, t_point *a, t_point *b,
				t_data *data);

/**
 * @brief Computes the outcode for a given point relative to the screen
 * boundaries.
 * This function determines whether a point is inside or outside the screen
 * and assigns an outcode representing its position relative to the
 * screen edges.
 * @param screen The screen dimensions.
 * @param pos The position of the point to be evaluated.
 * @return The computed outcode indicating which boundary the point
 * is outside of.
 * @author Bellissant Pablo
 */
int			compute_out(t_screen screen, t_pos_double pos);

/**
 * @brief Updates a point's coordinates and computes its outcode.
 * This function sets the view coordinates of a point and determines its
 * position relative to the screen boundaries.
 *
 * @param screen The screen dimensions.
 * @param p A pointer to the point to update.
 * @param pos The new position to assign to the point.
 * @param out A pointer to store the computed outcode.
 * @author Bellissant Pablo
 */
void		update_point(t_screen screen, t_point *p, t_pos_double pos,
				int *out);

/**
 * @brief Computes the intersection point of a line segment with a given
 * boundary.
 * This function determines the coordinate of the intersection between a line
 * segment and a horizontal or vertical boundary.
 *
 * @param limit The boundary value to intersect with.
 * @param a A pointer to the first point of the line segment.
 * @param b A pointer to the second point of the line segment.
 * @param swap Determines whether to swap x and y coordinates for vertical
 * intersections.
 * @return The computed intersection coordinate.
 * @author Bellissant Pablo
 */
double		get_intersection(int limit, t_point *a, t_point *b, int swap);

void		exit_fdf(t_data *data);

#endif