NAME = fdf

SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = lib/libft
LIBFTINC = $(LIBFTDIR)/include

SRCS =	$(addprefix $(SRCDIR)/, \
		main.c)

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

LIBFT = $(LIBFTDIR)/libft.a

CFLAGS = -Wall -Wextra -Werror -I $(INCDIR) -I $(LIBFTINC)
DEBUGFLAGS = -pg
DEPFLAGS = -MMD -MP
MAKEFLAGS = --no-print-directory


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean 
	make all

bonus: all

debug: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $@ $^

-include $(DEPS)

.PHONY: all clean fclean re bonus FORCE
