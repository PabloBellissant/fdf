NAME = fdf

SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = lib/libft
LIBFTINC = $(LIBFTDIR)/include
MLX_DIR = lib/minilibx-linux

SRCS =	$(addprefix $(SRCDIR)/, \
		open_map.c \
		convert_hexa.c \
		init_key.c \
		init_graphic.c \
		event_handler/key_press_event.c \
        event_handler/get_key.c \
		event_handler/key_is_pressed.c \
		event_handler/key_release_event.c \
		event_handler/mouse_is_pressed.c \
		event_handler/mouse_press_event.c \
        event_handler/mouse_release_event.c \
        event_handler/mouse_wheel.c \
        get_map_list.c \
        get_simple_name.c \
        check_input/check_input.c \
        check_input/action/change_height.c \
        check_input/action/change_height_selected.c \
        check_input/action/change_map.c \
        check_input/action/change_param_lag_comp.c \
        check_input/action/select_zone.c \
        check_input/action/simple_clic.c \
        calc_degrade.c \
        calc_matrix.c \
        iso_matrix.c \
        init_param.c \
        put_pixel.c \
        get_proc_time.c \
        draw_gui.c \
        draw_text/draw_string.c \
        draw_text/draw_int.c \
        draw_text/draw_string_int.c \
        to_rad.c \
        to_degrees.c \
        draw_circle.c \
        draw_line/draw.c \
        draw_line/bresenham/bresenham.c \
        draw_line/bresenham/bresenham_degrade.c \
        draw_line/xiaolin_wu.c \
        draw_line/cohen_sutherland_clip/cohen_sutherland_clip.c \
        draw_line/cohen_sutherland_clip/compute_clip.c \
        draw_line/cohen_sutherland_clip/utils_clip.c \
        can_put_pixel.c \
        normalize_camera.c \
        get_fps.c \
        draw_rectangle.c \
        clear_window.c \
        set_camera_math.c \
        auto_rotate.c \
        get_delta_time.c \
        draw_data.c \
        ft_sleep.c \
        hook_handler.c \
        loop.c \
        calc_view.c \
        get_point.c \
        draw_map.c \
        normalize_value.c \
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
       	init_fdf.c \
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
