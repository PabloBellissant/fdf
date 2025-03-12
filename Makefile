NAME = fdf

SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = lib/libft
LIBFTINC = $(LIBFTDIR)/include
MLX_DIR = lib/minilibx-linux

SRCS =	$(addprefix $(SRCDIR)/, \
		open_map.c \
		init_key.c \
		event_handler/key_is_pressed.c \
		event_handler/key_press_event.c \
		event_handler/key_release_event.c \
		event_handler/mouse_is_pressed.c \
		event_handler/mouse_press_event.c \
        event_handler/mouse_release_event.c \
        event_handler/mouse_wheel.c \
        calc_degrade.c \
        calc_matrix.c \
        rotation_matrix.c \
        init_param.c \
        put_pixel.c \
        get_proc_time.c \
        draw_text/draw_string.c \
        draw_text/draw_int.c \
        to_rad.c \
        to_degrees.c \
        draw_line.c \
        can_put_pixel.c \
        normalize_camera.c \
        get_fps.c \
        draw_rectangle.c \
        clear_window.c \
        set_camera_math.c \
        auto_rotate.c \
        get_delta_time.c \
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

fast: CFLAGS += -O3
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
