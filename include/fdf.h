/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:58:11 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/20 09:34:00 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stdbool.h>
# include "libft.h"
# include "define.h"
# include "struct.h"

/**
 * @brief Main program, initialize all values, and load entered map,
 * Then call loop.
 * @param argc The arg count.
 * @param argv The args.
 * @author Bellissant Pablo
 */
int			main(int argc, char **argv);

/**
 * @brief Initialize some variables, to properly start fdf.
 * @param data A pointer to the struct 'S_DATA'.
 * @param map_in The argv[1] of the main, containing input file.
 * @author Bellissant Pablo
 */
void		init_fdf(t_data *data, char *map_in);

/**
 * @brief Read a map from a fd, and create a vector of vector containing points,
 * according to the map read.
 * @param data A pointer to the struct 'S_DATA'.
 * @param fd The file descriptor.
 * @author Bellissant Pablo
 */
int			open_map(t_data *data, int fd);

/**
 * @brief Convert a value in hexa (base 16), to an integer (base 10).
 * @param str The string to convert.
 * @return The result in integer.
 * @author Bellissant Pablo
 */
int			convert_hexa(const char *str);

/**
 * @brief Initializes all the key_map to false.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		init_key(t_data *data);

/**
 * @brief Checks if a specific key is pressed.
 *
 * @param key The key to check.
 * @param data A pointer to the struct 'S_DATA'.
 * @return True if the key is pressed, false otherwise.
 * @author Bellissant Pablo
 */
bool		key_is_pressed(const KEY_TYPE key, t_data data);

/**
 * @brief Handles a key press event by updating the key state.
 * @param keycode The keycode of the pressed key.
 * @param data A pointer to the struct 'S_DATA'.
 * @return 0 if the key is found and updated, -1 if the key is not in the map.
 * @author Bellissant Pablo
 */
int			key_press(const KEY_TYPE keycode, t_data *data);

/**
 * @brief Handles a key release event by updating the key state.
 * @param keycode The keycode of the released key.
 * @param data A pointer to the struct 'S_DATA'.
 * @return 0 if the key is found and updated, -1 if the key is not in the map.
 * @author Bellissant Pablo
 */
int			key_release(const KEY_TYPE keycode, t_data *data);

/**
 * @brief Checks if mouse is clicked.
 *
 * @param button The button to check.
 * @param data A pointer to the struct 'S_DATA'.
 * @return True if the button is pressed, false otherwise.
 * @author Bellissant Pablo
 */
bool		mouse_is_pressed(const KEY_TYPE button, const t_data data);

/**
 * @brief Handles a mouse press event.
 * @param button The mouse button that was pressed.
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param data A pointer to the struct 'S_DATA'.
 * @return 0 if the button is handled, -1 if the button is not recognized.
 * @author Bellissant Pablo
 */
int			mouse_press(const int button, int x, int y, t_data *data);

/**
 * @brief Handles a mouse release event.
 *
 * @param button The mouse button that was pressed.
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param data A pointer to the struct 'S_DATA'.
 * @return 0 if the button is handled, -1 if the button is not recognized.
 * @author Bellissant Pablo
 */
int			mouse_release(const int button, int x, int y, t_data *data);

/**
 * @brief Handles mouse wheel events to zoom in or out.
 * @param button The button associated with the wheel scroll
 * (4 for scroll up, 5 for scroll down).
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		mouse_wheel(const int button, t_data *data);

/**
 * @brief Compute a degrade beetween two colors, with a mod.
 * @param color_a The first color.
 * @param color_b The second color.
 * @param mod A value beetween 0 and 1, used as a mod.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
t_color		calc_degrade(const t_color color_a, const t_color color_b,
				double mod, t_data data);

/**
 * @brief Compute a point to a 4*4 matrix.
 * @param p The point to calculate.
 * @param m the 4*4 matrix
 * @note The function will compute value p.x_view, p.y_view, p.z_view and p.w.
 * and put the result in the same variables.
 * @author Bellissant Pablo
 */
void		calc_matrix(t_point *p, float m[16]);

/**
 * @brief Compute the isometric view.
 * @param p the point to compute.
 * @param camera the camera data.
 * @author Bellissant Pablo
 */
void		iso_matrix(t_point *p, const t_camera camera);

/**
 * @brief Draw the map, points or line depending of params.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		draw_map(t_data *data);

/**
 * @brief Draws a circle on the screen, using bresenham.
 * @param data A pointer to the struct 'S_DATA'.
 * @param pos The position of the circle's center.
 * @author Bellissant Pablo
 */
