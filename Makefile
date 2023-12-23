NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = fractol.c helpers.c hooks.c generator.c init.c color.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o fractol $(OBJS) $(LIBFT) -lm -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c fractol.h $(LIBFT_DIR)/libft.h $(LIBFT)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

