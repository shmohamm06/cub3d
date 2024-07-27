RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

INC_DIR = include

SRCS = ft_strlcpy.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
       ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memmove.c \
       ft_memcmp.c ft_memcpy.c ft_memset.c ft_strdup.c ft_strchr.c ft_strcmp.c \
       ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
       ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
       ft_striteri.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
       ft_putnbr_fd.c get_next_line.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
       ft_lstadd_back.c ft_lstdelone.c ft_lstlast.c ft_lstiter.c ft_lstclear.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)"
	@echo "Created: $(words $(OBJS)) file(s) for libft"
	@echo "Created: $(NAME)"

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)"
	@echo "Removed: $(words $(OBJS)) file(s) for libft"
	@echo "Removed: $(NAME)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re