void		draw_circle(t_data *data, t_pos pos);

/**
 * @brief Initializes the starting params to true or false.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		init_param(t_data *data);

/**
 * @brief Puts a pixel on the screen at the specified coordinates
 * with the given color.
 * @warning The pixel must exist in the entered range, if you are not
 * certain that the pixel can be draw here, use safe_put_pixel() instead.
 * @param data A pointer to the struct 'S_DATA'.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color of the pixel.
 * @author Bellissant Pablo
 */
void		put_pixel(t_data *data, int x, int y, const int color);

/**
 * @brief Puts a pixel on the screen at the specified coordinates
 * with the given color.
 * @note This function is safe because if the pixel is out of range,
 * the function simply return.
 * @param data A pointer to the struct 'S_DATA'.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color of the pixel.
 * @author Bellissant Pablo
 */
void		safe_put_pixel(t_data *data, int x, int y, const int color);

/**
 * @brief Get the actual CPU timestamp, by reading '/proc/self/sched'.
 * @return The actual cpu time.
 * @author Bellissant Pablo
 */
ssize_t		get_cpu_time(void);

/**
 * @brief Draws a centered string at the specified position with the
 * given color.
 * @param data A pointer to the struct 'S_DATA'.
 * @param pos The position where the string should be drawn.
 * @param str The string to be drawn.
 * @param color The color of the string.
 * @author Bellissant Pablo
 */
void		draw_center_string(const t_data data, t_pos pos, char *str,
				int color);

/**
 * @brief Draw an array on the string.
 * @param data A pointer to the struct 'S_DATA'.
 * @param pos the position x and y.
 * @param str The string to draw.
 * @param color The color of the string.
 * @author Bellissant Pablo
 */
void		draw_string(const t_data data, t_pos pos, char *str, int color);

/**
 * @brief Draw an integer on the screen.
 * @param data A pointer to the struct 'S_DATA'.
 * @param x the position x.
 * @param y the position y.
 * @param value the value to draw.
 * @author Bellissant Pablo
 */
void		draw_int(const t_data data, const int x, const int y, int value);

/**
 * @brief Draw an array on the string, and a value next to it.
 * @note 'str: value'
 * @param data A pointer to the struct 'S_DATA'.
 * @param pos the position x and y.
 * @param str The string to draw.
 * @param value The value to draw.
 * @author Bellissant Pablo
 */
void		draw_string_int(const t_data data, t_pos pos, char *str, int value);

/**
 * @brief convert a degree to a radian
 * @param degrees The degree to convert.
 * @return the radiant, in float.
 * @author Bellissant Pablo
 */
float		to_rad(float degrees);

/**
 * @brief convert a radian to a degrees.
 * @param degrees The degree to convert.
 * @return the radiant, in float.
 * @author Bellissant Pablo
 */
float		to_degrees(float radian);

/**
 * @brief Returns a pointer to the state of a specific key.
 * @param data A pointer to the struct 'S_DATA'.
 * @param value The key index.
 * @return A pointer to the key state.
 * @author Bellissant Pablo
 */
bool		*get_key(t_data *data, int value);

/**
 * @brief Function to know if a point can be draw at certain coordinate.
 * @param data A pointer to the struct 'S_DATA'.
 * @param point the point to know.
 * @return True if the point can be drawn, False if not.
 * @author Bellissant Pablo
 */
bool		can_put_pixel(const t_data *data, const t_point point);

/**
 * @brief Function to know if a pos can be draw at certain coordinate.
 * @param data A pointer to the struct 'S_DATA'.
 * @param pos the coordinate x and y.
 * @return True if the point can be drawn, False if not.
 * @author Bellissant Pablo
 */
bool		can_put_pos(const t_data *data, const t_pos pos);

/**
 * @brief Function to know if a rectangle can be drawn at given coordinates.
 * @param data A pointer to the struct 'S_DATA'.
 * @param pos_a The start of the rectangle.
 * @param pos_b The end of the rectangle.
 * @return True if the point can be drawn, False if not.
 * @author Bellissant Pablo
 */
bool		can_put_rectangle(const t_data *data, t_pos pos_a, t_pos pos_b);

/**
 * @brief Normalize camera, from 0 to pi * 2
 * @param camera a pointer to the camera data.
 * @author Bellissant Pablo
 */
void		normalize_camera(t_camera *camera);

/**
 * @brief Get the number of frame per seconds.
 * @return the fps.
 * @author Bellissant Pablo
 */
