#
#
RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

NAME=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

%.o: %.c
	@cc -c -w $(CFLAGS) $?
%.o: %.m
	@cc -c -w $(CFLAGS) $?

all: $(NAME)

$(NAME):	$(OBJ)
	@ar -r -c $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ""
	@echo "$(GREEN)"
	@echo "Created: $(words $(OBJ)) object file(s) for MLX"
	@echo "Created: $(NAME)$(RESET)"

clean:
	@rm -f $(NAME) $(OBJ) *~
	@rm -f mlx_app
	@echo ""
	@echo "$(YELLOW)"
	@echo "Removed: $(words $(OBJ)) object file(s) from MLX"
	@echo "Removed: $(NAME)$(RESET)"

re: clean all
