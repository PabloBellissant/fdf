NAME = fdf

SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = lib/libft
LIBFTINC = $(LIBFTDIR)/include
MLX_DIR = lib/minilibx-linux

SRCS =	$(addprefix $(SRCDIR)/, \
		init/map_loading/open_map.c \
		init/map_loading/convert_hexa.c \
        init/map_loading/get_map_list.c \
        init/map_loading/get_name.c \
		init/init_key.c \
       	init/init_fdf.c \
        init/init_param.c \
		init/init_graphic.c \
        math/calc_matrix.c \
        math/calc_view.c \
        math/normalize_camera.c \
        math/normalize_value.c \
        math/set_camera_math.c \
        math/to_rad.c \
        math/to_degrees.c \
        math/iso_matrix.c \
        time/get_cpu_time.c \
        time/ft_sleep.c \
        time/get_fps.c \
        time/get_delta_time.c \
        draw/put_pixel.c \
        draw/calc_degrade.c \
        draw/draw_gui.c \
        draw/draw_data.c \
        draw/draw_text/draw_string.c \
        draw/draw_text/draw_int.c \
        draw/draw_text/draw_string_int.c \
        draw/draw_line/draw.c \
        draw/draw_line/bresenham/bresenham.c \
        draw/draw_line/bresenham/bresenham_degrade.c \
        draw/draw_line/xiaolin_wu.c \
        draw/draw_line/cohen_sutherland_clip/cohen_sutherland_clip.c \
        draw/draw_line/cohen_sutherland_clip/compute_clip.c \
        draw/draw_line/cohen_sutherland_clip/utils_clip.c \
        draw/draw_shapes/draw_circle.c \
        draw/draw_shapes/draw_rectangle.c \
        draw/draw_map.c \
        draw/can_put_pixel.c \
        draw/clear_window.c \
        loop/check_input/check_input.c \
        loop/check_input/action/change_height.c \
        loop/check_input/action/change_height_selected.c \
        loop/check_input/action/change_map.c \
        loop/check_input/action/change_param_lag_comp.c \
        loop/check_input/action/select_zone.c \
        loop/check_input/action/simple_clic.c \
		loop/event_handler/key_press_event.c \
        loop/event_handler/get_key.c \
		loop/event_handler/key_is_pressed.c \
		loop/event_handler/key_release_event.c \
		loop/event_handler/mouse_is_pressed.c \
		loop/event_handler/mouse_press_event.c \
        loop/event_handler/mouse_release_event.c \
        loop/event_handler/mouse_wheel.c \
        loop/auto_rotate.c \
        loop/hook_handler.c \
        loop/loop.c \
        loop/get_point.c \
        button/set_button.c \
        button/draw_button.c \
        button/click_button.c \
        button/action/set_draw_line.c \
        button/action/same_level_draw.c \
        button/action/diff_level_draw.c \
        button/action/set_clipping.c \
        button/action/fun_lsd.c \
       	button/action/set_motion_blur.c \
       	button/action/set_full_clear.c \
       	button/action/set_auto_rotate.c \
       	button/action/set_limit_fps.c \
       	button/action/set_degrade.c \
       	button/action/set_antialiasing.c \
       	exit_fdf.c \
		main.c)

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

CFLAGS = -Wall -Wextra -Werror -I $(INCDIR) -I $(LIBFTINC) -I $(MLX_DIR) -g
LDFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz
DEPFLAGS = -MMD -MP
MAKEFLAGS = --no-print-directory


all: $(NAME)

fast: CFLAGS += -Ofast
fast: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFTDIR)

$(MLX): FORCE
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean
	make all

refast: fclean
	make fast

bonus: all

debug: $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -pg -o $@ $^ $(LDFLAGS)

-include $(DEPS)

.PHONY: all clean fclean re bonus FORCE