int			get_fps(void);

/**
 * @brief Draw a filled rectangle.
 * @param data A pointer to the struct 'S_DATA'.
 * @param pos_a The first corner.
 * @param pos_b The second corner.
 * @param color The color of the rectangle.
 * @author Bellissant Pablo
 */
void		draw_fill_rectangle(t_data *data, t_pos pos_a, t_pos pos_b,
				int color);

/**
 * @brief Draw a clear rectangle (only edges).
 * @param data A pointer to the struct 'S_DATA'.
 * @param pos_a The first corner.
 * @param pos_b The second corner.
 * @param color The color of the rectangle.
 * @author Bellissant Pablo
 */
void		draw_edge_rectangle(t_data *data, t_pos pos_a, t_pos pos_b,
				int color);

/**
 * @brief Function to clear windows, following differents parameters.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		clear_window(t_data *data);

/**
 * @brief Sets the trigonometric values for the camera's pitch and yaw angles.
 *
 * @param camera A pointer to the struct 't_camera'.
 * @author Bellissant Pablo
 */
void		set_camera_math(t_camera *camera);

/**
 * @brief Get the time passed since the last frame.
 * @return the delta time.
 * @author Bellissant Pablo
 */
size_t		get_delta_time(void);

/**
 * @brief Update the camera pitch and camera yaw if auto_rotate is active.
 * This function create a rotating effect.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		auto_rotate(t_data *data);

/**
 * @brief Draws some stuff on the string, like general info, screen info,
 * camera info or map info.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		draw_data(t_data *data);

/**
 * @brief Pauses the program for a specified amount of time in milliseconds.
 * @param ms The duration to sleep in milliseconds.
 * @author Bellissant Pablo
 */
void		ft_sleep(size_t ms);

/**
 * @brief Sets up event handlers for various window events in mlx.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		hook_handler(t_data *data);

/**
 * @brief The loop of the program, call at each frames. Main thread.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
int			loop(t_data *data);

/**
 * @brief Compute the view of each point from a map line, by calling iso_matrix.
 * @param map The line of the map.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		calc_view(t_vector *map, t_data *data);

/**
 * @brief Get the point in a map, by x and y.
 * @param data A pointer to the struct 'S_DATA'.
 * @param x The pos x.
 * @param y The pos y.
 * @return a pointer to the point, NULL if point does not exist.
 * @author Bellissant Pablo
 */
t_point		*get_point(t_data *data, size_t x, size_t y);

/**
 * @brief Initializes the graphics of the mlx.
 * @param data A pointer to the struct 'S_DATA'.
 * @return 0 if initialization is successful, -1 if an error occurs.
 * @author Bellissant Pablo
 */
int			init_graphic(t_data *data);

/**
 * @brief Remove the path, and the extension of a file name.
 * @param str The file name
 * @return The file name without extension and path.
 * @author Bellissant Pablo
 */
char		*get_name(char *str);

/**
 * @brief Free memory from map.
 * @param map A pointer to the map.
 * @author Bellissant Pablo
 */
void		free_map(t_vector *map);

/**
 * @brief Open the file maps/maps_name and fill an array of chars for each
 * line of maps/maps_name, representing the maps to load.
 * @return an array of chars, containing all maps name.
 * @author Bellissant Pablo
 */
char		**get_map_list(void);

/**
 * @brief Normalizes a value to be within a specified range.
 *
 * @param value A pointer to the value to normalize.
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @author Bellissant Pablo
 */
void		normalize_value(int *value, int min, int max);

/**
 * @brief Normalizes a float value to be within a specified range.
 * @note The 'min' is 0.
 * @param value A pointer to the value to normalize.
 * @param max The maximum value of the range.
 * @author Bellissant Pablo
 */
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
 * @param data A pointer to the struct 'S_DATA'.
 * @param a The starting point of the line.
 * @param b The ending point of the line.
 * @param color The color of the line.
 * @author Bellissant Pablo
 */
void		xiaolin_wu(t_data *data, t_point point_a, t_point point_b,
				int color);

/**
 * @brief Draw the GUI, all buttons, and stuff on the screen.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
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
 * @brief Change the state of the option 'limit fps' to True / False
 * Also change the state / color of the 'limit fps' button.
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

/**
 * @brief Cleans up resources and free all memory allocated.
 * @param data A pointer to the struct 'S_DATA'.
 * @author Bellissant Pablo
 */
void		exit_fdf(t_data *data);

#endif