RESET       = \033[0m
GREEN       = \033[32m
YELLOW      = \033[33m

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
FRAMEWORKS = -framework OpenGL -framework AppKit
LIB_DIR = libft
MLX_DIR = mlx

SRCS = cub3d.c utils.c utils2.c parse_map.c map.c init.c \
       map_utils.c colour.c check_map.c check_map2.c check_map3.c \
       check_files.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(LIB_DIR)/libft.a $(MLX_DIR)/libmlx.a $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/libft.a -o $(NAME) $(FRAMEWORKS) -L$(MLX_DIR) -lmlx
	@echo "$(GREEN)"
	@echo "Created: $(words $(OBJS)) object file(s) for Cub3d"
	@echo "Created: $(NAME)"

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

$(LIB_DIR)/libft.a:
	@$(MAKE) -C $(LIB_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(MLX_DIR)/libmlx.a
	@rm -f $(LIB_DIR)/libft.a
	@echo "$(YELLOW)"
	@echo "Removed: $(words $(OBJS)) object file(s) for Cub3d"
	@echo "Removed: $(NAME)"

re: fclean all

.PHONY: all clean fclean re